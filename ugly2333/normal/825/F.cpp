//??CF 825F
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
const int m1 = 1e9+37;
const int m2 = 1e9+91;
const int base = 137;
char c[8888];
int pwr1[8888],pwr2[8888];
int h1[8888],h2[8888],a[8888];
int f[8888][8888],dp[8888];
pair<int,int> geth(int l,int r){
	if(l==0)
		return make_pair(h1[r],h2[r]);
	l--;
	int x,y;
	x=(h1[r]-(LL)h1[l]*pwr1[r-l]%m1+m1)%m1;
	y=(h2[r]-(LL)h2[l]*pwr2[r-l]%m2+m2)%m2;
	return make_pair(x,y);
}
bool g(int j,int k)
{
	//if(k>=15)
	//	return geth(j-k+1,j)==geth(j+1,j+k);
	int i;
	for(i=1;i<=k;i=i+1)
		if(c[j-k+i]!=c[j+i])
			return 0;
	return 1;
}
int main()
{
	int n,i,j,l,k;
	scanf("%s",&c);
	n=strlen(c);
	pwr1[0]=1;
	pwr2[0]=1;
	for(i=1;i<=n;i=i+1){
		pwr1[i]=(LL)pwr1[i-1]*base%m1;
		pwr2[i]=(LL)pwr2[i-1]*base%m2;
	}
	a[0]=0;
	for(i=1;i<=n;i=i+1)
		a[i]=a[i/10]+1;
	h1[0]=c[0];
	h2[0]=c[0];
	for(i=1;i<n;i=i+1){
		h1[i]=((LL)h1[i-1]*base+c[i])%m1;
		h2[i]=((LL)h2[i-1]*base+c[i])%m2;
	}
	for(i=0;i<n;i=i+1)
		for(j=i;j<n;j=j+1)
			f[i][j]=j-i+1;
	for(l=0;l<n;l=l+1){
		for(i=0,j=l;j<n;i=i+1,j=j+1){
			k=f[i][j];
			if(j+k<n&&k<f[i][j+k]&&g(j,k))
				f[i][j+k]=k;
		}
	}
	for(i=0;i<n;i=i+1){
		dp[i]=f[0][i]+a[(i+1)/f[0][i]];
		for(j=0;j<i;j=j+1)
			dp[i]=min(dp[i],dp[j]+f[j+1][i]+a[(i-j)/f[j+1][i]]);
	}
	cout<<dp[n-1]<<endl;
	return 0;
}