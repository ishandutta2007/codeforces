#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const long long mod=1e9+7;
const int N=100055;
struct Node
{
	vector<int> edges;
	vector<long long> vals;
	vector<int> colors;
	vector<int> CenEdges;
} Tree[N];
int NodeSize[N];
bool visited[N];
void CentroidDFS(int cur, int prev, int *n)
{
	(*n)++;
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev && !visited[v])
		{
			CentroidDFS(v,cur,n);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int GetCentroid(int cur, int prev, int n)
{
	bool isCentroid=true;
	int HeaviestChild=-1;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev && !visited[v])
		{
			if(HeaviestChild==-1 || NodeSize[HeaviestChild]<NodeSize[v])
				HeaviestChild=v;
			if(NodeSize[v]>n/2) isCentroid=false;
		}
	}
	if(HeaviestChild==-1 || (isCentroid && n-NodeSize[cur]<=n/2))
		return cur;
	return GetCentroid(HeaviestChild,cur,n);
}
int GetCentroid(int src)
{
	int n=0;
	CentroidDFS(src,src,&n);
	return GetCentroid(src,src,n);
}
int Decompose(int src)
{
	int CurCenNode=GetCentroid(src);
	visited[CurCenNode]=true;
	int i;
	for(i=0;i<Tree[CurCenNode].edges.size();i++)
	{
		int v=Tree[CurCenNode].edges[i];
		if(!visited[v])
		{
			int NewCenNode=Decompose(v);
			Tree[CurCenNode].CenEdges.push_back(NewCenNode);
		}
	}
	return CurCenNode;
}
int CenRoot;
void CentroidDecomposition(int n)
{
	int i;
	for(i=0;i<n;i++) visited[i]=false;
	CenRoot=Decompose(0);
	for(i=0;i<n;i++) visited[i]=false;
}
long long FenwickTree[2][2][4*N];
vector<int> WhatToInitialize;
bool ok;
void Initialize(int ft)
{
	int i;
	//for(i=0;i<4*N;i++)
	//{
	//	FenwickTree[ft][0][i]=1;
	//	FenwickTree[ft][1][i]=0;
	//}
	if(ok==false)
	{
		int j;
		for(j=0;j<2;j++)
		{
			for(i=0;i<4*N;i++)
			{
				FenwickTree[j][0][i]=1;
				FenwickTree[j][1][i]=0;
			}
		}
		ok=true;
	}
	for(i=0;i<WhatToInitialize.size();i++)
	{
		FenwickTree[ft][0][WhatToInitialize[i]]=1;
		FenwickTree[ft][1][WhatToInitialize[i]]=0;
	}
}
void Set(int ft, int x, long long w)
{
	for(x;x<4*N;x+=x&(-x))
	{
		FenwickTree[ft][0][x]*=w;
		FenwickTree[ft][0][x]%=mod;
		if(FenwickTree[ft][1][x]==0)
			WhatToInitialize.push_back(x);
		FenwickTree[ft][1][x]++;
	}
}
pair<long long, long long> Get(int ft, int x)
{
	pair<long long, long long> a;
	a.first=1;
	a.second=0;
	for(x;x>0;x-=x&(-x))
	{
		a.first*=FenwickTree[ft][0][x];
		a.first%=mod;
		a.second+=FenwickTree[ft][1][x];
	}
	return a;
}
long long pow(long long x, long long p)
{
	long long ans=1;
	while(p>0)
	{
		if(p&1) ans=(x*ans)%mod;
		x=(x*x)%mod;
		p>>=1;
	}
	return ans;
	/*if(p==0) return 1;
	if(p==1) return x;
	//if(p==2) return (x*x)%mod;
	if(p%2==0)
	{
		long long y=pow(x,p/2);
		return (y*y)%mod;
	}
	else
	{
		long long y=pow(x,(p-1)/2);
		y=(y*y)%mod;
		return (y*x)%mod;
	}*/
	/*long int y=pow(x,p/2);
	long int sol;
	sol=y*y;
	sol%=mod;
	if(x&1)
	{
		sol*=x;
		sol%=mod;
	}
	return sol;*/
	/*long int sol=1;
	for(int i=0;i<p;i++)
	{
		sol*=x;
	}
	return sol;*/
}
struct Back
{
	int r,b;
	long long w;
	Back (int a, int d, long long c)
	{
		r=a;
		b=d;
		w=c;
	}
};
vector<Back> Backtrack;
long long sol=1;
const int shift=N*2;
void SolDFS(int cur, int prev, int red, int black, long long path)
{
	Backtrack.push_back(Back(red,black,path));
	if(red*2>=black && black*2>=red)
	{
		sol=(sol*path)%mod;
	}
	//printf("%i:\n",cur+1);
	pair<long long, long long> p,q,r;
	p=Get(0,2*red-black+shift);
	q=Get(1,N*4-1);
	r=Get(1,2*black-red+shift);
	//printf("p:%lld %i\nq:%lld %i\nr:%lld %i\n",p.first,p.second,q.first,q.second,r.first,r.second);
	//long long tmp=p.first*pow(path,p.second-q.second+r.second);
	//tmp%=mod;
	//long int tmp1=q.first/r.first;
	//tmp1*=pow(path,q.second-r.second);
	//tmp1%=mod;
	//tmp=tmp/tmp1;
	//printf("tmp:%lld\n",tmp);
	//long long tmp=((p.first*r.first)/q.first)%mod;
	long long tmp=((p.first*r.first)%mod*pow(q.first,mod-2))%mod;
	tmp=(tmp*pow(path,p.second-q.second+r.second))%mod;
	//long long tmp=((p.first/r.first)*pow(path,p.second-r.second))%mod;
	sol*=tmp;
	sol%=mod;
	//printf("sol:%lld\n",sol);
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		long long w=Tree[cur].vals[i];
		int color=Tree[cur].colors[i];
		if(!visited[v] && v!=prev)
		{
			int nred,nblack;
			nred=red;
			nblack=black;
			if(color==0) nred++;
			else nblack++;
			SolDFS(v,cur,nred,nblack,(path*w)%mod);
		}
	}
}
void Solve(int src)
{
	visited[src]=true;
	Initialize(0);
	Initialize(1);
	WhatToInitialize.clear();
	int i,j;
	for(i=0;i<Tree[src].edges.size();i++)
	{
		int v=Tree[src].edges[i];
		long long w=Tree[src].vals[i];
		int color=Tree[src].colors[i];
		if(!visited[v])
		{
			int red=0,black=0;
			if(color==0) red++;
			else black++;
			SolDFS(v,src,red,black,w);
			for(j=0;j<Backtrack.size();j++)
			{
				Set(0,Backtrack[j].b-2*Backtrack[j].r+shift,Backtrack[j].w);
				Set(1,Backtrack[j].r-2*Backtrack[j].b+shift,Backtrack[j].w);
			}
			Backtrack.clear();
		}
	}
	for(i=0;i<Tree[src].CenEdges.size();i++)
	{
		int v=Tree[src].CenEdges[i];
		if(!visited[v])
		{
			Solve(v);
		}
	}
}
int main()
{
	int n,i,u,v,c;
	long long w;
	scanf("%i",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i %lld %i",&u,&v,&w,&c);
		u--;
		v--;
		Tree[u].edges.push_back(v);
		Tree[u].vals.push_back(w);
		Tree[u].colors.push_back(c);
		Tree[v].edges.push_back(u);
		Tree[v].vals.push_back(w);
		Tree[v].colors.push_back(c);
	}
	CentroidDecomposition(n);
	Solve(CenRoot);
	printf("%lld\n",sol);
	return 0;
}
/*
5
1 2 9 0
2 3 5 1
2 4 5 0
2 5 5 1

1265625

8
1 2 7 1
2 3 4 1
3 4 19 1
5 1 2 0
6 2 3 0
7 3 3 0
8 4 4 0

452841614
*/