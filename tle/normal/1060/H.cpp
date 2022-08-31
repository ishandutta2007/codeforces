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
ll C[2333][2333];
int d,MOD,p=0;
#define SZ 23333
ll co[SZ];
vector<int> operator - (vector<int> a,vector<int> b)
{
	vector<int> s;
	int u=max(a.size(),b.size());
	a.resize(u); b.resize(u);
	for(int i=0;i<u;++i)
		s.pb((a[i]-b[i])%MOD);
	return s;
}
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
int add(int a,int b)
{
	++p;
	cout<<"+ "<<a<<" "<<b<<" "<<p<<endl;
	co[p]=(co[a]+co[b])%MOD;
	return p;
}
int po(int a)
{
	++p;
	cout<<"^ "<<a<<" "<<p<<endl;
	co[p]=qp(co[a],d);
	return p;
}
int mul(int a,int k)
{
	k=(k%MOD+MOD)%MOD;
	if(!k) k+=MOD;
	int s=a; --k;
	while(k)
	{
		if(k&1) s=add(s,a);
		a=add(a,a); k>>=1;
	}
	return s;
}
int neg(int a)
{return mul(a,MOD-1);}
#define minus minus_
int minus(int a,int b)
{return add(a,neg(b));}
void op(int a)
{
	cout<<"f "<<a<<endl;
	cerr<<co[a]<<endl;
}
int l=3,z;
ll show(vector<int>&v,ll t)
{
	ll x=1,s=0;
	for(int i=0;i<v.size();++i)
		s+=x*v[i]%MOD,s%=MOD,x=x*t%MOD;
	return (s%MOD+MOD)%MOD;
}
int p2(int a)
{
	if(d==2) return po(a);
	int n=d+1;
	static vector<int> u[233],ss[233];
	static int w[233],ww[233];
	ww[0]=a;
	for(int i=1;i<=n;++i)
	{
		u[i].clear();
		ss[i].clear();
		for(int w=0;w<=d;++w)
			u[i].pb(C[d][w]*qp(i,d-w)%MOD);
		ww[i]=add(ww[i-1],l);
		w[i]=po(ww[i]);
		ss[i].resize(n+1);
		ss[i][i]=1;
	}
	for(int s=0;s<=d;++s)
	{
		ll x=u[s+1][s]%MOD;
		if(!x)
		{
		for(int q=s+2;q<=n;++q)
			if(u[q][s]%MOD)
			{
				x=u[q][s]%MOD;
				for(int i=1;i<=n;++i)
					swap(ss[i][s+1],ss[i][q]);
//				swap(w[s+1],w[q]);
				swap(u[s+1],u[q]);
				break;
			}
		}
		if(!x) throw "GG";
		ll rv=qp(x,MOD-2);
		for(auto& w:u[s+1]) w=w%MOD*rv%MOD;
		for(auto& w:ss[s+1]) w=w%MOD*rv%MOD;
//		w[s+1]=mul(w[s+1],rv);
		for(int q=1;q<=n;++q) if(q!=s+1&&u[q][s]%MOD)
		{
			ll v=u[q][s]%MOD;
//			w[q]=add(w[q],mul(w[s+1],-v));
			for(int e=1;e<=n;++e)
				ss[q][e]=(ss[q][e]-ss[s+1][e]*v)%MOD;
			for(int e=0;e<=d;++e)
				u[q][e]=(u[q][e]-u[s+1][e]*v)%MOD;
		}
	}
	int aa=z;
	for(int i=1;i<=n;++i)
		if(ss[3][i])
//			cout<<ss[2][i]<<"?\n",
			aa=add(aa,mul(w[i],ss[3][i]));
//	cerr<<co[a]<<"->"<<co[aa]<<"!!\n";
	return aa;
}
int main()
{
	cin>>d>>MOD; p=4;
	for(int i=0;i<SZ;++i) co[i]=1;
	for(int i=0;i<2333;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	co[1]=5; co[2]=3; z=minus(l,l);
	op(mul(minus(minus(p2(add(1,2)),p2(1)),p2(2)),(MOD+1)/2));
}