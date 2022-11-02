#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
ll all[N];
int size[N],n,f[N][N],num[N],x,s[N][N];
ll solve(int now,int l,int r){
	if (now==0)return 0;
	ll S1=0,S2=0,val1=0,val2=0,v1=0,v2=0;
	for (int i=l;i<=r;i++)val2+=(ll)f[i][now]*num[i],v2+=num[i],S2+=(ll)num[i]*s[i][now-1];
	if (!v2)return 0;
	ll ans=1e18;
	for (int i=1;i<min(l,2);i++)ans=min(ans,val2-(ll)v2*f[i][now]+S1+S2+(ll)f[i][now]*(n-size[r]+size[l-1]));
	for (int i=l,j=l;i<=r;i=j){
		while (j<=r&&f[j][now]==f[i][now])v2-=num[j],val2-=(ll)num[j]*f[j][now],S2-=(ll)s[j][now-1]*num[j],j++;
		ans=min(ans,solve(now-1,i,j-1)+(ll)f[i][now]*v1-val1+val2-(ll)v2*f[i][now]+S1+S2+(ll)f[i][now]*(n-size[r]+size[l-1]));
		for (int k=i;k<j;k++)v1+=num[k],val1+=(ll)f[k][now]*num[k],S1+=(ll)s[k][now-1]*num[k];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=5000;i++){
		for (int j=1;j<=5000;j++)f[i][j]=f[i-1][j];
		int j=i;
		for (int k=2;k<=5000;k++)
			while (j%k==0)j/=k,f[i][k]++;
		for (int j=1;j<=5000;j++)s[i][j]=s[i][j-1]+f[i][j];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		num[x]++;
	}
	for (int i=1;i<=5000;i++){
		all[i]=all[i-1];
		for (int j=1;j<=5000;j++)all[i]+=(ll)num[j]*f[j][i];
	}
	for (int i=1;i<=5000;i++)size[i]=size[i-1]+num[i];
	printf("%lld\n",solve(5000,1,5000));
}