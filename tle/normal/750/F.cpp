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
vector<int> adj[SZ];
int n,h,ans=0;
void upd(int x)
{
	if(adj[x].size()||ans) return;
	printf("? %d\n",x);
	fflush(stdout);
	int k; scanf("%d",&k);
	if(k==2) ans=x;
	adj[x].resize(k);
	for(int i=0;i<k;i++)
		scanf("%d",&adj[x][i]);
}
void prt(int x=ans)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int dis[SZ],dir[SZ],fa[SZ];
bool leaf[SZ];
int qs[SZ];
int fa_1() //what's the *real* father of 1?
{
	upd(1);
	if(adj[1].size()==2)
		return 0;
	if(adj[1].size()==1)
		return adj[1][0];
	int l=1,r=1,tot=0; qs[r++]=1;
	while(l^r)
	{
		int x=qs[l++];
		if(leaf[dir[x]]) continue;
		upd(x);
		for(int b:adj[x])
		{
			if(b==fa[x]) continue;
			fa[b]=x; dis[b]=dis[x]+1;
			if(x==1) dir[b]=b;
			else dir[b]=dir[x];
			if(!leaf[dir[b]])
			{
				upd(b);
				if(ans) return 233;
				if(adj[b].size()==1)
					leaf[dir[b]]=1, ++tot;
				if(dis[b]<3) qs[r++]=b;
			}
		}
		if(tot==2) break; //???
	}
	for(int a:adj[1])
	{
		if(!leaf[a]) return a;
	}
	return 0;
}
bool chk(int x,int f,int z)
{
	upd(x);
	if(adj[x].size()==1) return 0;
	if(!z) return 1;
	for(int b:adj[x])
	{
		if(b!=f) return chk(b,x,z-1);
		//every direction is the same
	}
}
int ss[SZ],sn=0;
void push(int x,int f,int dep)
{
	if(!dep) {ss[++sn]=x; return;}
	upd(x);
	for(auto b:adj[x])
		if(b!=f) push(b,x,dep-1);
}
#define clr(x) memset(x,0,sizeof(x))
void sol()
{
	scanf("%d",&h); n=(1<<h)-1;
	ans=0; for(int i=1;i<=n;i++) adj[i].clear();
	clr(dis); clr(fa); clr(leaf); clr(dir);
	int fa1=fa_1();
	if(ans) {prt(); return;}
	int dep=0; //actual deep of 1
	for(int i=1;i<=n;i++)
		if(leaf[dir[i]]) dep=max(dep,dis[i]);
	dep=h-dep; //deep to climb
	int cur=1,bk=1;
	if(dep>3)
	{
		cur=fa1;
		while(--dep>3)
		{
			upd(cur);
			vector<int> tmp=adj[cur];
			tmp.erase(find(tmp.begin(),tmp.end(),bk));
			int fa=tmp[0];
			if(!chk(fa,cur,h-dep-1)) fa=tmp[1];
			bk=cur; cur=fa;
		}
	}
	sn=0; push(cur,bk,2);
	for(int i=1;i<sn;i++) upd(ss[i]);
	if(!ans) ans=ss[sn];
	prt();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) sol();
}