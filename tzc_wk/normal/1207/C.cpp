#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define int long long
int n,a,b,dp[200005][2];
bool x[200005];
string s;
inline void solve(){
	cin>>n>>a>>b>>s;
	memset(x,0,sizeof(x));
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			x[i-1]=x[i]=1;
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=b;
	for(int i=1;i<=n;i++){
		if(x[i]){
			dp[i][1]=min(dp[i-1][1]+b*2+a,dp[i-1][0]+b*2+a*2);
		}
		else{
			dp[i][0]=min(dp[i-1][0]+b+a,dp[i-1][1]+b+a*2);
			dp[i][1]=min(dp[i-1][1]+b*2+a,dp[i-1][0]+b*2+a*2);
		}
//		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<dp[n][0]<<endl;
}
signed main(){
	int T;cin>>T;
	while(T--)	solve();
	return 0;
}