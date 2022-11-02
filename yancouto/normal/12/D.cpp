#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

struct lady {
	int b, i, r;
	bool operator < (lady o) const {
		if(b == o.b) return pii(i, r) > pii(o.i, o.r);
		else return b > o.b;
	}
	bool gr(lady o) { return b > o.b && i > o.i && r > o.r; }
} a[500009];

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i].b);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i].i);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i].r);
	sort(a, a + n);
	set<pii> s;
	s.insert(pii(-1, -1000000009));
	s.insert(pii(1000000009,  1));
	int tot = 0;
	for(i = 0; i < n;) {
		for(j = i; j < n && a[i].b == a[j].b; j++)
			if(-s.lower_bound(pii(a[j].i, -a[j].r))->y > a[j].r)
				tot++;
		for(; i < j; i++) {
			if(-s.lower_bound(pii(a[i].i, -a[i].r))->y >= a[i].r) continue;
			auto it = s.insert(pii(a[i].i, -a[i].r)).first;
			while(-prev(it)->y <= a[i].r)
				s.erase(prev(it));
		}
	}
	printf("%d\n", tot);
}