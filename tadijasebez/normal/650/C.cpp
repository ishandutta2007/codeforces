#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1000050;
int p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
int in[N],a[N],sol[N];
vector<int> E[N];
int max(int a, int b){ return a>b?a:b;}
vector<int> id;
bool comp(int x, int y){ return a[x]<a[y];}
int main()
{
	Init();
	int n,m,i,j,k;
	scanf("%i %i",&n,&m);
	for(k=0;k<n*m;k++) scanf("%i",&a[k]);
	for(i=0;i<n;i++)
	{
		id.clear();
		for(j=0;j<m;j++) id.push_back(i*m+j);
		sort(id.begin(),id.end(),comp);
		for(j=1;j<id.size();j++)
		{
			int x=id[j],y=id[j-1];
			if(a[x]==a[y]) Union(x,y);
		}
	}
	for(j=0;j<m;j++)
	{
		id.clear();
		for(i=0;i<n;i++) id.push_back(i*m+j);
		sort(id.begin(),id.end(),comp);
		for(i=1;i<id.size();i++)
		{
			int x=id[i],y=id[i-1];
			if(a[x]==a[y]) Union(x,y);
		}
	}
	for(i=0;i<n;i++)
	{
		id.clear();
		for(j=0;j<m;j++) id.push_back(i*m+j);
		sort(id.begin(),id.end(),comp);
		for(j=1;j<id.size();j++)
		{
			int x=id[j],y=id[j-1];
			if(a[x]>a[y]) in[Find(x)]++,E[Find(y)].push_back(Find(x));
		}
	}
	for(j=0;j<m;j++)
	{
		id.clear();
		for(i=0;i<n;i++) id.push_back(i*m+j);
		sort(id.begin(),id.end(),comp);
		for(i=1;i<id.size();i++)
		{
			int x=id[i],y=id[i-1];
			if(a[x]>a[y]) in[Find(x)]++,E[Find(y)].push_back(Find(x));
		}
	}
	queue<int> q;
	for(k=0;k<n*m;k++) if(k==Find(k) && !in[k]) q.push(k),sol[k]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(i=0;i<E[x].size();i++)
		{
			int y=E[x][i];
			in[y]--;
			sol[y]=max(sol[y],sol[x]+1);
			if(!in[y]) q.push(y);
		}
	}
	for(k=0;k<n*m;k++)
	{
		printf("%i ",sol[Find(k)]);
		if(k%m==m-1) printf("\n");
	}
	return 0;
}