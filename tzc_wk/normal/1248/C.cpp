#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
const int MOD=1e9+7;
int n,m,ans=0,dp[100005][2][2];
signed main(){
	n=read();m=read();
	dp[1][0][0]=dp[1][1][0]=1;
	for(int i=2;i<=max(n,m);i++){
		dp[i][0][0]=(dp[i-1][1][0]+dp[i-1][1][1])%MOD;
		dp[i][0][1]=dp[i-1][0][0];
		dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%MOD;
		dp[i][1][1]=dp[i-1][1][0];
	}
	ans+=(dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1])%MOD;
	ans+=(dp[m][0][0]+dp[m][0][1]+dp[m][1][0]+dp[m][1][1])%MOD;
	ans%=MOD;
	cout<<(ans-2+MOD)%MOD<<endl;
	return 0;
}