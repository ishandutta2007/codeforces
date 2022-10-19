#include<bits/stdc++.h>
using namespace std;
const int N=1001,M=41;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,k,t,a[N][N],dis[M][N][N],vis[M];
vector<pair<int,int>>co[M];
pair<int,int> q[N*N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int c=1;c<=k;c++)
				dis[c][i][j]=1e9;
			scanf("%d",&a[i][j]);
			dis[a[i][j]][i][j]=0;
			co[a[i][j]].emplace_back(i,j);
		}
	}
	for(int c=1;c<=k;c++)
	{
		for(int i=1;i<=k;i++)
			vis[i]=0;
		auto d=dis[c];
		int b=0,e=0;
		for(auto i:co[c])
			q[e++]=i;
		while(b<e)
		{
			int x=q[b].first,y=q[b].second;
			b++;
			if(!vis[a[x][y]])
			{
				vis[a[x][y]]=1;	
				for(auto i:co[a[x][y]])
				{
					int kx=i.first,ky=i.second;
					if(d[kx][ky]>d[x][y]+1)
					{
						d[kx][ky]=d[x][y]+1;
						q[e++]=make_pair(kx,ky);
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				int kx=x+dx[i],ky=y+dy[i];
				if(kx<1||kx>n||ky<1||ky>m)
					continue;
				if(d[kx][ky]>d[x][y]+1)
				{
					d[kx][ky]=d[x][y]+1;
					q[e++]=make_pair(kx,ky);
				}
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=abs(x1-x2)+abs(y1-y2);
		for(int c=1;c<=k;c++)
			ans=min(ans,dis[c][x1][y1]+dis[c][x2][y2]+1);
		printf("%d\n",ans);
	}
	return 0;
}