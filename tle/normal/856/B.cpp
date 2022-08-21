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
#define SZ 1234567
int T,n; char s[SZ];
int an=1,ch[SZ][26];
void ins(char* s)
{
	int cur=1;
	for(int i=0;s[i];++i)
	{
		int c=s[i]-'a';
		if(!ch[cur][c])
		{
			ch[cur][c]=++an;
			memset(ch[an],0,sizeof ch[0]);
		}
		cur=ch[cur][c];
	}
}
int fa[SZ];
vector<int> chs[SZ];
void dfs(int x,int g,int l=0)
{
	int gg=(g==1)?0:g;
	fa[x]=gg; if(gg) chs[gg].pb(x);
	for(int j=0;j<26;++j)
	{
		if(!ch[x][j]) continue;
		if(l) dfs(ch[x][j],ch[g][j],l+1);
		else dfs(ch[x][j],g,l+1);
	}
}
int f[SZ][2];
void dd(int x)
{
	f[x][0]=0; f[x][1]=1;
	for(auto b:chs[x])
	{
		dd(b); f[x][1]+=f[b][0];
		f[x][0]+=max(f[b][1],f[b][0]);
	}
}
void sol()
{
	scanf("%d",&n); an=1;
	memset(ch[1],0,sizeof ch[1]);
	for(int i=1;i<=n;++i)
		scanf("%s",s), ins(s);
	for(int i=1;i<=an;++i) fa[i]=0,chs[i].clear();
	dfs(1,1);
	int ans=0;
	for(int i=2;i<=an;++i) if(!fa[i])
		dd(i), ans+=max(f[i][0],f[i][1]);
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}