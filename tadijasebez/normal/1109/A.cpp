#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	map<int,int> cnt[2];
	int n,i;
	scanf("%i",&n);
	vector<int> a(n+1,0);
	cnt[0][0]++;
	ll ans=0;
	ll x=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		x^=a[i];
		ans+=cnt[i&1][x];
		cnt[i&1][x]++;
	}
	printf("%lld\n",ans);
	return 0;
}