#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=250;
const int s=N-2,t=N-1;
const int inf=1000000000;
bool NotPrime[200001];
void FindPrimes()
{
	int i,j;
	NotPrime[1]=true;
	for(i=2;i<200001;i++)
		if(!NotPrime[i])
			for(j=i+i;j<200001;j+=i)
				NotPrime[j]=true;

}
struct Node
{
	int level;
	int num;
	int power;
	inline bool operator < (const Node &b) const
	{
		return level<b.level;
	}
} Cards[N];
class Graph
{
 private:
	int l,r,n;
	int sum;
	int ResidualGraph[N][N];
	int num[N];
	int power[N];
	queue<int> q;
	int parent[N];
	bool visited[N];
 public:
	Graph()
	{
		sum=0;
		l=0;
		r=0;
		n=N/2;
		int i,j;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				ResidualGraph[i][j]=0;
			}
		}
	}
	void AddNode(Node b)
	{
		sum+=b.power;
		if(b.num%2==1)
		{
			num[l]=b.num;
			power[l]=b.power;
			l++;
		}
		else
		{
			num[n+r]=b.num;
			power[n+r]=b.power;
			r++;
		}
	}
	void Initialize()
	{
		sum=0;
		l=0;
		r=0;
		n=N/2;
		int i,j;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				ResidualGraph[i][j]=0;
			}
		}
	}
	void ConstructBipartiteGraph()
	{
		int i,j;
		for(i=0;i<l;i++)
		{
			ResidualGraph[s][i]=power[i];
			for(j=0;j<r;j++)
			{
				if(!NotPrime[num[i]+num[j+n]])
				{
					ResidualGraph[i][j+n]=inf;
				}
			}
		}
		for(i=0;i<r;i++)
		{
			ResidualGraph[i+n][t]=power[i+n];
		}
	}
	bool BFS()
	{
		int i;
		for(i=0;i<N;i++)
		{
			visited[i]=false;
		}
		q.push(s);
		visited[s]=true;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(i=0;i<l;i++)
			{
				if(!visited[i] && ResidualGraph[x][i]>0)
				{
					parent[i]=x;
					visited[i]=true;
					q.push(i);
				}
			}
			for(i=n;i<r+n;i++)
			{
				if(!visited[i] && ResidualGraph[x][i]>0)
				{
					parent[i]=x;
					visited[i]=true;
					q.push(i);
				}
			}
			i=t;
			if(!visited[i] && ResidualGraph[x][i]>0)
			{
				parent[i]=x;
				visited[i]=true;
				q.push(i);
			}
		}
		return visited[t];
	}
	int Solve()
	{
		int MaxFlow=0,i;
		while(BFS())
		{
			int MinCut=inf;
			for(i=t;i!=s;i=parent[i])
			{
				if(MinCut>ResidualGraph[parent[i]][i])
					MinCut=ResidualGraph[parent[i]][i];
			}
			MaxFlow+=MinCut;
			for(i=t;i!=s;i=parent[i])
			{
				ResidualGraph[parent[i]][i]-=MinCut;
				ResidualGraph[i][parent[i]]+=MinCut;
			}
		}
		return sum-MaxFlow;
	}
} g;
bool Check(int lvl, int n, int k)
{
	g.Initialize();
	int i=0;
	int JedanMax=-1,JedanMin=-1;
	while(i<n && Cards[i].level<=lvl)
	{
		if(Cards[i].num==1)
		{
			if(JedanMax==-1 || Cards[i].power>Cards[JedanMax].power)
				JedanMax=i;
			if(JedanMin==-1 || Cards[i].power<Cards[JedanMin].power)
				JedanMin=i;
		}
		else
		{
			g.AddNode(Cards[i]);
		}
		i++;
	}
	
	if(JedanMin!=-1)
	{
		//g.AddNode(Cards[JedanMin]);	
		g.AddNode(Cards[JedanMax]);
	}
	g.ConstructBipartiteGraph();
	int tmp1=g.Solve(),tmp2=0;
	//printf("%i %i\n",lvl,i);
	/*if(JedanMax!=-1)
	{
		g.Initialize();
		i=0;
		while(i<n && Cards[i].level<=lvl)
		{
			if(Cards[i].num!=1) g.AddNode(Cards[i]);
			i++;
		}
		g.AddNode(Cards[JedanMax]);
		g.ConstructBipartiteGraph();
		tmp2=g.Solve();
	}*/
	if(tmp1<tmp2) tmp1=tmp2;
	//printf("%i\n",tmp1);
	return k<=tmp1;
}
int main()
{
	int n,k,i;
	int sol,top,bot,mid;
	scanf("%i%i",&n,&k);
	for(i=0;i<n;i++) scanf("%i %i %i",&Cards[i].power,&Cards[i].num,&Cards[i].level);
	sort(Cards,Cards+n);
	FindPrimes();
	bot=1;
	top=n;
	sol=-1;
	while(top>=bot)
	{
		mid=(top+bot)>>1;
		if(Check(mid,n,k)) sol=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	//for(i=1;i<50;i++) if(!NotPrime[i]) printf("%i ",i);
	return 0;
}