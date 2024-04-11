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
const int inf=2.01e9;
int n,p,s[SZ],len[SZ],t[SZ],id[SZ];
int f[1<<22]; pii so[1<<22],rs[SZ];
vector<int> ve,v2;
bool by_s(int a,int b) {return s[a]<s[b];}
bool by_t(int a,int b) {return t[a]<t[b];}
void prt(int g,int t)
{
	if(!g) return;
	int s=so[g].se;
	rs[s]=pii(t,so[g].fi);
	prt(g^(1<<s),t);
}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;++i)
		scanf("%d%d%d",s+i,len+i,t+i),
		ve.pb(i),v2.pb(i);
	sort(ve.begin(),ve.end(),by_s);
	sort(v2.begin(),v2.end(),by_t);
	for(int i=0;i<(1<<n);++i) f[i]=inf;
	f[0]=1;
	for(int i=0;i<(1<<n);++i) if(f[i]!=inf)
	{
	int _=0,g=f[i];
	for(auto t:v2) if(!(i&(1<<t)))
	{
		for(;_<int(ve.size());++_)
		{
			int j=ve[_];
			if(g+::t[t]<s[j]) break;
			if(i&(1<<j))
			{
				if(g<s[j]+len[j]) g=s[j]+len[j];
			}
			else if(g>=s[j]&&g<s[j]+len[j]) g=s[j]+len[j];
		}
		if(g+::t[t]>=s[t]) continue;
		int w=g+::t[t];
		if(w>=f[i^(1<<t)]) continue;
		f[i^(1<<t)]=w;
		so[i^(1<<t)]=pii(g,t);
	}
	}
	if(p==1)
	{
		if(f[(1<<n)-1]>=inf)
		{
			puts("NO");
			return 0;
		}
		puts("YES");
		prt((1<<n)-1,1);
		for(int i=0;i<n;++i)
			printf("%d %d\n",rs[i].fi,rs[i].se);
		return 0;
	}
	int g=-1;
	for(int i=0;i<(1<<n);++i)
		if(f[i]<inf&&f[((1<<n)-1)^i]<inf) g=i;
	if(g==-1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	prt(g,1); prt(((1<<n)-1)^g,2);
	for(int i=0;i<n;++i)
		printf("%d %d\n",rs[i].fi,rs[i].se);
}