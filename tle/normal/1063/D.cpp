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
ll n;
//ax+by=1
void exgcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0) {x=1; y=0; return;}
    exgcd(b,a%b,x,y);
    ll p=x-a/b*y; x=y; y=p;
}
ll dv(ll a,ll b)
{
	if(b==0) return 8e18;
	ll u=a/b-2;
	while((u+1)*b<=a) ++u;
	return u;
}
ll wo(ll p,ll q,ll k,ll b)
{
	if(k<p) return -1;
	k-=p;
	ll ua=min(p,k);
	if(b<=ua);else return -1;
	//k=A+(A+B+n)*t, b<=A<=ua, 0<=B<=q=n-p
	//(A+B+n)*t \in [k-ua,k-b]
	if(n<900000)
	{
		for(int w=n;w>=0;--w)
		{
			ll u=w+n,t=(k-ua)/u-2;
			while(u*t<k-ua||t<0) ++t;
			while(u*t<=k-b)
			{
				ll A=k-u*t,B=w-A;
				if(b<=A&&A<=ua);else throw "GG";
				if(0<=B&&B<=q) return w;
				++t;
			}
		}
		return -1;
	}
	ll aa=-1;
	//k=A+(A+B+n)*t, b<=A<=ua, 0<=B<=q
	//t
	for(ll t=0;n*t<=k;++t)
	{
		//A*(t+1)+B*t=k-n*t
		ll A=t+1,B=t,C=k-n*t;
		if(C==0)
		{
			if(b<=0)
			{
				if(t==0) aa=max(aa,q);
				else aa=max(aa,0LL);
			}
			continue;
		}
		ll a0,b0;
		exgcd(A,B,a0,b0);
		a0*=C; b0*=C;
		if(B==0)
		{
			if(b<=a0&&a0<=p);
			else continue;
		}
		//b<=a0-k*B<=ua,0<=b0+k*A<=q
		//A+B=a0+b0+k
		ll k=min(dv(a0-b,B),dv(q-b0,A));
		if(a0-k*B<=ua&&b0+k*A>=0);else continue;
		aa=max(aa,a0+b0+k);
	}
	return aa;
}
int main()
{
	ll l,r,k;
	cin>>n>>l>>r>>k;
	ll g=r-l+1;
	if(g<=0) g+=n;
	ll ans=-1;
	ans=max(ans,wo(g,n-g,k,0));
	ans=max(ans,wo(g,n-g,k+1,1));
	cout<<ans<<"\n";
}