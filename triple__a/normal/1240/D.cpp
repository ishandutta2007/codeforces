#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
const int SHA1=12345678;
const int SHA2=87654321;
const int MOD1=1e9+7;
const int MOD2=998575343;

int q,n;
int a[maxn],st[maxn];
int dp1[maxn],dp2[maxn];
map<pair<int,int>,int>mp;

void add(int u,int v){
	mp[{u,v}]++;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>q;
	while (q--){
		cin>>n;
		mp.clear();
		int t=0;
		mp[{0,0}]++;
		for (int i=1;i<=n;++i){
			cin>>a[i]; 
			if (t&&st[t]==a[i]){
				t--;
			}
			else{
				dp1[t+1]=(1LL*SHA1*dp1[t]+a[i])%MOD1;
				dp2[t+1]=(1LL*SHA2*dp2[t]+a[i])%MOD2;
				st[++t]=a[i];
			}
			add(dp1[t],dp2[t]);
//			cout<<dp[t]<<endl;
		}
		long long ans=0;
		for (auto c:mp){
			ans+=1LL*c.second*(c.second-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}