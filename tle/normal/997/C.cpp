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
#define SZ 2333333
ll fac[SZ],rfac[SZ];
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll C(int a,int b)
{
	if(b>a||b<0) return 0;
	return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	int n;
	cin>>n;
	ll ans=qp(qp(3,n)-3,n);
	for(int i=1;i<=n;++i)
		if(i&1)
		{
		ans-=C(n,i)*qp(qp(3,n-i)-1,n)*3;ans%=MOD;
		ans-=C(n,i)*(qp(3,i)-3)%MOD*
		qp(qp(3,n-i),n);ans%=MOD;
		}
		else
		{
		ans+=C(n,i)*qp(qp(3,n-i)-1,n)*3;ans%=MOD;
		ans+=C(n,i)*(qp(3,i)-3)%MOD*
		qp(qp(3,n-i),n);ans%=MOD;
		}
	ans=qp(3,(ll)n*n)-ans;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}