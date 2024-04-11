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
#define SZ 2333333
Edg
int vis[SZ],n,m,os[SZ],on,l[SZ],r[SZ];
bool cho[SZ],gg[SZ];
void mark(int x)
{r[l[x]]=r[x]; l[r[x]]=l[x];}
void dfs(int x)
{
	mark(x), vis[x]=x;
	for esb(x,e,b) if(!vis[b])
		mark(b), vis[b]=x;
	while(r[0]<=n) dfs(r[0]);
	if(gg[x]) return;
	for esb(x,e,b) if(cho[b]) return;
	cho[x]=1;
	for esb(x,e,b) gg[b]=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),ad_de(a,b);
	for(int i=1;i<=n+1;++i)
		r[i-1]=i,l[i]=i-1;
	dfs(1);
	for(int i=1;i<=n;++i)
		if(cho[i]) os[++on]=i;
	printf("%d\n",on);
	for(int i=1;i<=on;++i)
		printf("%d " ,os[i]);
}