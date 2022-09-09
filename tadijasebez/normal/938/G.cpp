#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define pb push_back
const int N=200050;
const int M=2*N;
struct Edge{ int u,v,w;Edge(int a, int b, int c){ u=a,v=b,w=c;}};
vector<Edge> eds[M];
int ls[M],rs[M],tsz,root;
void AddEdge(int &c, int ss, int se, int qs, int qe, int u, int v, int w)
{
	if(qs>qe || ss>qe || qs>se) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ eds[c].pb(Edge(u,v,w));return;}
	int mid=ss+se>>1;
	AddEdge(ls[c],ss,mid,qs,qe,u,v,w);
	AddEdge(rs[c],mid+1,se,qs,qe,u,v,w);
}
int p[N],r[N],x[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i,r[i]=1;}
int Find(int i){ return i==p[i]?i:Find(p[i]);}
int FindXor(int i){ return i==p[i]?0:x[i]^FindXor(p[i]);}
vector<int> bck;
int Gauss[31];
void AddCycle(int w)
{
	for(int i=29;~i;i--)
	{
		if(!((w>>i)&1)) continue;
		if(!Gauss[i])
		{
			Gauss[i]=w;
			bck.pb(i);
			return;
		}
		w^=Gauss[i];
	}
	bck.pb(30);
}
void PrintGauss(){ printf("Gauss:");for(int i=3;~i;i--) printf("%i ",Gauss[i]);printf("\n");}
void DelCycle(){ Gauss[bck.back()]=0;bck.pop_back();}
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
vector<int> lzy;
void AddEdge(int u, int v, int w)
{
	//printf("AddEdge:%i %i %i  ",u,v,w);
	int a=Find(u);
	int b=Find(v);
	w^=FindXor(u)^FindXor(v);
	//printf("%i\n",w);
	if(a==b){ AddCycle(w);lzy.pb(0);return;}
	bck.pb(30);
	if(r[a]<r[b]) Swap(a,b);
	//printf("par[%i]=%i x[%i]=%i\n",b,a,b,w);
	p[b]=a;
	r[a]+=r[b];
	x[b]=w;
	lzy.pb(b);
}
void DelEdge()
{
	DelCycle();
	if(lzy.back())
	{
		int v=lzy.back();
		r[p[v]]-=r[v];
		p[v]=v;
		x[v]=0;
	}
	lzy.pop_back();
}
int min(int a, int b){ return a>b?b:a;}
int sol[N],qu[N],qv[N],cnt;
void Solve(int c, int ss, int se)
{
	//if(se<=cnt) printf("ss:%i se:%i ",ss,se),PrintGauss();
	int i;
	for(i=0;i<eds[c].size();i++) AddEdge(eds[c][i].u,eds[c][i].v,eds[c][i].w);
	//if(se<=cnt) PrintGauss();
	if(ss==se)
	{
		sol[ss]=FindXor(qu[ss])^FindXor(qv[ss]);
		if(ss<=cnt)
		{
			//printf("dist:%i\n",sol[ss]);
			//PrintGauss();
		}
		for(i=29;~i;i--) sol[ss]=min(sol[ss],sol[ss]^Gauss[i]);
		for(i=0;i<eds[c].size();i++) DelEdge();
		return;
	}
	int mid=ss+se>>1;
	Solve(ls[c],ss,mid);
	Solve(rs[c],mid+1,se);
	for(i=0;i<eds[c].size();i++) DelEdge();
	//if(se<=cnt) printf("ss:%i se:%i ",ss,se),PrintGauss();
}
map<int,int> time[N],dist[N];
map<int,int>::iterator it;
int main()
{
	int n,m,q,u,v,w,i,t;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i %i",&u,&v,&w);
		if(u>v) Swap(u,v);
		time[u][v]=1;
		dist[u][v]=w;
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&t,&u,&v);
		if(u>v) Swap(u,v);
		if(t==1)
		{
			scanf("%i",&w);
			time[u][v]=cnt+1;
			dist[u][v]=w;
		}
		if(t==2)
		{
			if(time[u].count(v)) AddEdge(root,1,N,time[u][v],cnt,u,v,dist[u][v]);
			time[u].erase(v);
			dist[u].erase(v);
		}
		if(t==3)
		{
			cnt++;
			qu[cnt]=u;
			qv[cnt]=v;
		}
	}
	for(u=1;u<=n;u++)
	{
		for(it=time[u].begin();it!=time[u].end();it++)
		{
			v=it->first;
			t=it->second;
			AddEdge(root,1,N,t,cnt,u,v,dist[u][v]);
		}
	}
	Init();
	Solve(root,1,N);
	for(i=1;i<=cnt;i++) printf("%i\n",sol[i]);
	return 0;
}