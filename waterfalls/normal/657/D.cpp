#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Problem {
	ll p,t;
	int ind;
	bool operator<(Problem o) const {
		return t*o.p<o.t*p;
	}
	bool operator==(Problem o) {
		return t*o.p==o.t*p;
	}
};

bool comp(Problem a, Problem b) { return a.p<b.p; }

int n;
ll T;
Problem x[150013];
vector<vector<Problem> > groups;
ll tot[150013];

bool check(double c) {
	double cur = 0;
	for (auto v: groups) {
		for (auto i: v) {
			double l = i.p*(1-1.*c*tot[i.ind]/T);
			if (cur>l) return false;
		}
		for (auto i: v) cur = max(cur,i.p*(1-1.*c*(tot[i.ind-1]+i.t)/T));
	}
	return true;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&x[i].p);
	for (int i=0;i<n;i++) scanf("%lld",&x[i].t);
	sort(x,x+n);
	groups = { {}, { x[0] } };
	for (int i=1;i<n;i++) {
		if (x[i]==groups.back().back()) groups.back().push_back(x[i]);
		else groups.push_back({ x[i] });
	}
	int on = 0;
	for (int i=1;i<groups.size();i++) {
		tot[i] = tot[i-1];
		for (auto j: groups[i]) {
			tot[i]+=j.t;
			x[on++].ind = i;
		}
	}
	T = tot[groups.size()-1];
	groups.clear();
	sort(x,x+n,comp);
	groups = { { x[0] } };
	for (int i=1;i<n;i++) {
		if (x[i].p==groups.back().back().p) groups.back().push_back(x[i]);
		else groups.push_back({ x[i] });
	}
	double low = 0;
	double high = 1;
	for (int i=0;i<39;i++) {
		if (check((low+high)/2)) low = (low+high)/2;
		else high = (low+high)/2;
	}
	printf("%1.9f\n",high);

	return 0;
}