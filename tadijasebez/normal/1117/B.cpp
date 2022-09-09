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
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	vector<int> a(n);
	for(int &i:a) scanf("%i",&i);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	ll block=(ll)a[0]*k+a[1];
	ll ans=block*(m/(k+1))+(ll)(m%(k+1))*a[0];
	printf("%lld\n",ans);
	return 0;
}