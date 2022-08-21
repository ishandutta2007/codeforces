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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,m,s[SZ]; Edg
vector<int> cs[SZ];
pair<pii,int> maxn[SZ];
int tmp[SZ],col[SZ];
void dfs(int x,int f=0)
{
	for(auto g:cs[x]) if(col[g]) tmp[col[g]]=x;
	int j=1;
	for(auto g:cs[x]) if(!col[g])
	{
		while(tmp[j]==x) ++j; col[g]=j++;
	}
	for esb(x,e,b) if(b!=f) dfs(b,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	int mi=-1,id=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		for(int j=1;j<=s[i];j++)
		{
			int x; scanf("%d",&x);
			cs[i].pb(x);
		} if(s[i]>mi) mi=s[i],id=i;
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b);
	}
	dfs(id);
	int mx=0;
	for(int i=1;i<=m;i++)
	{
		if(!col[i]) col[i]=1;
		mx=max(mx,col[i]);
	}
	printf("%d\n",mx);
	for(int i=1;i<=m;i++) printf("%d ",col[i]);
}