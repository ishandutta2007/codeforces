#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

inline int solve(deque<int> &d, int m) {
	return max(d[m] - d.front(), d.back() - d[m]);
}

int main() {
	int i, n, k; char c;
	scanf("%d %d", &n, &k);
	deque<int> d;
	int all = INT_MAX;
	for(i = 0; i < n; i++) {
		scanf(" %c", &c);
		if(c == '1') continue;
		d.pb(i);
		if(d.size() > k + 1) d.pop_front();
		if(d.size() < k + 1) continue;
		int l = 0, r = k;
		while(r - l > 4) {
			int m = (l + r) / 2;
			if(solve(d, m) > solve(d, m + 1)) l = m;
			else r = m;
		}
		int mn = INT_MAX;
		for(; l <= r; l++)
			mn = min(mn, solve(d, l));
		all = min(all, mn);
	}
	printf("%d\n", all);
}