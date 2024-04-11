#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }
 
// void maxi(int& a, int b) {
	// a = max(a, b);
// }
// void mini(int& a, int b) {
	// a = min(a, b);
// }
 
void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	const int INF = 1e9 + 5;
	long long L = 1, R = INF;
	set<long long> s;
	long long offset = 0;
	int dp = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(i % 2 == 1) {
			int diff = a[i] - a[i-1];
			L += diff;
			R += diff;
			offset += diff;
			// set<int> s2;
			// for(int x : s) {
				// s2.insert(x + diff);
			// }
			// s = s2;
		}
		L = max(L, 1LL);
		R = min(R, a[i] - 1LL);
		// maxi(L, 1LL);
		// mini(R, a[i] - 1LL);
		while(!s.empty() && *s.begin() + offset < 1) {
			s.erase(s.begin());
		}
		while(!s.empty() && *s.rbegin() + offset >= a[i]) {
			s.erase(prev(s.end()));
		}
		if(L <= R || !s.empty()) {
			if(i != 0) {
				dp++;
			}
			if(a[i] % 2 == 0) {
				if((L <= a[i] / 2 && a[i] / 2 <= R) || s.count(a[i] / 2 - offset)) {
					dp++;
					L = R = a[i] / 2;
					s.clear();
				}
				else {
					s.insert(a[i] / 2 - offset);
				}
			}
		}
		else {
			L = 1;
			R = a[i] - 1;
			if(a[i] % 2 == 0) {
				L = R = a[i] / 2;
				dp++;
			}
		}
	}
	debug() << imie(dp);
	printf("%d\n", 2 * n - dp);
}
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}