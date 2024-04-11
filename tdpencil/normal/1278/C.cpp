#include <bits/stdc++.h>

#define ar array
#define ll long long

using namespace std;
const int mxN=2e5;
int a[mxN];
int b[mxN];
// some prefix must be equal to some suffix
//

set<pair<int, int>> seen;

int ch(int val) {
	auto it=seen.lower_bound({val,0});
	if(it==seen.end()||(*it).first!=val)
		return -1;
	else
		return (*it).second;
		
}
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		seen.clear();
		for(int i = n-1;~i;i--)	
			cin>>a[i], a[i]=(a[i]%2?1:-1);
		for(int i =0; i < n; i++)
			cin >> b[i], b[i]=(b[i]%2?1:-1);
		// now some a[i]+b[i] == 0

		int cur=0;
		for(int i =0 ; i < n; i++)
			cur+=a[i];
		seen.insert({cur,0});
		for(int i =0;i<n;i++)
			cur-=a[i],seen.insert({cur,i+1});
		int ans=1e9;	
		int left=0;
		for(int i =0;i<n;i++)
			left+=b[i];
		int v=ch(-left);
		if(v!=-1)
			ans=min(ans,v);
		for(int i=0;i<n;i++) {
			left-=b[i];
			int l=ch(-left);
			if(l!=-1)
				ans=min(ans,l+i+1);
		}
		cout << ans << '\n';

		
	}
}