#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=500050;
ll a[N],b[N];
int main()
{
	int n,m,k;
	ll ta,tb;
	scanf("%i %i %lld %lld %i",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	if(k>=min(n,m)) return 0*printf("-1\n");
	int j=1;
	ll ans=0;
	for(int i=1;i<=k+1;i++)
	{
		int ost=k+1-i;
		ll tme=a[i]+ta;
		while(j<=m && b[j]<tme) j++;
		if(j+ost>m) return 0*printf("-1\n");
		ans=max(ans,b[j+ost]+tb);
	}
	printf("%lld\n",ans);
	return 0;
}