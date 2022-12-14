#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int graph[550][550];
long long dis[550][550];

int ids[550];
long long ans[550];

bool exi[550];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&graph[i][j]);
	for(int i=0;i<N;i++)
	{
		scanf("%d",ids+i);
		ids[i]--;
	}
	for(int i=0;i<550;i++) for(int j=0;j<550;j++) dis[i][j]=1ll<<55;
	for(int i=0;i<550;i++) dis[i][i]=0;
	for(int i=0;i<N;i++) exi[i]=false;
	for(int i=N-1;i>=0;i--)
	{
		int v=ids[i];
		exi[v]=true;
		for(int j=0;j<N;j++)
		{
			if(exi[j]==false) continue;
			dis[v][j]=min(dis[v][j],(long long)graph[v][j]);
			dis[j][v]=min(dis[j][v],(long long)graph[j][v]);
		}
		for(int j=0;j<N;j++)
		{
			if(exi[j]==false) continue;
			for(int k=0;k<N;k++)
			{
				if(exi[k]==false) continue;
				dis[v][j]=min(dis[v][j],dis[v][k]+dis[k][j]);
				dis[j][v]=min(dis[j][v],dis[j][k]+dis[k][v]);
			}
		}
		for(int j=0;j<N;j++) for(int k=0;k<N;k++)
		{
			if(exi[j]==false||exi[k]==false) continue;
			dis[j][k]=min(dis[j][k],dis[j][v]+dis[v][k]);
		}
		long long res=0;
		for(int j=0;j<N;j++) for(int k=0;k<N;k++)
		{
			if(dis[j][k]!=1ll<<55) res+=dis[j][k];
		}
		ans[i]=res;
	}
	for(int i=0;i<N;i++)
	{
		cout<<ans[i]<<(i==N-1?'\n':' ');
	}
	return 0;
}