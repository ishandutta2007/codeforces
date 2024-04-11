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
	int n,a,b;
	scanf("%i %i",&b,&n);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%i",&a);
		cnt^=a&1;
	}
	if((b&1)==0) printf("%s\n",a&1?"odd":"even");
	else printf("%s\n",cnt&1?"odd":"even");
	return 0;
}