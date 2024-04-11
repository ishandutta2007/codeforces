#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> Vec;
typedef vector<Vec> Mat;
const int MAXN = 200;
const int MAXL = 200;
const ll INF = (1ll<<60);
struct node{
	int nxt[26], fail;
	ll key;
}a[MAXN*MAXL + 5];
int ncnt, root;
void init() {
	root = ncnt = 0;
	for(int i=0;i<26;i++)
		a[root].nxt[i] = root;
	a[root].fail = root, a[root].key = 0;
}
int newnode() {
	ncnt++;
	for(int i=0;i<26;i++)
		a[ncnt].nxt[i] = -1;
	a[ncnt].fail = -1, a[ncnt].key = 0;
	return ncnt;
}
void Insert(char *S, ll val) {
	int lenS = strlen(S), nw = root;
	for(int i=0;i<lenS;i++) {
		int p = S[i] - 'a';
		if( a[nw].nxt[p] == -1 || a[nw].nxt[p] == root )
			a[nw].nxt[p] = newnode();
		nw = a[nw].nxt[p];
	}
	a[nw].key += val;
}
void ACBuild() {
	queue<int>que;
	for(int i=0;i<26;i++) {
		if( a[root].nxt[i] == root ) continue;
		a[a[root].nxt[i]].fail = root;
		que.push(a[root].nxt[i]);
	}
	while( !que.empty() ) {
		int f = que.front(); que.pop();
		for(int i=0;i<26;i++) {
			if( a[f].nxt[i] == -1 ) continue;
			int p = a[f].nxt[i], q = a[f].fail;
			while( a[q].nxt[i] == -1 )
				q = a[q].fail;
			a[p].fail = a[q].nxt[i], a[p].key += a[a[q].nxt[i]].key;
			que.push(p);
		}
	}
}
Mat operator *(Mat a, Mat b) {
	int n = a.size(), m = b.size(), p = b[0].size();
	Mat c(n, Vec(p, -INF));
	for(int i=0;i<n;i++)
		for(int j=0;j<p;j++)
			for(int k=0;k<m;k++)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
	return c;
}
Mat pow(Mat A, ll k) {
	Mat ret = A; k--;
	while( k ) {
		if( k & 1 ) ret = ret * A;
		A = A * A;
		k >>= 1;
	}
	return ret;
}
ll A[MAXN + 5];
char S[MAXL + 5];
int main() {
	init();
	int n;ll l;
	scanf("%d%lld", &n, &l);
	for(int i=1;i<=n;i++)
		scanf("%lld", &A[i]);
	for(int i=1;i<=n;i++) {
		scanf("%s", S);
		Insert(S, A[i]);
	}
	ACBuild();
	Mat B(ncnt+1, Vec(ncnt+1, -INF)), dp(ncnt+1, Vec(1, -INF));
	dp[0][0] = 0;
	for(int i=0;i<=ncnt;i++)
		for(int j=0;j<26;j++) {
			int p = i;
			while( a[p].nxt[j] == -1 )
				p = a[p].fail;
			B[a[p].nxt[j]][i] = a[a[p].nxt[j]].key;
		}
	dp = pow(B, l)*dp;
/*	for(int i=0;i<=ncnt;i++)
		printf("%d : %lld\n", i, dp[i][0]);*/
	ll ans = -INF;
	for(int i=0;i<=ncnt;i++)
		ans = max(ans, dp[i][0]);
	printf("%I64d\n", ans);
}