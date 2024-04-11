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
#define SZ 233333
#define D 20
int n,fst[SZ],nxt[SZ],vb[SZ],fa[SZ],up[SZ][D],dep[SZ],M=0,dfsn[SZ],C=0,sz[SZ];
void ad_de(int a,int b) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
void dfs(int p)
{
    dfsn[p]=++C; sz[p]=1;
    for(int e=fst[p];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[p]) continue;
        fa[b]=up[b][0]=p; dep[b]=dep[p]+1;
        dfs(b); sz[p]+=sz[b];
    }
}
void pree()
{
    dfs(1);
    for(int g=1;g<D;g++)
    {
        for(int i=1;i<=n;i++)
        {
            if(up[i][g-1]) up[i][g]=up[up[i][g-1]][g-1];
        }
    }
}
//jump up (x=fa[x]) until dep[x]=d
int jmp(int x,int d)
{
    for(int i=D-1;i>=0;i--)
        if(!up[x][i]||dep[up[x][i]]<d);else x=up[x][i];
    return x;
}
int lca(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    y=jmp(y,dep[x]);
    if(x==y) return x;
    for(int i=D-1;i>=0;i--)
        if(up[x][i]!=up[y][i]) x=up[x][i], y=up[y][i];
    return fa[x];
}
int m,q[SZ];
typedef pair<int,int> pii;
int sn,ss[SZ],vn,vs[SZ],stn=0,st[SZ],vfa[SZ];
bool cmp_dfsn(int a,int b) {return dfsn[a]<dfsn[b];}
void build()
{
    vn=stn=0;
    sort(ss+1,ss+1+sn,cmp_dfsn);
    sn=unique(ss+1,ss+1+sn)-ss-1;
    for(int i=1;i<=sn;i++) vs[++vn]=ss[i];
    for(int i=1;i<=sn;i++)
    {
        int x=ss[i];
        if(!stn) {st[++stn]=x; vfa[x]=0; continue;}
        int lca=::lca(x,st[stn]);
        for(;dep[st[stn]]>dep[lca];--stn)
        {
            if(dep[st[stn-1]]<=dep[lca]) vfa[st[stn]]=lca; 
        }
        if(st[stn]!=lca)
        {
            vs[++vn]=lca;
            vfa[lca]=st[stn];
            st[++stn]=lca;
        }
        vfa[x]=lca; st[++stn]=x;
    }
}
map<int,int> rs[SZ];
int t[SZ],mv[SZ],qr[SZ],sub[SZ],vv[SZ],p[SZ],dt[SZ];
map<int,int>::iterator cp[SZ];
bool in_blk[SZ],out[SZ];
int ca=0;
void ddd(int x)
{
	sub[x]=mv[x];
	for esb(x,e,b)
		ddd(b), sub[x]+=sub[b];
	vv[x]=t[x]+sub[x];
	if(!in_blk[x]&&!out[x]) ca+=vv[x]<0;
}
vector<int> cur_blk;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i)
		scanf("%d",p+i),ad_de(p[i],i);
	for(int i=1;i<=n;++i)
		scanf("%d",t+i);
	pree();
	int le=0,S=600;
	for(int i=1;i<=m;++i) scanf("%d",qr+i);
	ddd(1);
	for(int i=1;i<=m;++i)
	{
		if((i-1)%S==0)
		{
			for(int j=1;j<=vn;++j)
				rs[vs[j]].clear();
			for(int j=1;j<=n;++j) in_blk[j]=0;
			//try to build vtree
			sn=0; ss[++sn]=1; cur_blk.clear();
			for(int j=i;j<=i+S-1&&j<=m;++j)
			{
				int ww=abs(qr[j]);
				ss[++sn]=ww;
				if(!in_blk[ww]) cur_blk.pb(ww);
				in_blk[ww]=1;
			}
			ca=0; ddd(1);
			build();
			for(int j=1;j<=vn;++j)
			{
				dt[vs[j]]=0;
				rs[vs[j]].clear();
				for(int z=vs[j];z!=vfa[vs[j]];z=p[z])
					if(!in_blk[z]&&!out[z])
						++rs[vs[j]][vv[z]];
				rs[vs[j]][-233333]=0;
				rs[vs[j]][233333]=0;
				int su=0;
				for(auto&t:rs[vs[j]])
					su+=t.se,t.se=su;
				cp[vs[j]]=--rs[vs[j]].lower_bound(0);
//				cerr<<vs[j]<<"w:";
//				for(auto t:rs[vs[j]])
//					cerr<<t.fi<<','<<t.se<<" ";
//				cerr<<"==\n";
			}
//			cerr<<i<<"==\n";
//			for(int j=1;j<=n;++j)
//				cerr<<vv[j]<<","<<out[j]<<" ";
//			cerr<<"\n";
//		cerr<<ca<<"ww\n";
		}
//		cerr<<ca<<"BG\n";
		if(qr[i]<0)
		{
			int rr=abs(qr[i]);
			++mv[rr]; out[rr]^=1;
			for(int j=rr;j;j=vfa[j])
			{
//				cerr<<j<<"--"<<vfa[j]<<" old"<<cp[j]->se<<"s\n";
				++dt[j]; ca-=cp[j]->se;
				//dt[x]+val<=-1
				while(cp[j]->fi+dt[j]>=0) --cp[j];
				ca+=cp[j]->se;
//				cerr<<cp[j]->fi<<" "<<cp[j]->se<<"w"<<dt[j]<<"!!!\n";
			}
		}
		else
		{
			int rr=abs(qr[i]);
			--mv[rr]; out[rr]^=1;
			for(int j=rr;j;j=vfa[j])
			{
//				cerr<<j<<"--"<<vfa[j]<<" old"<<cp[j]->se<<"s\n";
				--dt[j]; ca-=cp[j]->se;
				//dt[x]+val<=-1
				while(1)
				{
					++cp[j];
					if(cp[j]!=rs[j].end()&&cp[j]->fi+dt[j]<0);
					else {--cp[j]; break;}
				}
//				cerr<<cp[j]->fi<<" "<<cp[j]->se<<"w"<<dt[j]<<"!!!\n";
				ca+=cp[j]->se;
			}
		}
//		cerr<<ca<<"ED\n";
		int cp=ca;
		for(auto s:cur_blk)
			if(!out[s])
//				cerr<<"Checked!"<<s<<" "<<(vv[s]+dt[s]<0)<<"\n",
				cp+=vv[s]+dt[s]<0;
		printf("%d ",cp);
	}
	cerr<<clock()<<"ms\n"; 
}