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
int T,n,a[SZ];
const int MOD=1e9+7;
ll qp(ll a,ll b) {
	ll x=1; a%=MOD;
	while(b) {
		if(b&1) x=x*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return x;
}
ll fac[SZ],rfac[SZ];
ll Cc(int a,int b) {
	return fac[a+b]*rfac[b]%MOD*rfac[a]%MOD;
}
ll C(int a,int b) {
	return fac[a]*rfac[b]%MOD*rfac[a-b]%MOD;
}
int main() {
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	/*
	for(int i=0;i<=5;++i) {
		for(int j=0;j<=i;++j) {
			ll s=0;
			for(int k=0;k<=j;++k)s+=Cc(i,k);
			cout<<s<<" "<<C(j+i+1,i+1)<<",";
		}
		cout<<"\n";
	} */
	scanf("%d",&n);
	for(int i=0;i<=n;++i) scanf("%d",a+i);
	ll ans=0;
	for(int i=0;i<=n;++i) {
		//i<a[i] 
//		for(int j=0;j<a[i];++j)
//		ans+=Cc(i,j);
		if(a[i])
		ans+=Cc(a[i]-1,i+1);
		/*
		for(int j=a[i]-1;j>=a[i+1]-1&&j>=0;--j) {
			// at(i,j)
			if(j+1>=a[i]) ans+=Cc(i,j);
			if(j>=a[i+1]) ans+=Cc(i,j);
			cout<<i<<","<<j<<" "<<(j+1>=a[i])+(j>=a[i+1])<<"\n"; 
		}*/
//			ans+=Cc(i,j),
//			cout<<i<<","<<j<<"\n";
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}