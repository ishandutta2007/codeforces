#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int m;
int c[5];
int a[1123];

int memo[4][1009][1 << 12];
int solve(int i, int j, int bm) {
	if(i == -1) {
		if(j == 0) return c[4] * (bm != 0);
		if(bm >> 8) return solve(3, j - 1, 0) + c[4];
		return solve(3, j - 1, (bm << 4) | a[j - 1]);
	}
	int &r = memo[i][j][bm];
	if(r != -1) return r;
	r = solve(i - 1, j, bm);
	if((bm >> i) & 1) r = min(r, c[1] + solve(i - 1, j, bm ^ (1 << i)));
	if(i <= 2) {
		if(((bm >> i) & 3) || ((bm >> (4 + i)) & 3))
			r = min(r, c[2] + solve(i - 1, j, bm & ~((1 << i) | (1 << (i + 1)) | (1 << (i + 4)) | (1 << (i + 5)))));
	}
	if(i <= 1) {
		if(((bm >> i) & 7) || ((bm >> (4 + i)) & 7) || ((bm >> (8 + i)) & 7)) {
			int neg = ((1 << (i + 3)) - (1 << i));
			neg |= ((1 << (i + 3 + 4)) - (1 << (i + 4)));
			neg |= ((1 << (i + 3 + 8)) - (1 << (i + 8)));
			r = min(r, c[3] + solve(i - 1, j, bm & ~neg));
		}
	}
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &m);
	for(i = 1; i <= 4; i++) scanf("%d", &c[i]);
	for(i = 0; i < 4; i++)
		for(j = 0; j < m; j++) {
			char c;
			scanf(" %c", &c);
			a[j] |= ((c == '*') << i);
		}
	printf("%d\n", solve(3, m - 1, a[m - 1]));
}