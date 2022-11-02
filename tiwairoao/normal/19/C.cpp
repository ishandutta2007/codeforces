#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
const int BASE = 1313131;
const ll MOD = ll(1E9) + 123;
int a[MAXN + 5], b[MAXN + 5], c[MAXN + 5], n;
int nxt[MAXN + 5], nw[MAXN + 5];
int key[MAXN + 5], ST[MAXN + 5][20];
void GetST() {
	for(int i=1;i<=n;i++)
		ST[i][0] = i;
	for(int j=1;j<20;j++) {
		int l = 1<<(j-1);
		for(int i=1;i+l<=n;i++) {
			if( key[ST[i][j-1]] >= key[ST[i+l][j-1]] )
				ST[i][j] = ST[i][j-1];
			else ST[i][j] = ST[i+l][j-1];
		}
	}
}
int RMQ(int le, int ri) {
	int k = log2(ri-le+1), l = (1<<k);
	if( key[ST[le][k]] >= key[ST[ri-l+1][k]] )
		return ST[le][k];
	else return ST[ri-l+1][k];
}
ll h[MAXN + 5], pw[MAXN + 5];
void CalHash() {
	pw[0] = 1;
	for(int i=1;i<=n;i++) {
		h[i] = (h[i-1] * BASE + a[i]) % MOD;
		pw[i] = (pw[i-1] * BASE) % MOD;
	}
}
ll GetHash(int l, int r) {
	return (h[r] - h[l-1]*pw[r-l+1]%MOD + MOD) % MOD;
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	int bsz = unique(b+1, b+n+1) - b - 1;
	for(int i=1;i<=n;i++)
		a[i] = lower_bound(b+1, b+bsz+1, a[i]) - b;
	CalHash();
	for(int i=n;i>=1;i--) {
		for(int j=nw[a[i]];j;j=nxt[j])
			if( j+j-i-1 <= n && GetHash(i, j-1) == GetHash(j, j+j-i-1) )
				key[i] = j-i;
		nxt[i] = nw[a[i]];
		nw[a[i]] = i;
	}
	GetST();
	int start = 1;
	while( true ) {
		int p = RMQ(start, n);
		if( !key[p] ) break;
		start = p + key[p];
	}
	printf("%d\n", n-start+1);
	for(int i=start;i<=n;i++)
		printf("%d ", b[a[i]]);
	puts("");
}