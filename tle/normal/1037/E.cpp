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
#define SZ 888888
int n,m,k,ea[SZ],eb[SZ],cho[SZ],deg[SZ],ans,oo[SZ];
set<int> adj[209999];
int qs[SZ],h=0,t=0;
void chk(int x)
{
	if(deg[x]<k) qs[t++]=x;
}
int py()
{
	while(h^t)
	{
		int x=qs[h++];
		if(!cho[x]) continue;
		cho[x]=0; --ans;
		for(auto u:adj[x]) if(cho[u])
			--deg[u],chk(u);
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
		scanf("%d%d",ea+i,eb+i),
		adj[ea[i]].insert(eb[i]),
		adj[eb[i]].insert(ea[i]);
	for(int i=1;i<=n;++i)
		cho[i]=1,deg[i]=adj[i].size();
	ans=n;
	for(int i=1;i<=n;++i) chk(i);
	for(int i=m;i>=1;--i)
	{
		oo[i]=py();
		if(cho[ea[i]]&&cho[eb[i]])
		{
			--deg[ea[i]],--deg[eb[i]];
			chk(ea[i]); chk(eb[i]);
		}
		adj[ea[i]].erase(eb[i]),
		adj[eb[i]].erase(ea[i]);
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",oo[i]);
}