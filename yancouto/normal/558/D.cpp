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
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int h, q;

ull most_left(ull x) {
	while(x < (1ull << h))
		x <<= 1;
	return x >> 1;
}

ull most_right(ull x) {
	while(x < (1ull << h))
		x = (x << 1) + 1;
	return x >> 1;
}

struct block {
	int on;
	ull x;
	block() {}
	block(int a, ull b) : on(a), x(b) {}
	bool operator < (const block &o) const { return x < o.x; }
};

int main() {
	int i, ni, ans; ull le, ri;
	scanf("%d %d", &h, &q);
	map<ull, int> evs;
	for(i = 0; i < q; i++) {
		scanf("%d %I64u %I64u %d", &ni, &le, &ri, &ans);
		ull ml = (1ull << (ni - 1)), mr = (1ull << ni) - 1;
		if(ans) {
			evs[most_left(ml)]++;
			evs[most_left(le)]--;
			evs[most_right(ri) + 1]++;
			evs[most_right(mr) + 1]--;
		}
		else {
			evs[most_left(le)]++;
			evs[most_right(ri) + 1]--;
		}
	}
	evs[most_right(1) + 1] = 0;
	ull one;
	ull many = 0, last = most_left(1);
	int bl = 0;
	for(auto &it : evs) {
		if(!bl) many += it.fst - last;
		if(!bl && it.fst > last) one = last;
		bl += it.snd;
		last = it.fst;
	}
	if(many == 0) puts("Game cheated!");
	else if(many > 1) puts("Data not sufficient!");
	else printf("%I64u\n", one);
	return 0;
}