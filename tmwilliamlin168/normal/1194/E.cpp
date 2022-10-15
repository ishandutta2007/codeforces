#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e3, mxC=mxN*2;
int n, ft[mxC+2];
vector<ar<int, 3>> h, v;

void upd(int i, int x) {
	for(++i; i<=mxC+1; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0, x1, y1, x2, y2; i<n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1+=mxN;
		y1+=mxN;
		x2+=mxN;
		y2+=mxN;
		if(x1>x2)
			swap(x1, x2);
		if(y1>y2)
			swap(y1, y2);
		if(x1==x2)
			v.push_back({x1, y1, y2});
		else
			h.push_back({y1, x1, x2});
	}
	sort(h.begin(), h.end());
	sort(v.begin(), v.end(), [](const ar<int, 3> &a, const ar<int, 3> &b) {
		return a[2]<b[2];
	});
	ll ans=0;
	for(int i=0; i<h.size(); ++i) {
		for(int j=0; j<v.size(); ++j)
			if(v[j][1]<=h[i][0])
				upd(v[j][0], 1);
		for(int j1=i+1, j2=0; j1<h.size()||j2<v.size(); ) {
			if(j2<v.size()&&(j1>=h.size()||v[j2][2]<h[j1][0])) {
				if(v[j2][1]<=h[i][0])
					upd(v[j2][0], -1);
				++j2;
			} else {
				int l=max(h[i][1], h[j1][1]), r=min(h[i][2], h[j1][2]);
				ll k=l<=r?qry(r+1)-qry(l):0;
				ans+=k*(k-1)/2;
				++j1;
			}
		}
	}
	cout << ans;
}