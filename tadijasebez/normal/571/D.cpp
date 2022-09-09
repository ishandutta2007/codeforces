#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define gc getchar
const int N=500050;
//vector<int> my[N];
void Read(int &x)
{
	x=0;char c=gc();
	while(c<48 || c>57) c=gc();
	while(c>47 && c<58) x=(x<<3)+(x<<1)+c-'0',c=gc();
}
void Read(int &x, int &y){ Read(x);Read(y);}
void Read(char &c){ c=gc();while(c<65 || c>90) c=gc();}
int fir[N],las[N],go[N];
int p[N],sz[N],mx[N],myx[N],mvx[N];
ll sum[N],add[N];
void Merge1(int x, int y, int t)
{
	x=p[x];y=p[y];
	if(sz[x]<sz[y]){ Merge1(y,x,t);return;}
	sz[x]+=sz[y];
	for(int v=fir[y];v;v=go[v])
	{
		//int v=my[y][i];
		p[v]=x;
		//sum[v]+=add[y]-add[x];
		if(mvx[v]<mx[y]) myx[v]=mx[y];
		mvx[v]=t;
		//my[x].pb(v);
	}
	go[las[y]]=fir[x];
	fir[x]=fir[y];
	//my[y].clear();
}
int Find(int x){ return x==p[x]?x:Find(p[x]);}
ll Get(int x){ return x==p[x]?add[x]:add[x]+Get(p[x]);}
void Merge2(int x, int y)
{
	x=Find(x);y=Find(y);
	//x=p[x];y=p[y];
	if(sz[x]<sz[y]){ Merge2(y,x);return;}
	sz[x]+=sz[y];
	p[y]=p[x];
	add[y]-=add[x];
	/*for(int v=fir[y];v;v=go[v])
	{
		//int v=my[y][i];
		p[v]=x;
		sum[v]+=add[y]-add[x];
		//if(mvx[v]<mx[y]) myx[v]=mx[y];
		//mvx[v]=t;
		//my[x].pb(v);
	}
	go[las[y]]=fir[x];
	fir[x]=fir[y];
	//my[y].clear();*/
}
void init(int n){ for(int i=1;i<=n;++i) p[i]=i,sum[i]=add[i]=mx[i]=mvx[i]=myx[i]=0,sz[i]=1,fir[i]=las[i]=i,go[i]=0;}
//struct Update{ int t,x,y;Update(int a=0, int b=0, int c=0):t(a),x(b),y(c){}} Us[N];
int Ust[N],Usx[N],Usy[N];
//struct Query{ int t,x,mul,id;Query(int a=0, int b=0, int c=0, int d=0):t(a),x(b),mul(c),id(d){}bool operator < (Query b) const{ return t<b.t;}};
//vector<Query> Qs;
const int M=2*N;
int Qst[M],Qsx[M],Qsmul[M],Qsid[M],id[M];
bool comp(int i, int j){ return Qst[i]<Qst[j];}
ll sol[N];
int main()
{
	int n,q,i,x,y;char t;
	//scanf("%i %i",&n,&q);
	Read(n,q);
	int u=0,v=0,m=0;init(n);
	for(i=1;i<=q;++i)
	{
		//scanf("\n%c",&t);
		Read(t);
		if(t=='U')
		{
			//scanf("%i %i",&x,&y);
			Read(x,y);
			++u;
			//Us[u]=Update(1,x,y);
			Ust[u]=1;
			Usx[u]=x;
			Usy[u]=y;
		}
		else if(t=='M')
		{
			//scanf("%i %i",&x,&y);
			Read(x,y);
			++u;
			//Us[u]=Update(2,x,y);
			Merge1(x,y,u);
		}
		else if(t=='A')
		{
			//scanf("%i",&x);
			Read(x);
			++u;
			//Us[u]=Update(3,x,0);
			Ust[u]=3;
			Usx[u]=x;
		}
		else if(t=='Z')
		{
			//scanf("%i",&x);
			Read(x);
			++u;
			//Us[u]=Update(4,x,0);
			mx[p[x]]=u;
		}
		else
		{
			//scanf("%i",&x);
			Read(x);
			++v;
			int t=myx[x];
			if(mvx[x]<mx[p[x]]) t=mx[p[x]];
			++m;id[m]=m;
			Qst[m]=t;Qsx[m]=x;Qsmul[m]=-1;Qsid[m]=v;
			++m;id[m]=m;
			Qst[m]=u;Qsx[m]=x;Qsmul[m]=1;Qsid[m]=v;
			//Qs.pb(Query(t,x,-1,v));
			//Qs.pb(Query(u,x,1,v));
		}
	}
	sort(id+1,id+1+m,comp);
	init(n);
	int d=1;
	for(i=1;i<=m;i++)
	{
		while(d<=Qst[id[i]])
		{
			if(Ust[d]==1) Merge2(Usx[d],Usy[d]);
			else if(Ust[d]==3) add[Find(Usx[d])]+=sz[Find(Usx[d])];
			++d;
		}
		//int x=Qs[i].x;
		sol[Qsid[id[i]]]+=Get(Qsx[id[i]])*Qsmul[id[i]];
	}
	for(i=1;i<=v;i++) printf("%lld\n",sol[i]);
	return 0;
}