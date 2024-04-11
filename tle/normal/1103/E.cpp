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
const int U=5,S=10;
typedef unsigned long long ull;
struct val
{
ull v[U];
val shift(int x)
{
	val uu; x%=S;
	if(x&1)
	{
		x=(x+5)>>1;
		for(int i=0;i<U;++i)
			uu.v[(i+x)%U]=-v[i];
	}
	else
	{
		x>>=1;
		for(int i=0;i<U;++i)
			uu.v[(i+x)%U]=v[i];
	}
	return uu; 
}
ull toull()
{return v[0]-v[1];}
};
val operator + (val a,val b)
{
	for(int i=0;i<U;++i) a.v[i]+=b.v[i];
	return a;
}
val operator - (val a,val b)
{
	for(int i=0;i<U;++i) a.v[i]-=b.v[i];
	return a;
}
val operator * (val a,val b)
{
	val c;
	memset(&c,0,sizeof c);
	for(int i=0;i<U;++i)
		for(int j=0;j<U;++j)
			c.v[(i+j)%U]+=a.v[i]*b.v[j];
	return c;
}
int n,x[SZ];
val cn[100055];
void dft(int p,int o)
{
	int d=o?(S-1):1;
	for(int i=0;i<100000;++i)
	{
		if(i%(p*S)>=p) continue;
		val su[S];
		memset(su,0,sizeof su);
		for(int a=0;a<S;++a)
			for(int b=0;b<S;++b)
				su[a]=su[a]+(cn[b*p+i].shift(a*b*d));
		for(int a=0;a<S;++a)
			cn[a*p+i]=su[a];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",x+i),++cn[x[i]].v[0];
	for(int i=1;i<100000;i*=10)
		dft(i,0);
	for(int i=0;i<100000;++i)
	{
		val a=cn[i],x;
		memset(&x,0,sizeof x);
		x.v[0]=1; ll b=n;
		while(b)
		{
			if(b&1) x=x*a;
			a=a*a; b>>=1;
		}
		cn[i]=x;
	}
	for(int i=1;i<100000;i*=10)
		dft(i,1);
	for(int i=0;i<n;++i)
	{
		ull w=cn[i].toull();
		for(int j=1;j<100000;j*=10)
			w/=2,w*=14757395258967641293ULL;
		w&=(1ULL<<58)-1;
		printf("%lld\n",ll(w)); 
	}
}