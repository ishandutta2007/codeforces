#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], c[mxN], ans;
bool vis[mxN];
vector<int> occ[mxN], cc;

void test(int x) {
	for(int i=0; i<x; ++i) {
		int c2=c[cc[i]];
		bool ok=1;
		for(int j=i; j<cc.size()&&ok; j+=x) {
			if(c[cc[j]]^c2) {
				ok=0;
			}
		}
		if(ok) {
			ans=min(x, ans);
			return;
		}
	}
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i], --p[i];
	for(int i=0; i<n; ++i)
		cin >> c[i], --c[i];
	memset(vis, 0, n);
	ans=1e9;
	for(int i=0; i<n; ++i) {
		if(vis[i])
			continue;
		int l=0;
		int s=i;
		while(!vis[s]) {
			vis[s]=1;
			//if(occ[c[s]].empty())
				//cc.push_back(c[s]);
			//occ[c[s]].push_back(l++);
			cc.push_back(s);
			s=p[s];
			++l;
		}
		/*
		for(int ci : cc) {
			int g=occ[ci][0]+l-occ[ci].back();
			for(int i=0; i+1<occ[ci].size(); ++i)
				g=__gcd(g, occ[ci][i+1]-occ[ci][i]);
			ans=min(l/g, ans);
			occ[ci].clear();
		}
		*/
		for(int j=1; j*j<=l; ++j) {
			if(l%j)
				continue;
			test(j);
			test(l/j);
		}
		cc.clear();
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}