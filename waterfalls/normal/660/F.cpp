#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

struct Frac {
	ll first, second;
	bool operator<(Frac o) {
		if (second==0) return (first>0);
		if (o.second==0) return (o.first<0);
		if (first/second!=o.first/o.second) return first/second<o.first/o.second;
		return (Frac) { o.second,o.first-(first/second)*o.second } < (Frac){ second,first-(first/second)*second };
	}
};
typedef pair<ll,ll> Line;

Frac inter(Line a, Line b) {
	return { b.B-a.B, a.A-b.A };
}

set<Line> hull;
set<Line>::iterator on;

bool check(set<Line>::iterator it) {
	if (next(it)==hull.end()) return false;
	if (it==hull.begin()) {
		if (it->A==next(it)->A) {
			if (on==it) ++on;
			hull.erase(it);
			return true;
		}
		return false;
	}
	auto a = prev(it), b = next(it);
	if (inter(*a,*b)<inter(*a,*it)) {
		if (on==it) --on;
		hull.erase(it);
		return true;
	}
	return false;
}

void insert(Line l) {
	auto it = hull.insert(l).A;
	if (on==next(it)) --on;
	while (it!=hull.begin() && check(prev(it)));
	while (next(it)!=hull.end() && check(next(it)));
	check(it);
}

ll eval(Line l, int i) { return i*l.A+l.B; }

ll query(int i) {
	while (next(on)!=hull.end()) {
		auto a = next(on);
		if (eval(*a,i)>eval(*on,i)) on++;
		else break;
	}
	return eval(*on,i);
}

int n;
ll a[200013];
ll sums[200013], isums[200013];

ll solve() {
	hull.clear();
	on = hull.begin();
	for (int i=1;i<=n;i++) sums[i] = sums[i-1]+a[i];
	for (int i=1;i<=n;i++) isums[i] = isums[i-1]+i*a[i];
	ll res = 0;
	for (int i=n;i>=1;i--) {
		ll m = sums[i];
		ll b = isums[i]+sums[i];
		insert(MP(m,b));
		res = max(res,query(-i)-isums[i-1]+(i-1)*sums[i-1]);
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll ans = solve();
	printf("%lld\n",ans);

    return 0;
}