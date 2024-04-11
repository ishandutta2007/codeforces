#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n;
vector<int> bs[1003];

int how_many(int a, int b, int i) {
	auto it1 = lower_bound(bs[i].begin(), bs[i].end(), a);
	auto it2 = lower_bound(bs[i].begin(), bs[i].end(), b);
	if(it2 == bs[i].begin()) return 0;
	if(*it1 > b) return 0;
	return it2 - it1;
}

int main() {
	int i, j, k, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &k);
		for(j = 0; j < k; j++) {
			scanf("%d", &x);
			bs[i].pb(x);
		}
		sort(bs[i].begin(), bs[i].end());
	}
	int tot = 0;
	for(i = 0; i < n; i++)
		for(j = 1; j < bs[i].size(); j++) 
			if(how_many(bs[i][j - 1], bs[i][j], (i - 1 + n) % n) !=
				how_many(bs[i][j - 1], bs[i][j], (i + 1) % n))
				tot++;
	printf("%d\n", tot);
	return 0;
}