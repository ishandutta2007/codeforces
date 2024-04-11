#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int k, n, a[2001], b[2000];
unordered_map<int, int> mp;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> k >> n;
	for(int i=0; i<k; ++i) {
		cin >> a[i+1];
		a[i+1]+=a[i];
	}
	for(int i=0; i<n; ++i) {
		cin >> b[i];
		set<int> s;
		for(int j=1; j<=k; ++j)
// 			++mp[b[i]-a[j]];
            s.insert(b[i]-a[j]);
        for(int c : s)
            ++mp[c];
	}
	int ans=0;
	for(pair<int, int> p : mp)
		ans+=p.second>=n;//, cout << p.first << endl;
	cout << ans;
}