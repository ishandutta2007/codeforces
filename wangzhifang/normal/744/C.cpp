#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 2147483647
#define max_n 16
#define max_m (max_n*(max_n-1)/2)
using namespace std;
int t[max_n],lg[1<<max_n],a[max_n],b[max_n];
int cnta[1<<max_n],cntb[1<<max_n],dp[1<<max_n][max_m+1];
template<typename T>void maxify(T&x,const T&y){
	y>x&&(x=y);
}
template<typename T>void minify(T&x,const T&y){
	y<x&&(x=y);
}
int main(){
	char ch;
	int n,m,suma,sumb;
	scanf("%d",&n),suma=sumb=0;
	for(int i=-1; ++i<n; t[i]=(ch=='B'),suma+=a[i],sumb+=b[i])
		scanf("\n%c%d%d",&ch,a+i,b+i);
	for(int i=-1; ++i<n; lg[1<<i]=i);
	int powe=1<<n;
	cnta[0]=cntb[0]=0;
	for(int i=0; ++i<powe; cnta[i]=cnta[i&(i-1)]+(t[lg[i&(-i)]]==0),cntb[i]=cntb[i&(i-1)]+(t[lg[i&(-i)]]==1));
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0,m=n*(n-1)/2;
	for(int s=-1; ++s<powe; )
		for(int j=-1; ++j<=m; )
			if(~dp[s][j])
				for(int i=-1,t=1; ++i<n; t<<=1)
					(s&t)||(maxify(dp[s|t][j+min(a[i],cnta[s])],dp[s][j]+min(b[i],cntb[s])),0);
	int ans=INF;
	for(int i=-1; ++i<=m; ~dp[(1<<n)-1][i]&&(minify(ans,max(suma-i,sumb-dp[powe-1][i])),1));
	printf("%d\n",ans+n);
	return 0;
}