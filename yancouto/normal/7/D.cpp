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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
char str[5000009];
int sta[5000009];


int main() {
	int i;
	scanf(" %s", str);
	int tot = 0;
	ull left = 0;
	ull right = 0;
	ull t = 1;
	sta[0] = 0;
	for(i = 0; str[i]; i++) {
		left = mod(t * ((int)((unsigned char) str[i])) + left);
		right = mod(right * 257 + ((int)((unsigned char) str[i])));
		t = mod(t * 257);
		if(left == right) sta[i + 1] = sta[(i + 1) / 2] + 1;
		else sta[i + 1] = 0;
		tot += sta[i + 1];
	}
	printf("%d\n", tot);
	return 0;
}