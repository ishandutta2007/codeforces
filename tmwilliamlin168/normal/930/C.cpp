#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, a[mxN+1], a1[mxN+1], a2[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		int l, r;
		cin >> l >> r;
		++a[l-1], --a[r];
	}
	for(int i=1; i<m; ++i)
		a[i]+=a[i-1];
	vector<int> v;
	for(int i=0; i<m; ++i) {
		if(v.empty()||a[i]>=v.back())
			v.push_back(a[i]);
		else
			*upper_bound(v.begin(), v.end(), a[i])=a[i];
		a1[i+1]=v.size();
	}
	v=vector<int>();
	for(int i=m-1; i>=0; --i) {
		if(v.empty()||a[i]>=v.back())
			v.push_back(a[i]);
		else
			*upper_bound(v.begin(), v.end(), a[i])=a[i];
		a2[i]=v.size();
	}
	int ans=0;
	for(int i=0; i<=m; ++i)
		ans=max(a1[i]+a2[i], ans);
	cout << ans;
}