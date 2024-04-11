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
	while(b<0) b+=MOD-1;
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
int *w0[2333],*w1[2333];
int getK(int n)
{int s=1; while(s<n) s<<=1; return s;}
void prep(int K)
{
	static int pool[1048576*4+3],*p=pool,i=1,j=1;
	for(;j<=K;++i,j<<=1)
	{
		w0[i]=p; w1[i]=(p+=j); p+=j;
		ll g=qp(3,(MOD-1)>>i),ig=qp(g,MOD-2);
		w0[i][0]=w1[i][0]=1;
		for(int k=1;k<j;++k)
			w0[i][k]=w0[i][k-1]*g%MOD,
			w1[i][k]=w1[i][k-1]*ig%MOD;
	}
}
void fft(int* x,int K,int v)
{
	prep(K);
	for(int i=0,j=0;i<K;i++)
	{
		if(i>j) swap(x[i],x[j]);
		for(int l=K>>1;(j^=l)<l;l>>=1);
	}
	for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
	for(int i=2,c=1;i<=K;i<<=1,++c)
		for(int *w=v?w1[c]:w0[c],j=0;j<K;j+=i)
			for(int h=i>>1,a,b,l=0;l<h;++l)
			{
				a=x[j+l]; if(a>=MOD) a-=MOD;
				b=(ll)x[j+h+l]*w[l]%MOD,
				x[j+h+l]=a-b+MOD,x[j+l]=a+b;
			}
	for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
	if(!v) return;
	ll rv=qp(K,MOD-2);
	for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
vector<int> operator * (const vector<int>& a,const vector<int>& b)
{
	static int p[1048576],q[1048576];
	int w=a.size()+b.size()-1;
	vector<int> c; c.resize(w);
	if(b.size()<13)
	{
		for(int i=0;i<a.size();++i)
			for(int j=0;j<b.size();++j)
				c[i+j]=(c[i+j]+(ll)a[i]*b[j])%MOD;
		return c;
	}
	int K=getK(w);
	for(int i=0;i<K;++i) p[i]=q[i]=0;
	for(int i=0;i<a.size();++i) p[i]=a[i];
	for(int i=0;i<b.size();++i) q[i]=b[i];
	fft(p,K,0); fft(q,K,0);
	for(int i=0;i<K;++i)
		p[i]=p[i]*(ll)q[i]%MOD;
	fft(p,K,1);
	for(int i=0;i<w;++i) c[i]=p[i];
	return c;
}
vector<int> l;
int n,k,d[10];
vector<int> calc(int n)
{
	if(n==1) return l;
	auto g=calc(n/2);
	g=g*g;
	if(n&1) g=g*l;
	return g;
}
int main()
{
	prep(1048576);
	cin>>n>>k; n/=2;
	l.resize(10);
	for(int i=0;i<k;++i)
		cin>>d[i],l[d[i]]=1;
	auto w=calc(n);
	ll ans=0;
	for(auto s:w)
		ans+=s*(ll)s,ans%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}