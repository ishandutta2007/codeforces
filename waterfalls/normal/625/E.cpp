#include <bits/stdc++.h>
using namespace std;

int n,m;

struct Frog {
	int p,l,i;
	bool operator<(Frog o) const { return p<o.p; }
	int dist(Frog o) const {
		int len = o.p-p;
		if (len<0) len+=m;
		if (i<o.i && len<=l) return 1;
		if (l<=o.l) return m+1;
		if (i<o.i) return (len-l-1)/(l-o.l)+2;
		return (len-1)/(l-o.l)+1;
	}
	void go(int t) {
		int x = (p+1LL*l*t)%m;
		if (x<0) x+=m;
		p = x;
	}
};

struct Time {
	int t;
	Frog f;
	bool operator<(Time o) const {
		if (t!=o.t) return t<o.t;
		return f.i<o.f.i;
	}
};

set<Frog> frogs;
set<Time> neigh;

void inc(set<Frog>::iterator& it) {
	++it;
	if (it==frogs.end()) it = frogs.begin();
}
void dec(set<Frog>::iterator& it) {
	if (it==frogs.begin()) it = frogs.end();
	--it;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int p,l;
		scanf("%d%d",&p,&l);
		frogs.insert({ p-1,l,i });
	}
	for (auto it=frogs.begin();it!=frogs.end();++it) {
		auto p = it;
		inc(p);
		neigh.insert({ it->dist(*p),*it });
	}
	while (true) {
		int t = neigh.begin()->t;
		Frog f = neigh.begin()->f;
		neigh.erase(neigh.begin());
		if (t==m+1) break;
		int eaten = 0;
		auto it = frogs.lower_bound(f);
		if (it==frogs.end() || f.i!=it->i) continue;
		while (true) {
			auto p = it;
			inc(it);
			frogs.erase(p);
			if (!frogs.size()) break;
			if (f.dist(*it)>t) break;
			eaten+=1;
		}
		if (!frogs.size()) {
			frogs.insert(f);
			break;
		}
		dec(it);
		Frog p = *it;
		inc(it);
		neigh.erase(neigh.lower_bound({ p.dist(f),p }));
		f.go(t);
		f.l = max(0,f.l-eaten);
		f.go(-t);
		neigh.insert({ p.dist(f),p });
		neigh.insert({ f.dist(*it),f });
		frogs.insert(f);
	}
	printf("%d\n",frogs.size());
	for (auto f: frogs) printf("%d ",f.i);
	printf("\n");

	return 0;
}