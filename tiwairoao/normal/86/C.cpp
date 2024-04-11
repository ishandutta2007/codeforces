#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXM = 10;
const int MAXS = 10;
const int MAXN = 1000;
const int MOD = 1000000009;
struct node{
	node *nxt[4], *fail;
	int mxl;
}au[MAXM*MAXS + 5], *root, *acnt;
int Fun(char ch) {
	if( ch == 'A' ) return 0;
	else if( ch == 'T' ) return 1;
	else if( ch == 'C' ) return 2;
	else return 3;
}
void ACinit() {
	root = acnt = &au[0];
	for(int i=0;i<4;i++)
		root->nxt[i] = root;
	root->fail = root, root->mxl = 0;
}
node *ACnewnode() {
	acnt++;
	for(int i=0;i<4;i++)
		acnt->nxt[i] = NULL;
	acnt->fail = NULL, acnt->mxl = 0;
	return acnt;
}
void ACinsert(char *S) {
	int lenS = strlen(S); node *nw = root;
	for(int i=0;i<lenS;i++) {
		int p = Fun(S[i]);
		if( nw->nxt[p] == NULL || nw->nxt[p] == root )
			nw->nxt[p] = ACnewnode();
		nw = nw->nxt[p];
	}
	nw->mxl = max(nw->mxl, lenS);
}
void ACbuild() {
	queue<node*>que;
	for(int i=0;i<4;i++)
		if( root->nxt[i] != root ) {
			que.push(root->nxt[i]);
			root->nxt[i]->fail = root;
		}
	while( !que.empty() ) {
		node *f = que.front(); que.pop();
		f->mxl = max(f->mxl, f->fail->mxl);
		for(int i=0;i<4;i++) {
			if( f->nxt[i] == NULL )
				f->nxt[i] = f->fail->nxt[i];
			else {
				f->nxt[i]->fail = f->fail->nxt[i];
				que.push(f->nxt[i]);
			}
		}
	}
}
char s[MAXS + 5];
ll dp[MAXN + 5][MAXS*MAXM + 5][MAXS + 5];
int main() {
	ACinit();
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		scanf("%s", s);
		ACinsert(s);
	}
	ACbuild(); int asiz = acnt - au;
	for(int i=0;i<4;i++)
		if( root->nxt[i]->mxl == 1 )
			dp[1][root->nxt[i] - au][0]++;
		else dp[1][root->nxt[i] - au][1]++;
	for(int i=2;i<=n;i++) {
		for(int j=0;j<=asiz;j++) {
			for(int k=0;k<4;k++) {
				int p = au[j].nxt[k] - au, q = au[p].mxl;
				for(int l=0;l<10;l++) {
					if( q > l ) {
						dp[i][p][0] = (dp[i][p][0] + dp[i-1][j][l]) % MOD;
					}
					else {
						dp[i][p][l+1] = (dp[i][p][l+1] + dp[i-1][j][l]) % MOD;
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<=asiz;i++)
		ans = (ans + dp[n][i][0]) % MOD;
	printf("%I64d\n", ans);
}