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
	int t;
	scanf("%i",&t);
	while(t--)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		if(a-b==1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}