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
int n,m;
char s[2333][2333];
int g[2333][2333];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	memset(g,127/3,sizeof g);
	g[1][0]=0;
	vector<pii> v; int sb=1;
	v.pb(pii(0,1));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			g[i][j]=min(g[i][j-1],g[i-1][j])
			+(s[i][j]!='a');
			if(g[i][j]<=m)
			{
				if(i+j>sb)
					sb=i+j,v.clear();
				if(i+j==sb)
					v.pb(pii(i,j));
			}
		}
	int u=n+n-1;
	for(int i=1;i<=sb-1;++i)
		--u,putchar('a');
	vector<pii> ss;
	for(auto t:v) ss.pb(t);
	while(u--)
	{
		int mi='z'; vector<pii> ns;
		for(auto t:ss)
		{
			pii w(t.fi,t.se+1);
			if(islower(s[w.fi][w.se]))
			{
				if(s[w.fi][w.se]<mi)
					ns.clear(),mi=s[w.fi][w.se];
				if(s[w.fi][w.se]==mi)
					ns.pb(w);
			}
			w=pii(t.fi+1,t.se);
			if(islower(s[w.fi][w.se]))
			{
				if(s[w.fi][w.se]<mi)
					ns.clear(),mi=s[w.fi][w.se];
				if(s[w.fi][w.se]==mi)
					ns.pb(w);
			}
		}
		sort(ns.begin(),ns.end());
		ns.erase(unique(ns.begin(),ns.end()),ns.end());
		putchar(mi);
		ss=ns;
	}
}