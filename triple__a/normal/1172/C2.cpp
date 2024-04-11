#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

const int maxn=300007;
const int maxm=5007;
const int mod=998244353;

int n,m,l[maxn],w[maxn],yes=0,no=0;
int dp[maxm][maxm];

inline int exgcd(int a,int b,int &x,int &y){
	if (!b){
		x=1,y=0;
		return a;
	}
	int ans=exgcd(b,a%b,x,y);
	int u=y,v=x-a/b*y;
	x=u,y=v;
	return ans;
}

inline int inv(int u){
	u=(u%mod+mod)%mod;
	int ans,tmp;
	exgcd(u,mod,ans,tmp);
	return (ans%mod+mod)%mod;
}

inline int mult(int u,int v){
	return u*v%mod;
}

#undef int
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;++i) scanf("%lld",&l[i]);
	for (int i=1;i<=n;++i) scanf("%lld",&w[i]);
	for (int i=1;i<=n;++i){
		if (l[i]) yes+=w[i];
		else no+=w[i];
	}
	dp[0][0]=1;
	for (int i=1;i<=m;++i){
		for (int j=0;j<i;++j){
			dp[i][j]=(dp[i][j]+mult(dp[i-1][j],mult((no-i+j+1)%mod,inv(yes+no-i+2*j+1))))%mod;
			dp[i][j+1]=(dp[i][j+1]+mult(dp[i-1][j],mult(yes+j,inv(yes+no-i+2*j+1))))%mod;
		}
	}
	int ans1=0,ans2=0;
	for (int i=0;i<=m;++i){
		ans1=(ans1+mult(yes+i,dp[m][i]))%mod;
		ans2=(ans2+mult((no-m+i+mod)%mod,dp[m][i]))%mod;
	}
	for (int i=1;i<=n;++i){
		if (l[i]){
			printf("%lld\n",mult(inv(yes),mult(ans1,w[i])));
		}
		else{
			printf("%lld\n",mult(inv(no),mult(ans2,w[i])));
		}
	}
	return 0;
}