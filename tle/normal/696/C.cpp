#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
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
#define inf 1001001001
#define infll 1001001001001001001LL
#define FOR0(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR1(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define ld double
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define RI(n) int (n); scanf("%d",&(n));
#define RI2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define RI3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR0(i,sz(t))s<<t[i]<<" ";return s; }
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define all(t) t.begin(),t.end()
#define FEACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS RI(testow)while(testow--)
#define FORZ(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define FORD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define ios0 ios_base::sync_with_stdio(0)
ll MOD=1000000007;
#define R register
#define I __attribute__((optimize("-Ofast"))) inline
I ll qp(R ll a,R ll b)
{
	a%=MOD;
	R ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}
#define N 2
struct matrix {int s[2][2];}cs;
I matrix operator * (R matrix& a,R matrix& b)
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
I void quickpow(R matrix& a,R ll b)
{
	R matrix ans;
	for(R int i=0;i<N;++i)
	{
		for(R int j=0;j<N;++j) ans.s[i][j]=i==j;
	}
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	a=ans;
}

namespace fib {char b[6666666]={},*f=b;}
#define getc() ((*fib::f)?(*(fib::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
#define isd(c) (c>='0'&&c<='9')
ll aa; int bb;
ll F(){
	char ch;
	while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
	while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
int main()
{
	int k=F();
	ll fm=2;
	cs.s[0][0]=0; cs.s[0][1]=2;
	cs.s[1][0]=1; cs.s[1][1]=1;
	while(k--)
	{
		ll n=F();
		if(n==1) continue;
		quickpow(cs,n);
		fm=qp(fm,n)%MOD;
	}
	ll ans=(ll)cs.s[0][0]*qp(2,MOD-2)%MOD;
	fm=fm*qp(2,MOD-2)%MOD;
	if(!ans) fm=1;
	printf("%I64d/%I64d",ans,fm);
}