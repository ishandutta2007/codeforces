#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, k;
int seen[2][512][512];
bool mrk[502];
int c[502];
//void solve(int i, int cur, int sub) {
//	if(cur > k) return;
//	if(i == n) {
//		if(cur == k) mrk[sub] = true;
//		return;
//	}
//	if(seen[i][cur][sub]) return;
//	seen[i][cur][sub] = true;
//	solve(i + 1, cur, sub);
//	solve(i + 1, cur + c[i], sub);
//	solve(i + 1, cur + c[i], sub + c[i]);
//}

int main() {
	int i, j, cur, sub;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &c[i]);
	seen[0][0][0] = 1;
	for(i = 0; i < n; i++) {
		for(cur = 0; cur <= k; cur++)
			for(sub = 0; sub <= k; sub++) {
				if(seen[i&1][cur][sub] < i + 1) continue;
				seen[!(i&1)][cur][sub] = i + 2;
				if(cur + c[i] > k) continue;
				seen[!(i&1)][cur + c[i]][sub] = i + 2;
				seen[!(i&1)][cur + c[i]][sub + c[i]] = i + 2;
			}
	}
	for(sub = 0; sub <= k; sub++)
		if(seen[n&1][k][sub] == n+1)
			mrk[sub] = true;
	printf("%d\n", accumulate(mrk, mrk + 502, 0));
	for(i = 0; i < 502; i++)
		if(mrk[i])
			printf("%d ", i);
	putchar('\n');
}