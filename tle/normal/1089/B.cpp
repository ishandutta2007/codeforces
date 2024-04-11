#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n;
Edg
vector<int> rp[SZ]; //root-path
int mat[SZ],dep[SZ],qs[SZ],h,t;
//mat[x]=-1: x is erased
//dep=-1 unvisited  0 even  1 odd
//only even points are inqueue
#define link(a,b) mat[a]=b, mat[b]=a
void mark(int x,int y,int b)
{
	for(int i=b+1;i<rp[x].size();i++)
	{
		int z=rp[x][i];
		if(dep[z]!=1) continue;
		rp[z]=rp[y];
		rp[z].insert(rp[z].end(),rp[x].rbegin(),rp[x].rend()-i);
		dep[z]=0; qs[t++]=z;
	}
}
bool bfs(int s)
{
	h=0, t=0; qs[t++]=s;
	for(int i=1;i<=n;i++)
		rp[i].clear(), dep[i]=-1;
	rp[s].pb(s); dep[s]=0;
	while(h^t)
	{
		int x=qs[h++];
		for esb(x,e,b) if(mat[b]>=0)
		{
			if(dep[b]==-1)
			{
				if(!mat[b])
				{
					vector<int>& g=rp[x];
					for(int i=0;i+1<g.size();i+=2)
						link(g[i],g[i+1]);
					link(x,b);
					return 1;
				}
				else
				{
					int z=mat[b]; rp[z]=rp[x];
					rp[z].pb(b); rp[z].pb(z);
					dep[b]=1; dep[z]=0; qs[t++]=z;
				}
			}
			else if(!dep[b])
			{
				int lc=0;
				while(lc<rp[x].size()&&lc<rp[b].size()
				&&rp[x][lc]==rp[b][lc]) ++lc; --lc;
				mark(x,b,lc); mark(b,x,lc);
			}
		}
	}
	return 0;
}
int match()
{
	int c=0;
	for(int i=1;i<=n;i++) mat[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(mat[i]!=0) continue;
		if(bfs(i)) ++c; else mat[i]=-1;
	}
	return c;
}
void clr()
{
	M=0;
	for(int i=0;i<=n;++i)
		mat[i]=dep[i]=qs[i]=fst[i]=0,rp[i].clear();
}
int T,a,b;
char g[2333];
void sol()
{
	scanf("%d%d",&a,&b);
	n=a+a+b;
	for(int x=1;x<=a;++x)
	{
		scanf("%s",g+1);
		adde(x,x+a);
		for(int y=1;y<=b;++y) if(g[y]=='1')
			adde(x,y+a+a),
			adde(x+a,y+a+a);
	}
	printf("%d\n",match()-a);
	clr();
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}