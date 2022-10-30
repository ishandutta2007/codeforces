#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,v,k;
int x[3013], y[3013];
vector<int> byx;
vector<int> viola[3013];
list<int>::iterator loc[3013], far[3013];
list<int> locs;
ll cur;

bool comp(int a, int b) { return x[a]<x[b]; }

ll process(int l) {
	locs.clear();
	cur = 0;
	ll res = 0;
	for (int i=0;i<=k;i++) locs.push_back(0);
	for (int i: byx) {
		if (y[i]>=l) {
			locs.push_back(i);
			loc[i] = --locs.end();
		}
	}
	for (int i=0;i<=k;i++) locs.push_back(v+1);
	for (int i: locs) {
		if (i==0 || i==v+1) continue;
		far[i] = loc[i];
		for (int j=0;j<k-1;j++) ++far[i];
		cur+=(x[i]-x[*prev(loc[i])])*(n+1-x[*far[i]]);
	}
	far[0] = locs.begin();
	far[v+1] = --locs.end();
	for (int r=m;r>=l;r--) {
		res+=cur;
		for (int i: viola[r]) {
			cur-=(x[i]-x[*prev(loc[i])])*(x[*far[*next(loc[i])]]-x[*far[i]]);
			auto it = loc[i];
			for (int j=0;j<k-1;j++) {
				--it;
				if (*it==0) break;
				cur-=(x[*it]-x[*prev(it)])*(x[*next(far[*it])]-x[*far[*it]]);
				++far[*it];
			}
			locs.erase(loc[i]);
		}
	}
	return res;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&v,&k);
	for (int i=1;i<=v;i++) {
		scanf("%d%d",&x[i],&y[i]);
		viola[y[i]].push_back(i);
		byx.push_back(i);
	}
	sort(byx.begin(),byx.end(),comp);
	x[0] = 0;
	x[v+1] = n+1;
	ll ans = 0;
	for (int l=1;l<=m;l++) ans+=process(l);
	printf("%lld\n",ans);

	return 0;
}