// CF 815C
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
const int inf = (1<<30)-1;
int n,b,c[5555],d[5555],fa[5555],t[5555],f[5555][5555],g[5555][5555],dp[5555];
int main()
{
	int i,j,k,x,s;
	cin>>n>>b;
	for(i=1;i<=n;i=i+1){
		cin>>c[i]>>d[i];
		if(i!=1)
			cin>>fa[i];
		d[i]=c[i]-d[i];
		t[i]=1;
		f[i][0]=inf;
		f[i][1]=d[i];
		g[i][0]=0;
		g[i][1]=c[i];
	}
	for(i=n;i>=2;i=i-1)
	{
		for(j=0;j<=n+5;j=j+1)
			dp[j]=inf;
		x=fa[i];
		for(j=1;j<=t[x];j=j+1)
			for(k=0;k<=t[i];k=k+1)
				dp[j+k]=min(dp[j+k],f[x][j]+min(f[i][k],g[i][k]));
		s=0;
		for(j=2;j<=t[x]+t[i];j=j+1){
			f[x][j]=dp[j];
			if(f[x][j]>b||s){
				f[x][j]=inf;
				s=1;
			}
		}
		for(j=0;j<=n+5;j=j+1)
			dp[j]=inf;
		for(j=0;j<=t[x];j=j+1)
			for(k=0;k<=t[i];k=k+1)
				dp[j+k]=min(dp[j+k],g[x][j]+g[i][k]);
		s=0;
		for(j=1;j<=t[x]+t[i];j=j+1){
			g[x][j]=dp[j];
			if(g[x][j]>b||s){
				g[x][j]=inf;
				s=1;
			}
		}
		t[x]+=t[i];
	}
	/*j=1;
	for(i=0;i<=t[j];i=i+1)
		cout<<i<<' '<<f[j][i]<<' '<<g[j][i]<<endl;*/
	for(i=0;i<=n;i=i+1){
		if(min(f[1][i+1],g[1][i+1])>b){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}