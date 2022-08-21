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
ll dep(ll x)
{
	ll ans=0;
	while(x) ans++, x>>=1;
	return ans;
}
ll glca(ll p,ll q)
{
	ll d1=dep(p),d2=dep(q);
	if(d1>d2) swap(d1,d2), swap(p,q);
	while(d1!=d2) q=q>>1, --d2;
	while(p!=q) q=q>>1, p=p>>1;
	return p;
}
map<ll,ll> vs;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c;
		if(a==1) cin>>d;
		ll lca=glca(b,c);
		if(a==1)
		{
			while(c!=lca) vs[c]+=d, c>>=1;
			while(b!=lca) vs[b]+=d, b>>=1;
		}
		else
		{
			ll ans=0;
			while(c!=lca) ans+=vs[c], c>>=1;
			while(b!=lca) ans+=vs[b], b>>=1;
			cout<<ans<<"\n";
		}
	}
}