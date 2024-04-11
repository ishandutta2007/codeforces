#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], l[mxN], r[mxN];
bool o[mxN];

void solve() {
	cin >> n;
	memset(o, 0, n);
	for(int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		if(!o[a[i]])
			l[a[i]]=i;
		o[a[i]]=1;
		r[a[i]]=i;
	}
	vector<ar<int, 2>> v;
	for(int i=0; i<n; ++i)
		if(o[i])
			v.push_back({l[i], r[i]});//, cout << i << endl;
	int ans=0;
	for(int i=0, j=0; i<v.size(); i=j) {
		for(++j; j<v.size()&&v[j-1][1]<v[j][0]; ++j);
		ans=max(j-i, ans);
	}
	cout << v.size()-ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--) {
		solve();
	}
}