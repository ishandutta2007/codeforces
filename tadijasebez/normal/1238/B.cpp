#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
int x[N];
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n,r;
		scanf("%i %i",&n,&r);
		for(int i=1;i<=n;i++) scanf("%i",&x[i]);
		sort(x+1,x+1+n);
		n=unique(x+1,x+1+n)-x-1;
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<=n && x[j]<=r*i) j++;
			if(n-j+1<=i){ printf("%i\n",i);break;}
		}
	}
	return 0;
}