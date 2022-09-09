#include <stdio.h>
#include <vector>
using namespace std;
const int inf=1e9;
const int N=350;
const int S=8*N;
const int M=32*N*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],clock,root[S],cnt,LS[S],RS[S],First[4];
void Set(int &c, int ss, int se, int qi, int X)
{
	if(!c) c=++clock,x[c]=-inf,ls[c]=0,rs[c]=0;
	x[c]=max(x[c],X);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,X);
	else Set(rs[c],mid+1,se,qi,X);
}
void Set(int &c, int ss, int se, int qi, int id, int X)
{
	if(!c) c=++cnt,LS[c]=0,RS[c]=0,root[c]=0;
	Set(root[c],1,N,id,X);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(LS[c],ss,mid,qi,id,X);
	else Set(RS[c],mid+1,se,qi,id,X);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(!c) return -inf;
	if(ss>qe || qs>se) return -inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int Get(int c, int ss, int se, int qs, int qe, int y1, int y2)
{
	if(!c) return -inf;
	if(ss>qe || qs>se) return -inf;
	if(qs<=ss && qe>=se) return Get(root[c],1,N,y1,y2);
	int mid=ss+se>>1;
	return max(Get(LS[c],ss,mid,qs,qe,y1,y2),Get(RS[c],mid+1,se,qs,qe,y1,y2));
}
void Init()
{
	clock=0;cnt=0;
	for(int i=0;i<4;i++) First[i]=0;
}
vector< pair<int,int> > E[N*N];
int min(int a, int b){ return a>b?b:a;}
int min(int a, int b, int c, int d){ return min(min(a,b),min(c,d));}
int Dist[N][N];
int main()
{
	x[0]=-inf;
	int n,m,p,v,i,j;
	scanf("%i %i %i",&n,&m,&p);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&v),E[v].push_back(make_pair(i,j));
	for(i=0;i<E[1].size();i++) 
	{
		int x=E[1][i].first;
		int y=E[1][i].second;
		Dist[x][y]=x+y-2;
		Set(First[0],1,N,x,y,x+y-Dist[x][y]);
		Set(First[1],1,N,x,y,x-y-Dist[x][y]);
		Set(First[2],1,N,x,y,y-x-Dist[x][y]);
		Set(First[3],1,N,x,y,-y-x-Dist[x][y]);
	}
	for(j=2;j<=p;j++)
	{
		for(i=0;i<E[j].size();i++)
		{
			int x=E[j][i].first;
			int y=E[j][i].second;
			Dist[x][y]=min(x+y-Get(First[0],1,N,1,x,1,y),
						   x-y-Get(First[1],1,N,1,x,y,N),
						   y-x-Get(First[2],1,N,x,N,1,y),
						  -x-y-Get(First[3],1,N,x,N,y,N));
		}
		Init();
		for(i=0;i<E[j].size();i++)
		{
			int x=E[j][i].first;
			int y=E[j][i].second;
			Set(First[0],1,N,x,y,x+y-Dist[x][y]);
			Set(First[1],1,N,x,y,x-y-Dist[x][y]);
			Set(First[2],1,N,x,y,y-x-Dist[x][y]);
			Set(First[3],1,N,x,y,-y-x-Dist[x][y]);
		}
	}
	int sol=inf;
	for(i=0;i<E[p].size();i++)
	{
		int x=E[p][i].first;
		int y=E[p][i].second;
		sol=min(sol,Dist[x][y]);
	}
	printf("%i\n",sol);
	return 0;
}