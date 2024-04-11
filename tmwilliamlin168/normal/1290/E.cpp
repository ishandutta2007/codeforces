#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1.5e5, B=300, mxBC=(mxN-1)/B+1;
int n, a[mxN], bc, mn[mxBC], x[mxN];
long long ans[mxN+1];
bool b[mxN];
vector<int> u[mxBC];
vector<ar<int, 2>> v[mxBC];

void psh(int i) {
	for(int j=i*B; j<min((i+1)*B, n); ++j)
		if(b[j])
			ans[j]+=u[i].size();
	for(int j=0, k=v[i].size(); j<u[i].size()||k; ) {
		if(j<u[i].size()&&(!k||u[i][j]>v[i][k-1][0]))
			ans[u[i][j++]]-=v[i].size()-k;
		else
			ans[x[v[i][--k][1]]]-=j;
	}
	u[i].clear();
	while(v[i].size()&&v[i].back()[0]>mn[i])
		v[i].pop_back();
	for(int j=i*B; j<min((i+1)*B, n); ++j)
		if(b[j]&&x[j]>mn[i])
			v[i].push_back({x[j]=mn[i], j});
	mn[i]=n;
}

void solve() {
	fill(x, x+n, n);
	memset(b, 0, n);
	for(int i=0; i<n; ++i) {
		int d=a[i]/B;
		for(int j=0; j<d; ++j)
			mn[j]=min(a[i], mn[j]);
		for(int j=d+1; j<bc; ++j)
			u[j].push_back(mn[j]);
		psh(d);
		vector<ar<int, 2>> w;
		int k=0;
		for(; k<v[d].size()&&v[d][k][0]<a[i]; ++k)
			w.push_back(v[d][k]);
		for(int j=d*B; j<a[i]; ++j)
			if(b[j]&&x[j]>a[i])
				w.push_back({x[j]=a[i], j});
		for(; k<v[d].size(); ++k)
			if(v[d][k][1]>a[i])
				w.push_back(v[d][k]);
		v[d]=w;
		for(int j=a[i]+1; j<min((d+1)*B, n); ++j) {
			if(b[j]) {
				++ans[j];
				--ans[x[j]];
			}
		}
		v[d].insert(lower_bound(v[d].begin(), v[d].end(), ar<int, 2>{n, a[i]}), {n, a[i]});
		b[a[i]]=1;
	}
	for(int i=0; i<bc; ++i) {
		psh(i);
		v[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	bc=(n-1)/B+1;
	for(int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	solve();
	reverse(a, a+n);
	solve();
	for(int i=0; i<n; ++i) {
		ans[i+1]+=ans[i];
		cout << ans[i]+i+1 << "\n";
	}
}