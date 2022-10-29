#include <iostream>
#define int long long
using namespace std;
int a[100005],e[1005][1005],dis[2005][2005];
signed main(int argc, char** argv) {
	int n,cnt;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		if(t!=0)
			a[++cnt]=t;
	}
	n=cnt;
	if(n>200)
	{
		puts("3");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) 
				e[i][j]=dis[i][j]=100000;
		}
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]&a[j])
				e[i][j]=e[j][i]=dis[i][j]=dis[j][i]=1;
			if(i==j)
				dis[i][j]=0;
		}
	}
	int ans=100000;
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<k;++i)
			for(int j=i+1;j<k;++j)
				ans=min(ans,dis[i][j]+e[i][k]+e[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans==100000)
		cout << -1;
	else
		cout << ans << endl;
	return 0;
}