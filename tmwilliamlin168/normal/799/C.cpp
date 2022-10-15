#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=1e5;
int n, c[2], ans;
vector<ar<int, 2>> v[2];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> c[0] >> c[1];
	for(int i=0; i<n; ++i) {
		int b, p;
		char e;
		cin >> b >> p >> e;
		v[e-'C'].push_back({b, p});
	}
	for(int i : {0, 1}) {
		sort(v[i].begin(), v[i].end());
		while(v[i].size()&&v[i].back()[1]>c[i])
			v[i].pop_back();
	}
	if(v[0].size()&&v[1].size())
		ans=max(ans, (v[0].size()?v[0].back()[0]:0)+(v[1].size()?v[1].back()[0]:0));
	for(int k : {0, 1}) {
		vector<ar<int, 2>> nv;
		for(ar<int, 2> a : v[k]) {
			if(nv.size()&&a[0]==nv.back()[0]) {
				if(nv.back()[1]+a[1]<=c[k])
					ans=max(ans, nv.back()[0]+a[0]);
				continue;
			}
			while(nv.size()&&a[1]<=nv.back()[1]) {
				if(nv.back()[1]+a[1]<=c[k])
					ans=max(ans, nv.back()[0]+a[0]);
				nv.pop_back();
			}
			nv.push_back(a);
		}
		while(nv.size()&&nv.back()[1]+nv[0][1]>c[k])
			nv.pop_back();
		for(int i=(int)nv.size()-1, j=0; ~i; --i) {
			while(j+1<i&&nv[j+1][1]+nv[i][1]<=c[k])
				++j;
			if(j>=i)
				break;
			ans=max(ans, nv[j][0]+nv[i][0]);
		}
	}
	cout << ans;
}