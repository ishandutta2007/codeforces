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
#define SZ 1234567
int k,n,m,ea[SZ],eb[SZ],te[SZ],fa[SZ]; Edgc
bool vis[SZ];
int dep[SZ];
bool nl[SZ];
void dfs(int x)
{
	vis[x]=1; nl[fa[x]]=1;
	for esb(x,e,b) if(!vis[b])
		dep[b]=dep[x]+1,fa[b]=x,
		te[vc[e]]=1,dfs(b);
}
vector<int> sb[SZ];
vector<int> gc(int x,int f)
{
	vector<int> v;
	while(x!=f) v.pb(x),x=fa[x];
	v.pb(f); return v;
}
map<pii,int> edg;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),
		ea[i]=a,eb[i]=b,adde(a,b,i),
		edg[pii(a,b)]=edg[pii(b,a)]=1;
	dep[1]=1; dfs(1);
	for(int i=1;i<=n;++i)
		if(dep[i]*(ll)k>=n)
		{
			vector<int> s=gc(i,1);
			puts("PATH");
			printf("%d\n",int(s.size()));
			if(int(s.size())*(ll)k<n) throw "GG";
			for(int j=0;j+1<int(s.size());++j)
				if(!edg.count(pii(s[j],s[j+1]))) throw "GG";
			for(auto x:s) printf("%d ",x);
			exit(0);
		}
	for(int i=1;i<=m;++i)
		if(!te[i])
		{
			if(dep[ea[i]]<dep[eb[i]])
				swap(ea[i],eb[i]);
			sb[ea[i]].pb(eb[i]);
		}
	vector<vector<int> > vs;
	for(int i=1;i<=n;++i) if(sb[i].size()>=2&&!nl[i])
	{
		int a=sb[i][0],b=sb[i][1];
		if(dep[a]<dep[b]) swap(a,b);
		//i--a--b
		if((dep[i]-dep[a]+1)%3)
			vs.pb(gc(i,a));
		else if((dep[i]-dep[b]+1)%3)
			vs.pb(gc(i,b));
		else
		{
			vector<int> w=gc(a,b); w.pb(i);
			reverse(w.begin(),w.end());
			vs.pb(w);
		}
		if(vs.size()>=k) break;
	}
//	cerr<<vs.size()<<"?\n";
	puts("CYCLES");
	for(auto t:vs)
	{
		printf("%d\n",int(t.size()));
		for(auto x:t)
			printf("%d ",x);
		puts("");
	}
}
//wth is wrong with this?