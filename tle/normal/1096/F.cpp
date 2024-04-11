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
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return x;
}
int bs[SZ];
void edt(int x,int y)
{
	for(;x<SZ;x+=x&-x)
		bs[x]+=y;
}
ll qry(int x)
{
	ll s=0;
	for(;x>=1;x-=x&-x)
		(s+=bs[x]);
	return s;
}
int n,p[SZ],g[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) g[i]=0;
	int A=0,B=0; ll ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",p+i);
		if(p[i]>0) g[p[i]]=1;
		else ++B;
	}
	ans+=B*(ll)(B-1)/2%MOD*qp(2,MOD-2)%MOD;
	for(int i=n;i>=1;--i) if(p[i]>0)
		ans+=qry(p[i]),ans%=MOD,edt(p[i],1);
	memset(bs,0,sizeof bs);
	for(int i=1;i<=n;++i)
		if(!g[i]) edt(i,1);
	for(int i=1;i<=n;++i)
	{
		if(p[i]<0)
		{
			++A,--B;continue;
		}
		ll Ps=qry(p[i])*qp(A+B,MOD-2)%MOD;
		ans+=Ps*B; ans%=MOD;
		ans+=(1-Ps)*A; ans%=MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}