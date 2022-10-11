#include <iostream>
#include <set>
#include <utility>
#include <cstdio>
#include <cassert>

typedef std::pair<int, int> ii;

const int ms = 200200;

int par[ms], size[ms], a[ms], l[ms], r[ms];
int ll[ms], rr[ms];

std::set<ii> groups;

int get_par(int x) {
	if(x == par[x]) {
		return x;
	} else {
		return par[x] = get_par(par[x]);
	}
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b) {
		return;
	}
	groups.erase(ii(-size[a], a));
	groups.erase(ii(-size[b], b));
	if(a > b) {
		std::swap(a, b);
	}
	size[a] += size[b];
	par[b] = a;
	ll[a] = std::min(ll[a], ll[b]);
	rr[a] = std::max(rr[a], rr[b]);
	//assert(ll[a] == a);
	groups.insert(ii(-size[a], a));
}

int main() {
	int n;
	std::cin >> n;
	a[n + 1] = -1;
	a[0] = -2;
	for(int i = 1; i <= n; i++) {
		//std::cin >> a[i];
		scanf("%i", a + i);
		l[i] = i - 1;
		r[i] = i + 1;
		ll[i] = rr[i] = i;
		par[i] = i;
		size[i] = 1;
		groups.insert(ii(-1, i));
		if(a[i] == a[i - 1]) {
			make_union(i, i - 1);
		}
	}
	int ans = 0;
	while(groups.size() > 0) {
		//std::cout << "groups is currently " << groups.size() << "\n";
		int on = groups.begin()->second;
		//std::cout << "got group of " << on << "\n";
		groups.erase(groups.begin());
		int pl = ll[get_par(on)];
		int pr = rr[get_par(on)];
		r[l[pl]] = r[pr];
		l[r[pr]] = l[pl];
		if(a[r[pr]] == a[l[pl]]) {
			make_union(r[pr], l[pl]);
		}
		ans++;
	}
	std::cout << ans << '\n';
}