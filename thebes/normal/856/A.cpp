#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#endif
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		//size of df doesn't exceed 1e4
		set<int> df;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				df.insert(abs(a[i]-a[j]));
			}
		}
		vector<bool> ok(1000005,true);
		vector<int> ans;
		for(int i=1;i<=1000000&&(int)ans.size()!=n;i++){
			if(!ok[i])continue;
			//this is done at most 1e2 times
			ans.push_back(i);
			for(int d:df)if(i+d<=1000000)ok[i+d]=false;
		}
		if((int)ans.size()!=n)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=0;i<(int)ans.size();i++)cout<<ans[i]<<" \n"[i==(int)a.size()-1];
		}
	}
}