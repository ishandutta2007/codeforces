#include<bits/stdc++.h>
#define INF (1<<29)
using namespace std;
int n,k,l;
int x[30],a[110];
int dist[10010];
int graph[30][30];
int dp[(1<<20)];
queue<int>q;
void add(int pos,int d)
{
	if(d<dist[pos])
	{
		dist[pos]=d;
		q.push(pos);	
	}	
} 
void bfs(int start)
{
	int i;
	for(i=0;i<=n;i++)
		dist[i]=INF;
	add(start,0);
	while(!q.empty())
	{
		int pos=q.front();
		q.pop();
		for(int i=0;i<l;i++)
		{
			if(pos-a[i]>=0)
				add(pos-a[i],dist[pos]+1);
			if(pos+a[i]<=n)
				add(pos+a[i],dist[pos]+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int mask,i,j;
	cin>>n>>k>>l;
	for(i=0;i<k;i++)
	{
		cin>>x[i];
		x[i]--;
	}
	for(i=0;i<l;i++)
		cin>>a[i];
	for(i=0;i<k;i++)
		x[k+i]=x[i]+1;
	k*=2;
	for(i=0;i<k;i++)
	{
		bfs(x[i]);
		for(int j=0;j<k;j++)
			graph[i][j]=dist[x[j]];
	}
	for(i=0;i<(1<<k);i++)
		dp[i]=INF;
	dp[0]=0;
	for(mask=0;mask<(1<<k);mask++)
	{
		if(mask!=0)
		{
			for(i=0;i<k;i++)
				if(mask&(1<<i))
					break;
			for(int j=0;j<k;j++)
				if(mask&(1<<j))
					if(i!=j)
						dp[mask]=min(dp[mask],dp[mask^(1<<i)^(1<<j)]+graph[i][j]);
		} 
	}
	int ans=dp[(1<<k)-1];
	if(ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}