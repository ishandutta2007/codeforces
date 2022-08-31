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
#define SZ 1234567
int e[SZ],n; ll k,a[SZ];
ll x[SZ],y[SZ]; int u=0;
void facc(ll s)
{
	for(ll p=2;p*p<=s;++p) if(s%p==0)
	{
		x[u]=p;
		while(s%p==0) s/=p,++y[u];
		++u;
	}
	if(s>1) x[u]=s,y[u]=1,++u;
}
ll mi[1<<14][14];
int ok[1<<14];
map<ll,vector<int> > mm;
int main()
{
	memset(mi,127/3,sizeof mi);
	scanf("%d%lld",&n,&k); ll g=0;
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i),g=__gcd(g,a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",e+i);
	facc(g);
	for(int i=1;i<=n;++i)
	{
		ll p=1;
		for(int j=0;j<u;++j)
			while(a[i]%x[j]==0) a[i]/=x[j],p*=x[j];
		mm[p].pb(e[i]);	
	}
	mi[0][0]=0;
	const ll inf=2e18;
	for(auto&s:mm)
	{
		sort(s.se.begin(),s.se.end());
		if(s.se.size()>u) s.se.resize(u);
		ll x=s.fi;
		vector<int> oa;
		for(int i=0;i<(1<<u);++i)
		{
			ll y=x,z=1;
			for(int j=0;j<u;++j) if(i&(1<<j))
			{
				while(y% ::x[j]==0) y/=::x[j],z*=::x[j];
			}
			ok[i]=(z<=k);
			if(z<=k) oa.pb(i);
		}
		for(auto ss:s.se)
		{
			bool up=0;
			for(int i=u-1;i>=0;--i)
				for(auto a:oa)
				{
					int b=((1<<u)-1)^a;
					for(int z=b;;z=(z-1)&b)
					{
						ll u=mi[z][i]+ss;
						if(u<mi[a^z][i+1])
							mi[a^z][i+1]=u,up=1;
						if(!z) break;
					}
				}
			if(!up) break;
		}
	}
	ll ans=8e18;
	for(int i=0;i<=u;++i)
		if(mi[(1<<u)-1][i]<inf)
			ans=min(ans,mi[(1<<u)-1][i]*i);
	if(ans>=inf) ans=-1;
	cout<<ans<<"\n";
}