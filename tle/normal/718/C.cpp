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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
ll MOD=1000000007;
ll qp(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1; 
	}
	return ans;
}
#define R register
#define N 2
struct matrix
{
	int s[3][3];
	matrix()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++) s[i][j]=(i==j);
		}
	}
	void clr()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++) s[i][j]=(i==j);
		}
	}
	bool clean()
	{
		bool ans=1;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++) ans&=(i==j);
		}
		return ans;
	}
}cs;
matrix operator * (matrix a,matrix b)
{
	R matrix ans;
	for(R int i=0;i<N;++i)
	{
		for(R int j=0;j<N;++j)
		{
			R ll rp=0;
			for(R int k=0;k<N;++k) rp=rp+(ll)a.s[i][k]*b.s[k][j]%MOD;
			rp%=MOD;
			ans.s[i][j]=rp;
		}
	}
	return ans;
}
matrix operator + (matrix a,matrix b)
{
	R matrix ans;
	for(R int i=0;i<N;++i)
	{
		for(R int j=0;j<N;++j) ans.s[i][j]=(a.s[i][j]+b.s[i][j])%MOD;
	}
	return ans;
}
matrix quickpow(matrix a,R ll b)
{
	matrix ans;
	for(R int i=0;i<N;++i)
	{
		for(R int j=0;j<N;++j) ans.s[i][j]=i==j;
	}
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	return ans;
}
namespace seg
{
int M=131072,M2=M+M,ls[SZ],rs[SZ];
matrix sum[SZ],tag[SZ];
void build()
{
    for(int i=M+1;i<=M+M;i++) ls[i]=rs[i]=i-M;
    for(int i=M-1;i;i--) ls[i]=ls[i+i], rs[i]=rs[i+i+1], sum[i]=sum[i+i]+sum[i+i+1];
}
void pd(int x)
{
    if(tag[x].clean()) return;
    sum[x]=sum[x]*tag[x];
    if(x+x<=M2)
	tag[x+x]=tag[x+x]*tag[x], tag[x+x+1]=tag[x+x+1]*tag[x];
    tag[x].clr();
}
void upd(int x)
{
    pd(x+x); pd(x+x+1);
    sum[x]=sum[x+x]+sum[x+x+1];
}
void edit(int x,int ql,int qr,matrix v)
{
    if(x>M2||ql>qr) return;
    pd(x);
    if(ql==ls[x]&&qr==rs[x]) {tag[x]=tag[x]*v; return;}
    int mid=ls[x]+rs[x]>>1;
    edit(x+x,ql,min(qr,mid),v);
    edit(x+x+1,max(mid+1,ql),qr,v);
    upd(x);
}
matrix gsum(int x,int ql,int qr)
{
    if(x>M2||ql>qr) return matrix();
    pd(x);
    if(ql==ls[x]&&qr==rs[x]) return sum[x];
    int mid=ls[x]+rs[x]>>1;
    matrix ans=gsum(x+x,ql,min(qr,mid))+gsum(x+x+1,max(mid+1,ql),qr);
    upd(x); return ans;
}
}
matrix fib;
int n,m;
int main()
{
	fib.s[0][1]=fib.s[1][0]=fib.s[1][1]=1;
	fib.s[0][0]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a; scanf("%d",&a);
		seg::sum[i+seg::M]=quickpow(fib,a);
	}
	seg::build();
	while(m--)
	{
		int t,l,r,x;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			scanf("%d",&x);
			seg::edit(1,l,r,quickpow(fib,x));
		}
		else
		{
			matrix rst=seg::gsum(1,l,r);
			ll ans=rst.s[0][1];
			ans=(ans%MOD+MOD)%MOD;
			printf("%d\n",int(ans));
		}
	}
}