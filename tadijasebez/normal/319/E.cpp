#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=32*N*4;
const int lim=1e9+7;
struct DSU
{
	int p[N],l[N],r[N];
	void init(){ for(int i=0;i<N;i++) p[i]=i,l[i]=lim,r[i]=-lim;}
	DSU(){ init();}
	int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
	void Union(int x, int y)
	{
        x=Find(x);y=Find(y);
        if(x==y) return;
        p[y]=x;
        l[x]=min(l[x],l[y]);
        r[x]=max(r[x],r[y]);
	}
} DS;
int ls[M],rs[M],tsz,root,bl[N],br[N];
vector<int> all[M];
void Add(int &c, int ss, int se, int qs, int qe, int id)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ all[c].pb(id);return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,id);
	Add(rs[c],mid+1,se,qs,qe,id);
}
void Take(int &c, int ss, int se, int qi, int id)
{
	if(!c) return;
	for(int i:all[c]) DS.Union(id,i);
	all[c].clear();
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Take(ls[c],ss,mid,qi,id);
	else Take(rs[c],mid+1,se,qi,id);
}
int main()
{
	int n,i,l,r,t,x,y,m=0,p;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&l,&r);
			m++;DS.l[m]=l;DS.r[m]=r;bl[m]=l;br[m]=r;
			Take(root,-lim,lim,l,m);
			Take(root,-lim,lim,r,m);
			p=DS.Find(m);
			Add(root,-lim,lim,DS.l[p]+1,DS.r[p]-1,p);
		}
		else
		{
			scanf("%i %i",&x,&y);x=DS.Find(x);y=DS.Find(y);
			if(x==y || (DS.l[x]>=DS.l[y] && DS.r[x]<=DS.r[y])) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}