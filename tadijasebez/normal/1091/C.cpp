#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	int n,i;
	scanf("%i",&n);
	vector<ll> ans;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll sol=0;
			sol=(ll)i*(n/i-1)*(n/i)/2+n/i;
			ans.pb(sol);
			if(i*i!=n)
			{
				int j=i;
				i=n/i;
				sol=(ll)i*(n/i-1)*(n/i)/2+n/i;
				ans.pb(sol);
				i=j;
			}
		}
	}
	sort(ans.begin(),ans.end());
	for(ll p:ans) printf("%lld ",p);
	return 0;
}