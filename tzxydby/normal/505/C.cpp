#include<bits/stdc++.h>
using namespace std;
const int N=3e4;
const int MAGIC=400;
const int inf=1e9;
int cnt[N+10];
int d[N+1][2*MAGIC+1];
int main()
{
	int n,D;
	scanf("%d%d",&n,&D);
	for(int i=0;i<n;i++)
	{
		int cur;
		scanf("%d",&cur);
		cnt[cur]++;
	}
	for(int i=0;i<N;i++)
		for(int j=-MAGIC;j<=MAGIC;j++)
			d[i][j+MAGIC]=-inf;
	d[D][0+MAGIC]=cnt[0]+cnt[D];
	for(int i=D;i<N;i++)
	{
		for(int j=-MAGIC;j<=MAGIC;j++)
		{
			if(d[i][j+MAGIC]==-inf)
				continue;
			for(int z=-1;z<=1;z++)
			{
				int len=j+D+z;
				if(j+z<-MAGIC||j+z>MAGIC||len<1||i+len>N)
					continue;
				d[i+len][j+z+MAGIC]=max(d[i+len][j+z+MAGIC],d[i][j+MAGIC]+cnt[i+len]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=N;i++)
		for(int j=-MAGIC;j<=MAGIC;j++)
			ans=max(ans,d[i][j+MAGIC]);
	printf("%d\n",ans);
	return 0;
}