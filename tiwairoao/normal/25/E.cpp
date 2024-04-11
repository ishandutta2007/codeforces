#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const ull MOD = ull(1E9) + 123;
const int MAXN = 300000;
const int INF = (1<<30);
char s[3][MAXN + 5];
int len[3], a[3];
ull h[3][MAXN + 5], pw[MAXN + 5];
void CalHash() {
	pw[0] = 1;
	for(int i=1;i<=MAXN;i++)
		pw[i] = pw[i-1] * 131 % MOD;
	for(int i=0;i<3;i++) {
		h[i][1] = s[i][1];
		for(int j=1;j<=len[i];j++)
			h[i][j] = (h[i][j-1] * 131 + s[i][j]) % MOD;
	}
}
inline ull GetHash(int l, int r, int t) {
	return (h[t][r]+(MOD-h[t][l-1]*pw[r-l+1]%MOD)) % MOD;
}
int solve() {
	bool flag1 = false, flag2 = false;
	for(int i=1;i<=len[a[0]];i++) {
		if( i+len[a[2]]-1 <= len[a[0]] ) {
			if( GetHash(1, len[a[2]], a[2]) == GetHash(i, i+len[a[2]]-1, a[0]) )
				flag1 = true;
		}
		else break;
	}
	for(int i=1;i<=len[a[1]];i++) {
		if( i+len[a[2]]-1 <= len[a[1]] ) {
			if( GetHash(1, len[a[2]], a[2]) == GetHash(i, i+len[a[2]]-1, a[1]) )
				flag1 = true;
		}
		else break;
	}
	for(int i=1;i<=len[a[0]];i++) {
		if( i+len[a[1]]-1 <= len[a[0]] ) {
			if( GetHash(1, len[a[1]], a[1]) == GetHash(i, i+len[a[1]]-1, a[0]) )
				flag2 = true;
		}
		else break;
	}
	int lim = min(len[a[0]], len[a[1]]), ans1, ans2;
	for(int i=lim;i>=0;i--) {
		if( GetHash(len[a[0]]-i+1, len[a[0]], a[0]) == GetHash(1, i, a[1]) ) {
			ans1 = i;
			break;
		}
	}
	lim = min(len[a[1]], len[a[2]]);
	for(int i=lim;i>=0;i--) {
		if( GetHash(len[a[1]]-i+1, len[a[1]], a[1]) == GetHash(1, i, a[2]) ) {
			ans2 = i;
			break;
		}
	}
	int ans = len[a[0]] + len[a[1]] + len[a[2]] - ans1 - ans2;
	if( flag1 )
		ans = min(ans, len[a[0]] + len[a[1]] - ans1);
	if( flag1 && flag2 )
		ans = min(ans, len[a[0]]);
	return ans;
}
int main() {
	for(int i=0;i<3;i++) {
		scanf("%s", s[i]+1);
		len[i] = strlen(s[i]+1);
		a[i] = i;
	}
	CalHash();
	int ans = INF;
	do {
		ans = min(ans, solve());
	}while( next_permutation(a, a+3) );
	printf("%d\n", ans);
}