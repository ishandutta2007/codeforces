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
#define SZ 5800999
char s[109999]; int n;
vector<int> ap[26],qz[26];
pair<pii,pii> qs[SZ]; int qn=0;
bool cmp(pair<pii,pii> a,pair<pii,pii> b)
{
	if(a.fi.se!=b.fi.se) return a.fi.se<b.fi.se;
	return a.fi.fi>b.fi.fi;
}
int nx[109999][26],pv[100099][26],
ps[109999],ts[109999],tl[26][109999],tr[26][109999];
int gans(pii t)
{
	if(t.fi>t.se) return 0;
	int u=0;
	for(int i=0;i<26;++i)
	{
		int b=pv[t.se][i];
		if(ap[i][b]<t.fi) continue;
		int a=nx[t.fi][i];
		u|=1<<(tl[i][t.fi]^tr[i][t.se]
		^qz[i][b-1]^qz[i][a-1]);
	}
	int g=0;
	while(u&(1<<g)) ++g;
	return g;
}
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=0;i<26;++i) ap[i].pb(0);
	for(int i=1;i<=n;++i)
		ps[i]=ap[s[i]-'a'].size(),
		ap[s[i]-'a'].pb(i);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j) pv[i][j]=pv[i-1][j];
		pv[i][s[i]-'a']=ps[i];
	}
	for(int j=0;j<26;++j) nx[n+1][j]=1e9;
	for(int i=n;i>=1;--i)
	{
		for(int j=0;j<26;++j) nx[i][j]=nx[i+1][j];
		nx[i][s[i]-'a']=ps[i];
	}
	for(int i=0;i<26;++i)
	{
		qz[i].pb(0);
		for(int j=1;j+1u<ap[i].size();++j)
			qs[++qn]=mp(pii(ap[i][j]+1,ap[i][j+1]-1),pii(i,j));
		for(int j=1;j<=n;++j)
		{
			int u=pv[j][i];
			if(u)
				qs[++qn]=mp(pii(ap[i][u]+1,j),pii(-j,i*2));
		}
		for(int j=1;j<=n;++j)
		{
			int u=nx[j][i];
			if(u<=n)
				qs[++qn]=mp(pii(j,ap[i][u]-1),pii(-j,i*2+1));
		}
	}
	sort(qs+1,qs+1+qn,cmp);
	for(int i=1;i<=qn;++i)
	{
		int w=gans(qs[i].fi),u=qs[i].se.fi;
		if(u>=0)
			qz[u].pb(qz[u].back()^w);
		else
		{
			if(qs[i].se.se&1)
				tl[qs[i].se.se>>1][-u]=w;
			else tr[qs[i].se.se>>1][-u]=w;
		}
	}
	int T,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		if(gans(pii(l,r))) puts("Alice");
		else puts("Bob");
	}
}