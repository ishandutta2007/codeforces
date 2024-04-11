#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
ll Get(ll x, ll y)
{
	ll mn=min(x,y);
	if(x>mn) return mn*2+1;
	else return mn*2;
}
int main()
{
	ll a,b,ab;
	scanf("%lld %lld %lld",&a,&b,&ab);
	ll ans=ab*2+Get(a,b);
	ll sol=1+ab*2+Get(a,b-1);
	printf("%lld\n",max(ans,sol));
	return 0;
}