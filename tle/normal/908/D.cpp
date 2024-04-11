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
int k,pa,pb;
const int MOD=1e9+7;
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
ll f[2333][2333],qz[2333][2333],bb[23333],inv[23333];
int main()
{
	cin>>k>>pa>>pb;
	ll ga=pa*qp(pa+pb,MOD-2)%MOD,
	gb=pb*qp(pa+pb,MOD-2)%MOD;
	bb[0]=inv[0]=1; ll ia=qp(ga,MOD-2),ib=qp(gb,MOD-2);
	for(int i=1;i<=20000;++i)
		bb[i]=bb[i-1]*ga%MOD,
		inv[i]=inv[i-1]*ia%MOD;
	f[0][1]=1;
	for(int i=0;i<=k;++i)
	{
		if(i)
		for(int j=1;j<=i;++j)
		{
			int p=i-j; ll&t=f[i][j],cp=1;
			t+=qz[p][j]*bb[j]%MOD*gb%MOD;
			t%=MOD;
		}
		for(int j=0;j<=k;++j)
		{
			qz[i][j]=f[i][j]*inv[j]%MOD;
			if(j) (qz[i][j]+=qz[i][j-1])%=MOD;
		}
	}
	--f[0][1]; (f[0][k]+=bb[k-1])%=MOD;
	ll ans=0,tt=0;
	for(int i=0;i<k;++i)
		for(int j=0;j<=k;++j) if(f[i][j]) 
		{
			int ls=max(k-i-j,0);
			ans+=qp(ga,ls)*(i+j+ls+ib-1)%MOD*f[i][j]%MOD;
		}
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}