#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct fenwick{
	using T = int;
    vector<T> a; int n, p=1<<30; T s;
    fenwick(int N) : a(++(n=N)) {}
    fenwick& operator[](int i){ p = i; return *this; }
    void operator+=(T v){
        for(++p; p<n; p+=p&-p) a[p] += v; }
    void operator=(T v){ operator+=(v - (*this)(p, p)); }
    T operator()(int i){
        for(s=0, ++i; i; i^=i&-i) s += a[i];
        return s; }
    T operator()(int l, int r){ return (*this)(r) - (*this)(l-1); }
    int lower_bound(T v){
        for(s=0, p=1<<21; p/=2; ) if(s+p<=n && a[s+p]<v) v -= a[s+=p];
        return s;
    }
} f(1<<20);

using T = array<int, 3>;

void add(int l, int r, int v) {
	f[l] += v;
	f[r+1] += -v;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;

	int c[n+1] = {};
	set<T> s;
	s.insert({1, n, 1});

	while(q--) {
		string t;
		cin >> t;
		if(t[0] == 'C') {
			int l, r, v;
			cin >> l >> r >> v;

			T x = {l+1};
			auto a = --s.lower_bound(x);
			if((*a)[0] != l) {
				auto [lv, rv, cv] = *a;


				if(rv > r) {
					add(l, r, c[cv]);
					s.erase(a);
					s.insert({lv, l-1, cv});
					s.insert({r+1, rv, cv});
					a = end(s);
				} else {
					add(l, rv, c[cv]);
					s.erase(a);
					s.insert({lv, l-1, cv});
					a = s.lower_bound(x);
				}
			}
			while(a != end(s) && (*a)[1] <= r) {
				auto [lv, rv, cv] = *a;
				add(lv, rv, c[cv]);

				a = s.erase(a);
			}
			if(a != end(s) && (*a)[0] <= r) {
				auto [lv, rv, cv] = *a;

				add(lv, r, c[cv]);
				s.erase(a);
				s.insert({r+1, rv, cv});
			}
			add(l, r, -c[v]);
			s.insert({l, r, v});

		} else if(t[0] == 'A') {
			int l, v; cin >> l >> v;
			c[l] += v;
		} else {
			int l; cin >> l;
			T x = {l+1};
			auto ff = s.lower_bound(x);
			--ff;

			cout << f(1, l) + c[(*ff)[2]] << '\n';
		}
	}
}