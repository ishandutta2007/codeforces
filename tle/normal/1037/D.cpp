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
int n,a[SZ],od[SZ];
vector<int> adj[SZ];
bool by_od(int x,int y)
{return od[x]<od[y];}
int qs[SZ],h=0,t=0;
bool vis[SZ];
void bfs(int x)
{
	qs[t++]=x; vis[x]=1;
	while(h^t)
	{
		x=qs[h++];
		for(auto b:adj[x]) if(!vis[b])
			vis[b]=1,qs[t++]=b;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),
		adj[a].pb(b),
		adj[b].pb(a);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),od[a[i]]=i;
	if(a[1]!=1)
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;++i)
		sort(adj[i].begin(),adj[i].end(),by_od);
	bfs(a[1]);
	for(int i=0;i<t;++i)
		if(qs[i]!=a[i+1])
		{
			puts("No");
			return 0;
		}
	puts("Yes");
}