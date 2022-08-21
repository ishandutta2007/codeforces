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
int n,p[SZ],pv[SZ],nx[SZ];
char c[SZ]; ll ans=0,tt[SZ]; map<int,int> pp;
vector<int> dd[SZ],aa;
void solve(char s)
{
	for(int i=0;i<=n+2;++i) dd[i].clear();
	for(int i=1;i<=n;++i) if(c[i]==s)
	{
		auto g=pp.lower_bound(p[i]); --g;
		dd[g->se].pb(p[i]);
	}
	for(int i=0;i<aa.size()-1;++i) if(dd[i].size())
	{
		if(aa.size()==2)
			ans+=dd[i].back()-dd[i].front();
		else
		{
		vector<ll> aaa;
		aaa.pb(dd[i][0]-(ll)aa[i]);
		aaa.pb(aa[i+1]-(ll)dd[i].back());
		for(int j=0;j+1<dd[i].size();++j)
			aaa.pb(dd[i][j+1]-dd[i][j]);
		sort(aaa.begin(),aaa.end());
		for(int _=0;_+1<aaa.size();++_) tt[i]+=aaa[_];
		}
	}
}
int ii=2.05e9;
set<int> gg[333];
int main()
{
	scanf("%d",&n);
	aa.pb(-ii); pp[-ii]=0;
	int ls=-1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%s",p+i,c+i);
		gg[c[i]].insert(p[i]);
		if(c[i]=='G')
		{
			aa.pb(p[i]); pp[p[i]]=aa.size()-1;
			if(ls!=-1) ans+=p[i]-ls;
			ls=p[i];
		}
	}
	aa.pb(ii); pp[ii]=aa.size()-1;
	solve('B'); solve('R');
	for(int i=0;i+1<aa.size();++i)
		ans+=min(aa[i+1]-(ll)aa[i],tt[i]);
	if(0)//aa.size()==2&&gg['R'].size()&&gg['B'].size())
	{
		//connect R&B
		int mi=2e9; auto&b=gg['B'];
		for(auto t:gg['R'])
		{
			auto a=b.lower_bound(t);
			if(a!=b.end()) mi=min(mi,*a-t);
			if(a!=b.begin()) mi=min(mi,t-*(--a));
		}
		ans+=mi;
	}
	printf("%lld\n",ans);
}