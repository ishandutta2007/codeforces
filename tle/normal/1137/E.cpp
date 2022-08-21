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
typedef long double ld;
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
typedef pair<ll,ll> pll;
//a.fi*x+a.se=b.fi*x+b.se
ld jd(pll a,pll b) {return (b.se-a.se)/ld(a.fi-b.fi);}
ll xd(pll a,pll b,pll c,pll d)
{return (b.se-a.se)*(long double)(d.fi-c.fi)
>=(d.se-c.se)*(long double)(b.fi-a.fi);}
pll ss[SZ]; int S=SZ/2,T=S-1;
int n,m; ll P=0,Q=0;
void ins_R(int x)
{
	pll u(x,-Q-x*P);
	while(S+1<=T&&xd(ss[S],ss[S+1],u,ss[S+1])) ++S;
	ss[--S]=u;
}
ll f(int x)
{
	return ss[x].fi*(ll)P+ss[x].se+Q;
}
int L,R;
void qry()
{
	int l=S,r=T;
	while(r-l>=15)
	{
		int m1=l+(r-l)/3,m2=r-(r-l)/3;
		ll f1=f(m1),f2=f(m2);
		if(f1<f2) r=m2; else l=m1;
	}
	pair<ll,ll> ans;
	ans.fi=8e18;
	for(int i=max(l-1,S);i<=min(r+1,T);++i)
		ans=min(ans,mp(f(i),ss[i].fi));
	printf("%lld %lld\n",ans.se-L+1,ans.fi);
}
int main()
{
	scanf("%d%d",&n,&m);
	S=SZ/2,T=S-1;
	L=1; R=n;
	ins_R(1);
	while(m--)
	{
		int o,a,b;
		scanf("%d%d",&o,&a);
		if(o==1)
		{
			Q+=a*(ll)P;
			S=SZ/2; T=S-1; L=1; R+=a;
			ins_R(1);
		}
		else if(o==2)
		{
			ins_R(R+1);
			R+=a;
		}
		else
		{
			scanf("%d",&b);
			P+=b; Q+=a-b;
		}
		qry();
	}
}