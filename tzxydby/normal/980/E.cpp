#include<bits/stdc++.h>
using namespace std;
template<class T>struct Fenwick
{
	int n;
	T* d;
	Fenwick():n(0),d(NULL){}
	Fenwick(int n_):n(n_)
	{
		d=new T[n_]();
	}
	Fenwick(const Fenwick &y):n(y.n)
	{
		d=new T[n];
		memcpy(d,y.d,sizeof(T)*n);
	}
	~Fenwick()
	{
		delete[] d;
		d=NULL;
		n=0;
	}
	friend void swap(Fenwick &x,Fenwick &y)
	{
		swap(x.n,y.n);
		swap(x.d,y.d);
	}
	Fenwick& operator=(Fenwick y)
	{
		swap(*this,y);
		return *this;
	}
	inline void add(int i,const T &x)
	{
		for(;i<n;i|=i+1)
			d[i]+=x; 
	}
	inline T sum(int r)
	{
		T s=T();
		for(;r;r&=r-1)
			s+=d[r-1];
		return s;
	}
	T sum(int l,int r)
	{
		return sum(r)-sum(l);
	}
};
const int N=1000005;
int n,k;
vector<int>g[N],ord,st;
int sz[N],par[N],iter[N],depth[N],pos[N];
bool use[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	} 
	par[n-1]=n-1;
	ord.reserve(n);
	st.reserve(n);
	st.push_back(n-1);
	while(!st.empty())
	{
		int v=st.back();
		if(iter[v]==0)
		{
			pos[v]=ord.size();
			ord.push_back(v);
		}
		if(iter[v]==(int)g[v].size())
		{
			st.pop_back();
			continue;
		}
		int w=g[v][iter[v]++];
		if(w==par[v])
			continue;
		par[w]=v;
		st.push_back(w);
	}
	for(int i=1;i<n;i++)
	{
		int v=ord[i];
		depth[v]=depth[par[v]]+1;
		v=ord[n-i];
		sz[v]++;
		sz[par[v]]+=sz[v];
	}
	sz[n-1]=n;
	int pre=0;
	Fenwick<int>f(n+11);
	for(int i=0;i<n;i++)
	{
		int v=ord[i];
		f.add(i,depth[v]-pre);
		pre=depth[v];
	}
	int rest=n-k;
	for(int v=n;v--&&rest;)
	{
		if(use[v])
			continue;
		int len=f.sum(pos[v]+1);
		if(len+1<=rest)
		{
			int cur=v;
			while(!use[cur])
			{
				use[cur]=true;
				f.add(pos[cur],-1);
				f.add(pos[cur]+sz[cur],+1);
				cur=par[cur];
				rest--;
			}
		}
	}
	for(int i=0;i<n;i++)
		if(!use[i])
			printf("%d ",i+1);
	return 0;
}