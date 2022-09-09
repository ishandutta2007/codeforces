#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],clock,root;
void Init(){ root=0;clock=0;x[0]=0;}
void Set(int &c, int ss, int se, int qi, int X)
{
	if(!c) c=++clock,x[c]=0,ls[c]=0,rs[c]=0;
	if(ss==se){ x[c]=X;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,X);
	else Set(rs[c],mid+1,se,qi,X);
	x[c]=min(x[ls[c]],x[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
vector<int> v[2][N];
struct Query
{
	int x1,y1,x2,y2,i;
	Query(){}
	Query(int a, int b, int c, int d, int e){ x1=a,y1=b,x2=c,y2=d,i=e;}
};
vector<Query> Q[2][N];
bool sol[M];
int main()
{
	Init();
	int n,m,k,i,j,q,x1,y1,x2,y2;
	scanf("%i %i %i %i",&n,&m,&k,&q);
	while(k--)
	{
		scanf("%i %i",&x1,&y1);
		v[0][x1].push_back(y1);
		v[1][y1].push_back(x1);
	}
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		Q[0][x2].push_back(Query(x1,y1,x2,y2,i));
		Q[1][y2].push_back(Query(x1,y1,x2,y2,i));
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<v[0][i].size();j++)
		{
			Set(root,1,m,v[0][i][j],i);
		}
		for(j=0;j<Q[0][i].size();j++)
		{
			sol[Q[0][i][j].i]|=Q[0][i][j].x1<=Get(root,1,m,Q[0][i][j].y1,Q[0][i][j].y2);
		}
	}
	Init();
	for(i=1;i<=m;i++)
	{
		for(j=0;j<v[1][i].size();j++)
		{
			Set(root,1,n,v[1][i][j],i);
		}
		for(j=0;j<Q[1][i].size();j++)
		{
			sol[Q[1][i][j].i]|=Q[1][i][j].y1<=Get(root,1,n,Q[1][i][j].x1,Q[1][i][j].x2);
		}
	}
	for(i=1;i<=q;i++) 
	{
		if(sol[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}