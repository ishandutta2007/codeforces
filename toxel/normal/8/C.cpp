#include <bits/stdc++.h>
using namespace std;
int sqr(int x){return x*x;}
int x[25],y[25],n,dis[25][25],path[1<<24];
int dp[(1<<24)];
int main(){
	int i,j,l,f,s,cur,maxi,p;
	cin>>x[0]>>y[0]>>n;
	for(i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(i=0;i<n+1;++i)
		for(j=0;j<n+1;++j)
			dis[i][j]= sqr(x[i]-x[j])+sqr(y[i]-y[j]);

	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	int t= 0x3f3f3f3f;
	for(i=0;i<(1<<n)-1;++i)
		if(dp[i]<t)
			for(j=0;j<n;++j)if(!(i>>j&1)){
				for(s=j;s<n;++s) if(!(i>>s&1)){
					int p = i|1<<j|1<<s,v = dp[i]+dis[0][j+1]+dis[j+1][s+1]+dis[s+1][0];
					if(dp[p]>v)dp[p]= v,path[p]=i;
				}
				break;
			}	
	printf("%d\n",dp[(1<<n)-1]);
	cout<<0;
	for(i=(1<<n)-1;i;i=path[i]){
		for(j=i^path[i];j;j-=j&-j)
			printf(" %d",int(log(j&-j)/log(2)+1e-8+1));
		printf(" 0");
	}
	putchar('\n');
}