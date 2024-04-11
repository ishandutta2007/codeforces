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
char s[555]; int sn,n,f[1510][210][210],go[23333],ans[23333];
const int MOD=10007;
inline ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
namespace linear_seq {
ll res[23333],base[23333],_c[23333],_md[23333];
vector<int> Md;
void mul(ll *a,ll *b,int k)
{
	for(int i=0;i<k+k;++i) _c[i]=0;
	for(int i=0;i<k;++i) if(a[i])
		for(int j=0;j<k;++j) _c[i+j]=(_c[i+j]+a[i]*b[j])%MOD;
	for (int i=k+k-1;i>=k;i--) if(_c[i])
		for(int j=0;j<(int)Md.size();++j)
			_c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%MOD;
	for(int i=0;i<k;++i) a[i]=_c[i];
}
int solve(ll n,vector<int> a,vector<int> b)
{
	ll ans=0,pnt=0; int k=a.size();
	for(int i=0;i<k;++i) _md[k-1-i]=-a[i];
	_md[k]=1; Md.clear();
	for(int i=0;i<k;++i) if(_md[i]) Md.push_back(i);
	for(int i=0;i<k;++i) res[i]=base[i]=0;
	res[0]=1; while((1ll<<pnt)<=n) ++pnt;
	for (int p=pnt;p>=0;p--)
	{
		mul(res,res,k);
		if(!((n>>p)&1)) continue;
		for(int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
		for(int j=0;j<(int)Md.size();++j)
			res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%MOD;
	}
	for(int i=0;i<k;++i) ans=(ans+res[i]*b[i])%MOD;
	if(ans<0) ans+=MOD; return ans;
}
vector<int> BM(vector<int> s)
{
	vector<int> C(1,1),B(1,1);
	int L=0,m=1,b=1;
	for(int n=0;n<(int)s.size();++n)
	{
		ll d=0;
		for(int i=0;i<=L;++i) d=(d+(ll)C[i]*s[n-i])%MOD;
		if(d==0) ++m;
		else if(L*2<=n)
		{
			vector<int> T=C;
			ll c=MOD-d*qp(b,MOD-2)%MOD;
			while(int(C.size())<int(B.size())+m) C.push_back(0);
			for(int i=0;i<(int)B.size();++i)
				C[i+m]=(C[i+m]+c*B[i])%MOD;
			L=n+1-L; B=T; b=d; m=1;
		}
		else
		{
			ll c=MOD-d*qp(b,MOD-2)%MOD;
			while(int(C.size())<int(B.size())+m) C.push_back(0);
			for(int i=0;i<(int)B.size();++i)
				C[i+m]=(C[i+m]+c*B[i])%MOD;
			++m;
		}
	}
	return C;
}
int gao(vector<int> a,ll n)
{
	vector<int> c=BM(a); c.erase(c.begin());
	for(int i=0;i<(int)c.size();++i) c[i]=(MOD-c[i])%MOD;
	return solve(n,c,vector<int>
	(a.begin(),a.begin()+int(c.size())));
}
}
int main()
{
	scanf("%s%d",s+1,&n);
	sn=strlen(s+1); n+=sn;
	f[0][1][sn]=1;
	for(int i=1;i<=1505;++i)
	{
		for(int j=1;j<=sn+1;++j)
			for(int k=j-1;k<=sn;++k) if(f[i-1][j][k])
			{
				if(j>k)
				{
					(f[i][j][k]+=f[i-1][j][k]*26)%=MOD;
					continue;
				}
				if(j==k)
				{
					(f[i][j][k]+=f[i-1][j][k]*25)%=MOD;
					(f[i][j][k-1]+=f[i-1][j][k])%=MOD;
					continue;
				}
				if(s[j]==s[k])
				{
					(f[i][j][k]+=f[i-1][j][k]*25)%=MOD;
					(f[i][j+1][k-1]+=f[i-1][j][k])%=MOD;
					continue;
				}
				(f[i][j][k]+=f[i-1][j][k]*24)%=MOD;
				(f[i][j][k-1]+=f[i-1][j][k])%=MOD;
				(f[i][j+1][k]+=f[i-1][j][k])%=MOD;
			}
	}
	for(int i=0;i<=3005;++i)
	{
		int g=i/2;
		if(i%2==0)
		{
			for(int j=1;j<=sn+1;++j)
				(ans[i]+=f[g][j][j-1])%=MOD;
		}
		else
		{
			for(int j=1;j<=sn+1;++j)
				(ans[i]+=f[g][j][j-1]*26)%=MOD;
			for(int j=1;j<=sn;++j)
				(ans[i]+=f[g][j][j])%=MOD;
		}
	}
	vector<int> g;
	for(int i=0;i<=3005;++i) g.pb((ans[i]%MOD+MOD)%MOD);
	int op=linear_seq::gao(g,n);
	op=(op%MOD+MOD)%MOD; cout<<op<<"\n";
}