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
const int MOD=998244353;
#define SZ 666666
ll w[2][SZ];
inline ll qp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
int K;
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
inline void fft(int* x,int v)
{
    for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            {
                p[j]=(q[j]-(t=(ll)p[j]*W%MOD)<0)?(q[j]-t+MOD):(q[j]-t);
                q[j]=(q[j]+t-MOD>=0)?(q[j]+t-MOD):(q[j]+t);
            }
        }
    if(!v) return;
    ll rv=qp(K,MOD-2);
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
vector<int> operator * (vector<int> a,vector<int> b)
{
	if(a.size()&&b.size());else return vector<int>();
	static int aa[SZ],bb[SZ]; fftinit(a.size()+b.size());
	for(int i=0;i<K;++i) aa[i]=bb[i]=0;
	for(int i=0;i<int(a.size());++i) aa[i]=a[i];
	for(int i=0;i<int(b.size());++i) bb[i]=b[i];
	fft(aa,0); fft(bb,0);
	for(int i=0;i<K;++i) aa[i]=(ll)aa[i]*bb[i]%MOD;
	vector<int> v; fft(aa,1);
	for(int i=0;i<int(a.size())+int(b.size())-1;++i) v.pb(aa[i]);
	return v;
}
vector<int> operator + (vector<int> a,vector<int> b)
{
	vector<int> s(max(a.size(),b.size()));
	for(int i=0;i<int(a.size());++i) (s[i]+=a[i])%=MOD;
	for(int i=0;i<int(b.size());++i) (s[i]+=b[i])%=MOD;
	return s;
}
int n,sz[SZ],son[SZ],fa[SZ]; ll v; Edg
void dfs(int x,int f=0)
{
	sz[x]=1; son[x]=0; fa[x]=f;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
}
int vs[SZ],vn=0;
vector<int> ans[SZ],tmp[SZ];
pair<vector<int>,vector<int> > work(int l,int r)
{
	if(l==r) return mp(tmp[l],tmp[l]);
	int m=(l+r)>>1;
	auto L=work(l,m),R=work(m+1,r);
	return mp(L.fi*R.fi,L.se+L.fi*R.se); 
}
void dfs2(int x)
{
	for(int p=x;p;p=son[p])
		for esb(p,e,b) if(b!=fa[p]&&b!=son[p]) dfs2(b);
	vn=0; for(int p=x;p;p=son[p]) vs[++vn]=p;
	if(x==1) tmp[0]={1}; else tmp[0]={0,1};
	for(int i=1;i<=vn;++i)
	{
		int p=vs[i]; tmp[i]={0,1};
		for esb(p,e,b) if(b!=fa[p]&&b!=son[p])
			tmp[i]=ans[b];
	}
	ans[x]=work(0,vn).se;
}
int main()
{
	scanf("%d%lld",&n,&v);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1); dfs2(1);
	ll fz=1,fm=1,aaa=0;
	for(int i=1;i<int(ans[1].size());++i)
	{
		if(i>1)
			fz=fz*(v%MOD+i-1)%MOD,fm=fm*(i-1)%MOD;
		ll aa=fz*qp(fm,MOD-2)%MOD;
		aaa+=aa*ans[1][i]; aaa%=MOD;
	}
	aaa=(aaa%MOD+MOD)%MOD;
	cout<<aaa<<"\n";
}