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
ll mod=1000003;
struct matrix {int n; ll s[103][103];};
matrix operator * (matrix a,matrix b)
{
	matrix ans; ans.n=a.n;
	for(int i=1;i<=a.n;i++)
	{
		for(int j=1;j<=a.n;j++)
		{
			ll rp=0;
			for(int k=1;k<=a.n;k++) rp=(rp+a.s[i][k]*b.s[k][j]%mod)%mod;
			ans.s[i][j]=rp;
		}
	}
	return ans;
}
matrix I(int n)
{
	matrix ans; ans.n=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) ans.s[i][j]=i==j;
	}
	return ans;
}
matrix quickpow(matrix a,ll b)
{
	matrix ans=I(a.n);
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a; b>>=1;
	}
	return ans;
}
matrix cs;
int c,w,h;
int main()
{
	cin>>c>>w>>h;
	cs.n=w+1;
	for(int i=1;i<=w+1;i++) cs.s[i][1]=1;
	for(int j=2;j<=w+1;j++)
	{
		for(int i=1;i<=w;i++) cs.s[i][j]=(i==j-1)?h:0;
	}
	matrix aa=quickpow(cs,c);
	ll ans=0;
	for(int i=1;i<=w+1;i++) ans=ans+aa.s[1][i], ans%=mod;
	cout<<ans<<"\n";
}