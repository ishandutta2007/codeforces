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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int main() {
	int i, w, h, n, x; char op;
	scanf("%d %d %d", &w, &h, &n);
	set<int> lr, ud;
	multiset<int> ww, hh;
	lr.insert(0); lr.insert(w);
	ud.insert(0); ud.insert(h);
	ww.insert(w); hh.insert(h);
	for(i = 0; i < n; i++) {
		scanf(" %c %d", &op, &x);
		if(op == 'H') {
			auto it = ud.lower_bound(x);
			auto it2 = it--;
			hh.erase(hh.find(*it2 - *it));
			hh.insert(*it2 - x); hh.insert(x - *it);
			ud.insert(x);
		} else {
			auto it = lr.lower_bound(x);
			auto it2 = it--;
			ww.erase(ww.find(*it2 - *it));
			ww.insert(*it2 - x); ww.insert(x - *it);
			lr.insert(x);
		}
		printf("%I64d\n", ll(*ww.rbegin()) * ll(*hh.rbegin()));
	}
}