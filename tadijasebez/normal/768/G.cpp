#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=2*N;
const int inf=1e9+7;
multiset<int> node[M];
multiset<int>::iterator it;
int ls[M],rs[M],tsz,root;
void Add(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	node[c].insert(val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Add(ls[c],ss,mid,qi,val);
	else Add(rs[c],mid+1,se,qi,val);
}
void Del(int c, int ss, int se, int qi, int val)
{
	node[c].erase(node[c].find(val));
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Del(ls[c],ss,mid,qi,val);
	else Del(rs[c],mid+1,se,qi,val);
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int GetMin(int c, int ss, int se, int qs, int qe, int k)
{
	if(qs>se || ss>qe || qs>qe) return inf;
	if(qs<=ss && qe>=se)
	{
		it=node[c].lower_bound(k);
		if(it==node[c].end()) return inf;
		else return *it;
	}
	int mid=ss+se>>1;
	return min(GetMin(ls[c],ss,mid,qs,qe,k),GetMin(rs[c],mid+1,se,qs,qe,k));
}
int GetMax(int c, int ss, int se, int qs, int qe, int k)
{
	if(qs>se || ss>qe || qs>qe) return 0;
	if(qs<=ss && qe>=se)
	{
		it=node[c].upper_bound(k);
		if(it!=node[c].begin()){ it--;return *it;}
		else return 0;
	}
	int mid=ss+se>>1;
	return max(GetMax(ls[c],ss,mid,qs,qe,k),GetMax(rs[c],mid+1,se,qs,qe,k));
}
multiset<int> parsz;
int sz[N],lid[N],rid[N],tid,n,r,sol[N];
vector<int> E[N];
void DFSID(int u){ lid[u]=++tid;sz[u]=1;for(int i=0;i<E[u].size();i++) DFSID(E[u][i]),sz[u]+=sz[E[u][i]];rid[u]=tid;Add(root,1,N,lid[u],sz[u]);}
void DFS(int u)
{
	Del(root,1,N,lid[u],sz[u]);
	vector<pair<int,int> > ch;
	int i;
	for(i=0;i<E[u].size();i++) ch.pb(mp(sz[E[u][i]],E[u][i]));
	sort(ch.rbegin(),ch.rend());
	int Max,Min,sec,add,need,v;
	if(ch.empty()) sol[u]=n-1;
	else if(u==r && ch.size()<=1) sol[u]=n-1;
	else if(u==r)
	{
		Max=ch[0].first;
		sec=ch[1].first;
		if(Max==sec) sol[u]=Max;
		else
		{
			Min=ch.back().first;
			v=ch[0].second;
			need=(Max-Min)/2;
			add=GetMin(root,1,N,lid[v],rid[v],need+1);
			sol[u]=max(Max-add,Min+add);
			add=GetMax(root,1,N,lid[v],rid[v],need);
			sol[u]=min(sol[u],max(Min+add,Max-add));
			if(ch.size()>2 && sol[u]<sec) sol[u]=sec;
		}
	}
	else if(ch.size())
	{
		if(ch[0].first<n-sz[u])
		{
			Max=n-sz[u];
			sec=ch[0].first;
			Min=ch.back().first;
			need=(Max-Min)/2+1;
			add=min(GetMin(root,1,N,1,lid[u]-1,need),GetMin(root,1,N,rid[u]+1,N,need));
			it=parsz.lower_bound(need+sz[u]);if(it!=parsz.end()) add=min(add,*it-sz[u]);
			sol[u]=max(Min+add,Max-add);
			need--;
			add=max(GetMax(root,1,N,1,lid[u]-1,need),GetMax(root,1,N,rid[u]+1,N,need));
			it=parsz.upper_bound(need+sz[u]);if(it!=parsz.begin()){ it--;add=max(add,*it-sz[u]);}
			sol[u]=min(sol[u],max(Min+add,Max-add));
			if(ch.size()>1 && sol[u]<sec) sol[u]=sec;
		}
		else if(ch[0].first>n-sz[u])
		{
			Max=ch[0].first;
			if(ch.size()==1 || ch[1].first<n-sz[u]) sec=n-sz[u];
			else sec=ch[1].first;
			Min=min(n-sz[u],ch.back().first);
			v=ch[0].second;
			if(Max==sec) sol[u]=Max;
			else
			{
				need=(Max-Min)/2;
				add=GetMin(root,1,N,lid[v],rid[v],need+1);
				sol[u]=max(Max-add,Min+add);
				add=GetMax(root,1,N,lid[v],rid[v],need);
				sol[u]=min(sol[u],max(Max-add,Min+add));
				if(ch.size()>1 && sol[u]<sec) sol[u]=sec;
			}
		}
		else sol[u]=n-sz[u];
	}
	else sol[u]=n-1;
	parsz.insert(sz[u]);
	for(i=0;i<E[u].size();i++) DFS(E[u][i]);
	parsz.erase(parsz.find(sz[u]));
	Add(root,1,N,lid[u],sz[u]);
}
int main()
{
	int u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&u,&v);
		if(!u) r=v;
		else E[u].pb(v);
	}
	DFSID(r);
	DFS(r);
	for(i=1;i<=n;i++) printf("%i\n",sol[i]);
	return 0;
}