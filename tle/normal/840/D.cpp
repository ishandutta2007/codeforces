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
#include <unordered_map>
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
#define S 5
int tmp[SZ];
struct iff {vector<pii> ms;};
iff operator + (iff a,const iff& b)
{
	if(a.ms.size()||b.ms.size());else return a;
	static pii ps[13]; int pn=0;
	for(auto g:b.ms) tmp[g.se]=g.fi;
	for(auto g:a.ms) ps[++pn]=pii(g.fi+tmp[g.se],g.se),tmp[g.se]=0;
	for(auto g:b.ms)
		if(tmp[g.se])
		{
			if(pn<S)
			{
				ps[++pn]=pii(tmp[g.se],g.se);
				tmp[g.se]=0; continue;
			}
			int mi=1e9;
			for(int j=1;j<=pn;++j)
				mi=min(mi,ps[j].fi);
			if(mi>tmp[g.se])
			{
				for(int j=1;j<=pn;++j) ps[j].fi-=tmp[g.se];
				tmp[g.se]=0; continue;
			}
			static pii tt[13]; int tn=0;
			for(int j=1;j<=pn;++j)
			{
				if(ps[j].fi<=mi) continue;
				ps[j].fi-=mi; tt[++tn]=ps[j];
			}
			if(tmp[g.se]-mi)
			tt[++tn]=pii(tmp[g.se]-mi,g.se);
			pn=tn; for(int i=1;i<=pn;++i) ps[i]=tt[i];
			tmp[g.se]=0;
		}
	a.ms.clear();
	for(int i=1;i<=pn;++i)
		a.ms.pb(ps[i]);
	return a;
}
vector<int> app[300006];
int qry(int x,int l,int r)
{
	vector<int>&v=app[x];
	return lower_bound(v.begin(),v.end(),r+1)
	-lower_bound(v.begin(),v.end(),l);
}
int n,q,a[SZ];
const int M=524288;
iff seg[SZ];
iff qry(int l,int r)
{
	iff ans;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ans=ans+seg[l^1];
		if(r&1) ans=ans+seg[r^1];
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),app[a[i]].pb(i),
		seg[i+M].ms.pb(pii(1,a[i]));
	for(int i=M-1;i>=1;--i)
		seg[i]=seg[i+i]+seg[i+i+1];
	while(q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		ld ne=(r-l+1)/ld(k);
		iff s=qry(l,r);
		int ans=1e9;
		for(auto g:s.ms)
			if(g.se<ans&&qry(g.se,l,r)>ne)
				ans=g.se;
		if(ans>1e8) puts("-1");
		else printf("%d\n",ans);
	}
}