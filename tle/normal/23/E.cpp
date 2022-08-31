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
int n,sz[777]; Edg
typedef pair<ld,int> F;
F dp[777][777],fs[777][777],tmp[777];
ld lg[777];
vector<F*> ds[777];
vector<int> son[777];
#define DP(c) ds[c][ds[c].size()-1]
void dfs(int x,int f=0)
{
	ds[x].pb(dp[x]);
	for esb(x,e,c) if(c!=f) ds[x].pb(fs[c]);
	int t=0; ds[x][t][1]=make_pair(0.0,0); sz[x]=1;
	for esb(x,e,c) if(c!=f)
	{
		dfs(c,x); son[x].pb(c); F*tmp=ds[x][t+1];
		for(int a=1;a<=sz[x]+sz[c];++a) tmp[a]=make_pair(-1e233,0);
		for(int a=1;a<=sz[x];++a)
			for(int b=1;b<=sz[c];++b)
				tmp[a+b]=max(tmp[a+b],
				make_pair(ds[x][t][a].fi+DP(c)[b].fi-lg[a]-lg[b]+lg[a+b],b*2));
		for(int a=1;a<=sz[x];++a)
			for(int b=1;b<=sz[c];++b)
				tmp[a]=max(tmp[a],make_pair(ds[x][t][a].fi+DP(c)[b].fi,b*2+1));
		for(int a=1;a<=sz[x]+sz[c];++a)
			dp[x][a]=tmp[a];
		sz[x]+=sz[c]; ++t;
	}
}
int ff[SZ],ss[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void dfs2(int x,int w)
{
	reverse(son[x].begin(),son[x].end());
	int g=ds[x].size()-1;
	for(int i=0;i<son[x].size();++i)
	{
		int c=son[x][i],gg=ds[x][g--][w].se;
		dfs2(c,gg/2);
		if(!(gg&1)) w-=gg/2,ff[c]=x;
	}
}
#define SZ 1000
ll s[SZ];
int main()
{
	memset(dp,-127/3,sizeof dp);
//	n=700;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) lg[i]=log(i);
	for(int i=2,a,b;i<=n;++i)
//		a=rand()%(i-1)+1,b=i,
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1); pair<ld,int> ma(-1e233,0);
	for(int i=1;i<=n;++i)
		ma=max(ma,make_pair(DP(1)[i].fi,i));
	dfs2(1,ma.se);
	for(int i=1;i<=n;++i) ++ss[gf(i)];
	s[0]=1;
	for(int i=1;i<=n;++i)
	{
		if(!ss[i]) continue;
		for(int j=0;j<SZ;++j) s[j]*=ss[i];
		for(int j=0;j+1<SZ;++j)
			s[j+1]+=s[j]/10,s[j]%=10;
	}
	int g=SZ-1; while(!s[g]) --g;
	while(~g) putchar(s[g--]+48);
}