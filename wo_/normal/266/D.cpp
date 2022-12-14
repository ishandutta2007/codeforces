#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const int inf=1<<29;

int graph[220][220];
int dis[220][220];

int N;

bool judge(int x)
{
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(graph[i][j]==inf) continue;
			vector<P> vec;
			int d=graph[i][j];
			bool flg=true;
			for(int v=0;v<N;v++)
			{
				int a=dis[v][i],b=dis[v][j];
				if(a==b+d)
				{
					if(x<b) flg=false;
					else if(b<=x&&x<=a)
					{
						int tmp=d-(x-b);
						vec.push_back(P(tmp,-1));
						vec.push_back(P(d,1));
					}
					else
					{
						vec.push_back(P(0,-1));
						vec.push_back(P(d,1));
					}
				}
				else if(b==a+d)
				{
					if(x<a) flg=false;
					else if(a<=x&&x<=b)
					{
						int tmp=x-a;
						vec.push_back(P(0,-1));
						vec.push_back(P(tmp,1));
					}
					else
					{
						vec.push_back(P(0,-1));
						vec.push_back(P(d,1));
					}
				}
				else
				{
					int M=max(a,b);
					int m=min(a,b);
					if(x<m)
					{
						flg=false;
						continue;
					}
					int farthest=M+(d-(M-m))/2;
					if(farthest<=x)
					{
						vec.push_back(P(0,-1));
						vec.push_back(P(d,1));
						continue;
					}
					vec.push_back(P(0,-1));
					vec.push_back(P(x-a,1));
					vec.push_back(P(d-(x-b),-1));
					vec.push_back(P(d,1));
				}
			}
			if(flg==false) continue;
			sort(vec.begin(),vec.end());
			int cnt=0;
			for(int k=0;k<vec.size();k++)
			{
				cnt-=vec[k].second;
				if(cnt>=N) return true;
			}
		}
	}
	return false;
}
int main()
{
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++)
	{
		graph[i][j]=i==j?0:inf;
		dis[i][j]=i==j?0:inf;
	}
	for(int i=0;i<M;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		u--;v--;
		d*=2;
		dis[u][v]=d;dis[v][u]=d;
		graph[u][v]=d;graph[v][u]=d;
	}
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++) for(int j=0;j<N;j++)
		{
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	int ub=inf,lb=0;//(,]
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(judge(mid)) ub=mid;
		else lb=mid;
	}
	int num=ub/2;
	printf("%d",num);
	if(ub%2==1)
	{
		printf(".5");
	}
	printf("\n");
	return 0;
}