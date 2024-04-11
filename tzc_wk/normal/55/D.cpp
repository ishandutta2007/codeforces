#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=2520;
int dp[20][2526][80],a[20],cnt,g[2526],idx;
int GCD(int a,int b){return (b==0)?a:GCD(b,a%b);}
int LCM(int a,int b){return (b==0)?a:a/GCD(a,b)*b;}
int dfs(int pos,int sum,int lcm,bool limit){
	if(pos==-1)	return sum%lcm==0;
	if(!limit&&dp[pos][sum][g[lcm]]!=-1)
		return dp[pos][sum][g[lcm]];
	int up=(limit)?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		ans+=dfs(pos-1,(sum*10+i)%MOD,LCM(lcm,i),(limit&&(i==a[pos])));
	}
	if(!limit)	dp[pos][sum][g[lcm]]=ans;
	return ans;
}
int solve(int x){
	cnt=0;
	while(x){
		a[cnt++]=x%10;
		x/=10;
	}
	return dfs(cnt-1,0,1,1);
}
signed main(){
	for(int i=1;i<=MOD;i++)	if(MOD%i==0)	g[i]=++idx;
	memset(dp,-1,sizeof(dp));
	int T;cin>>T;
	while(T--){
		int l,r;cin>>l>>r;cout<<solve(r)-solve(l-1)<<endl;
	}
}