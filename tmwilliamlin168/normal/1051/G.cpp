#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5, mxSTS=19*mxN+1;
int n, ai, bi;
ll ans;
map<int, int> mp;

struct segtree {
	int sts=1, lc[mxSTS], rc[mxSTS], c1[mxSTS];
	ll c2[mxSTS];
	void bld(int &i, int l2=0, int r2=n-1) {
		i=sts++;
		c1[i]=1;
		c2[i]=bi+1;
		if(l2==r2)
			return;
		int m2=(l2+r2)/2;
		if(bi<=m2)
			bld(lc[i], l2, m2);
		else
			bld(rc[i], m2+1, r2);
	}
	void mrg(int &i1, int i2, int l2=0, int r2=n-1, int d1=0, int d2=0) {
		if(!i1) {
			swap(i1, i2);
			swap(d1, d2);
		}
		if(!i2) {
			ans+=c2[i1]*d2;
			return;
		}
		int m2=(l2+r2)/2;
		mrg(lc[i1], lc[i2], l2, m2, d1+c1[rc[i1]], d2+c1[rc[i2]]);
		mrg(rc[i1], rc[i2], m2+1, r2, d1, d2);
		c1[i1]=c1[lc[i1]]+c1[rc[i1]];
		c2[i1]=c2[lc[i1]]+c2[rc[i1]];
	}
} st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	mp[-1]=0;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> ai >> bi, --ai, --bi;
		auto it2=--mp.upper_bound(ai), it1=it2++;
		if(it1->first+st.c1[it1->second]<ai)
			it1=mp.insert({ai, 0}).first;
		int c=0;
		st.bld(c);
		ans-=(ai-it1->first)*st.c2[c];
		st.mrg(it1->second, c);
		if(it2!=mp.end()&&it1->first+st.c1[it1->second]>=it2->first) {
			ans-=(it2->first-it1->first)*st.c2[it2->second];
			st.mrg(it1->second, it2->second);
			mp.erase(it2);
		}
		cout << ans << "\n";
	}
}