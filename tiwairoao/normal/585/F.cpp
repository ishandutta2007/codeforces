#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXD = 50;
const int MAXN = 1000;
const int MOD = int(1E9) + 7;
struct node{
	node *nxt[10], *fail;
	bool flag;
}au[MAXD*MAXN+5], *root, *acnt;
char s[MAXN + 5], x[MAXD + 5], y[MAXD + 5];
ll pw10[MAXD + 5];
void init() {
	pw10[0] = 1;
	for(int i=1;i<=MAXD;i++)
		pw10[i] = pw10[i-1] * 10 % MOD;
	root = acnt = &au[0];
	for(int i=0;i<10;i++)
		root->nxt[i] = root;
	root->fail = root, root->flag = false;
}
node *ACnewnode() {
	acnt++;
	for(int i=0;i<10;i++)
		acnt->nxt[i] = NULL;
	acnt->fail = NULL, acnt->flag = false;
	return acnt;
}
void ACinsert(char *S, int lenS) {
	node *nw = root;
	for(int i=0;i<lenS;i++) {
		int p = S[i] - '0'; 
		if( nw->nxt[p] == root || nw->nxt[p] == NULL )
			nw->nxt[p] = ACnewnode();
		nw = nw->nxt[p];
	}
	nw->flag = true;
}
void ACbuild() {
	queue<node*>que;
	for(int i=0;i<10;i++) {
		if( root->nxt[i] != root ) {
			root->nxt[i]->fail = root;
			que.push(root->nxt[i]);
		}
	}
	while( !que.empty() ) {
		node *f = que.front(); que.pop();
		f->flag |= f->fail->flag;
		for(int i=0;i<10;i++) {
			if( f->nxt[i] == NULL )
				f->nxt[i] = f->fail->nxt[i];
			else {
				f->nxt[i]->fail = f->fail->nxt[i];
				que.push(f->nxt[i]);
			}
		}
	}
}
ll dp[MAXN*MAXD + 5][MAXD + 5];
void ACsolve(int d) {
	int tsz = acnt - au;
	for(int i=0;i<=tsz;i++)
		if( !au[i].flag ) dp[i][0] = 1;
	for(int i=1;i<=d;i++) {
		for(int j=0;j<=tsz;j++) {
			if( au[j].flag ) continue;
			for(int k=0;k<10;k++) {
				int p = au[j].nxt[k] - au;
				dp[j][i] = (dp[j][i] + dp[p][i-1]) % MOD;
			}
		}
	}
}
int main() {
	init();
	scanf("%s%s%s", s, x, y);
	int d = strlen(x), lenS = strlen(s);
	for(int i=0;i<=lenS-d/2;i++)
		ACinsert(s+i, d/2);
	ACbuild(); ACsolve(d);
	ll ans1 = 0, ans2 = 0;
	node *nw = root;
	for(int i=1;i<x[0]-'0';i++)
		ans1 = (ans1 + (pw10[d-1] - dp[nw->nxt[i]-au][d-1]) % MOD + MOD) % MOD;
	nw = nw->nxt[x[0]-'0'];
	for(int i=1;i<d;i++) {
		if( nw->flag ) {
			for(int j=i;j<d;j++)
				ans1 = (ans1 + pw10[d-1-j]*(x[j] - '0')) % MOD;
			break;
		}
		for(int j=0;j<x[i]-'0';j++) 
			ans1 = (ans1 + (pw10[d-1-i] - dp[nw->nxt[j]-au][d-1-i]) % MOD + MOD) % MOD;
		nw = nw->nxt[x[i]-'0'];
	}
	nw = root;
	for(int i=1;i<y[0]-'0';i++)
		ans2 = (ans2 + (pw10[d-1] - dp[nw->nxt[i]-au][d-1]) % MOD + MOD) % MOD;
	nw = nw->nxt[y[0]-'0'];
	for(int i=1;i<d;i++) {
		if( nw->flag ) {
			for(int j=i;j<d;j++)
				ans2 = (ans2 + pw10[d-1-j]*(y[j] - '0')) % MOD;
			break;
		}
		for(int j=0;j<y[i]-'0';j++) 
			ans2 = (ans2 + (pw10[d-1-i] - dp[nw->nxt[j]-au][d-1-i]) % MOD + MOD) % MOD;
		nw = nw->nxt[y[i]-'0'];
	}
	if( nw->flag ) ans2++;
	printf("%I64d\n", ((ans2 - ans1) % MOD + MOD) % MOD);
}