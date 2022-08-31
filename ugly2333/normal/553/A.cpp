//CF A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 1005;
const int mod = 1e9+7;
int a[N],s[N];
int dp[N][N],inv[N];
int fpow(int x,int p){
	if(!p)
		return 1;
	LL res;
	res=fpow(x,p>>1);
	res=res*res%mod;
	if(p&1)
		res=res*x%mod;
	return res;
}
void exgcd(int a,int b,int& x,int& y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int getinv(int q){
	int x,y;
	exgcd(q,mod,x,y);
	return (x%mod+mod)%mod;
}
int main()
{
	int n,i,j,h,x;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[n+1-i];
	h=0;
	for(i=1;i<=n;i=i+1)
		s[i]=s[i-1]+a[i],h+=a[i];
	dp[0][0]=1;
	for(i=0;i<h;i=i+1){
		for(j=0;j<=n;j=j+1){
			if(dp[i][j]){
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
				dp[i+1][j]=(dp[i+1][j]+(LL)dp[i][j]*(s[j]-i)%mod)%mod;
			}
		}
	}
	/*x=1;
	for(i=1;i<=h;i=i+1)
		x=(LL)x*i%mod;
	inv[h]=fpow(x,mod-2);
	for(i=h-1;i>=0;i=i-1)
		inv[i]=(LL)inv[i+1]*(i+1)%mod;*/
	x=1;
	inv[0]=1;
	for(i=1;i<=h;i=i+1)
		x=(LL)x*i%mod,inv[i]=getinv(x);
	x=dp[h][n];
	//cout<<h<<x<<endl;
	for(i=1;i<=n;i=i+1)
		x=(LL)x*inv[a[i]-1]%mod;
	cout<<x<<endl;
	return 0;
}