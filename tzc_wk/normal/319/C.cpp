#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define int long long
int n,a[100005],b[100005];
int dp[100005];
int q[100005],hd=1,tl=0;
inline double sl(int j,int k){
	return 1.0*(dp[k]-dp[j])/(b[j]-b[k]);
}
signed main(){
	cin>>n;
	fz(i,1,n)	cin>>a[i];
	fz(i,1,n)	cin>>b[i];
	memset(dp,63,sizeof(dp));
	dp[1]=0;
	q[++tl]=1;
	fz(i,2,n){
		while(hd<tl&&sl(q[hd],q[hd+1])<a[i])	hd++;
		dp[i]=dp[q[hd]]+b[q[hd]]*a[i];
		while(hd<tl&&sl(i,q[tl])<sl(q[tl],q[tl-1]))	tl--;
		q[++tl]=i;
//		cout<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
}
/*
dp[i]=min(dp[j]+b[j]*a[i])

j>k

dp[j]+b[j]*a[i]<dp[k]+b[k]*a[i]
dp[j]-dp[k]<a[i]*(b[k]-b[j])
dp[j]-dp[k]
----------->-a[i]
 b[j]-b[k]
*/