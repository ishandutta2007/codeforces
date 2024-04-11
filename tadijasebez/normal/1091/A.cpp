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
	int y,b,r;
	scanf("%i %i %i",&y,&b,&r);
	int ans=min(y,b-1);
	ckmn(ans,r-2);
	printf("%i\n",ans+ans+1+ans+2);
	return 0;
}