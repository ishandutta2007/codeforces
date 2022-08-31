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
#include <unordered_set>
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
int n,m;
Edg
unordered_set<ll> es;
inline bool he(int a,int b)
{
	if(a>b) swap(a,b);
	return es.count(a*555555LL+b);
}
int d[SZ],fm[SZ];
queue<int> qs;
void bfs(int r)
{
	for(int i=1;i<=n;++i) d[i]=1e9;
	d[r]=0; qs.push(r); fm[r]=-1;
	while(!qs.empty())
	{
		int x=qs.front(); qs.pop();
		for esb(x,e,b)
		{
			if(d[b]<=d[x]+1) continue;
			d[b]=d[x]+1; fm[b]=x; qs.push(b);
		}
	}
}
int deg[SZ],vis[SZ]; vector<int> ts;
void dfs(int x)
{
	vis[x]=1; ts.pb(x);
	for esb(x,e,b) if(b!=1)
	{
		++deg[b]; if(!vis[b]) dfs(b);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		es.insert(a*555555LL+b);
		adde(a,b);
	}
	bfs(1);
	int ans2=d[n];
	if(ans2<=4)
	{
		printf("%d\n",ans2);
		vector<int> v;
		int x=n;
		while(x!=1) v.pb(x),x=fm[x];
		v.pb(x); reverse(v.begin(),v.end());
		for(auto t:v) printf("%d ",t);
		puts(""); return 0;
	}
	for esb(1,e,b)
		for esb(b,ee,s)
			if(s!=1&&!he(1,s))
			{
				printf("4\n");
				printf("1 %d %d 1 %d\n",b,s,n);
				return 0;
			}
	for esb(1,e,b) if(!vis[b])
	{
		ts.clear(); dfs(b);
		int g=-1;
		for(auto p:ts)
			if(deg[p]+1!=ts.size()) {g=p; break;}
		if(g==-1) continue;
		for(auto r:ts)
			if(!he(g,r)&&r!=g)
			{
				for(auto h:ts)
				{
					if(h!=g&&h!=r&&he(g,h)&&he(h,r))
					{
						printf("5\n");
						printf("1 %d %d %d %d %d\n",g,h,r,g,n);
						return 0;
					}
				}
			}
	}
	puts("-1");
}