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
#include <assert.h>
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
int n,p[SZ],d[SZ],w[SZ];
vector<int> ch[SZ];
int ss[SZ],sn;
int ts[SZ],tn;
int main()
{
	scanf("%d",&n);
	pii md(0,0);
	for(int i=1;i<n;++i)
		scanf("%d",p+i),
		d[i]=d[p[i]]+1,
		ch[p[i]].pb(i),
		md=max(md,pii(d[i],i));
	for(int g=md.se;;g=p[g])
	{
		ss[++sn]=g; w[g]=1;
		if(g==0) break;
	}
	for(int g=md.se;;g=p[g])
	{
		sort(ch[g].begin(),ch[g].end(),[&](int p,int q)
		{
			return w[p]<w[q];
		});
		if(g==0) break;
	}
	int g=0;
	while(ch[g].size())
	{
		if(ch[g].size()==1)
		{
			g=ch[g].back();
			continue;
		}
		int u=ch[g].back();
		ch[g].pop_back();
		ts[++tn]=u;
		int v=ch[g].back();
		p[u]=v; ch[v].pb(u);
	}
	vector<int> op;
	for(int w=0;;)
	{
		op.pb(w);
		if(!ch[w].size()) break;
		w=ch[w][0];
	}
	for(auto p:op) printf("%d ",p);
	puts("");
	printf("%d\n",n-1-md.fi);
	while(tn)
		printf("%d ",ts[tn--]);
}