#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=200050;
int t[N];
int main()
{
	int q;
	scanf("%i",&q);
	while(q--)
	{
		int n,h;
		scanf("%i %i",&h,&n);
		for(int i=1;i<=n;i++) scanf("%i",&t[i]);
		int ans=0,j=0;
		t[0]=h+1;
		for(int i=0;i<=n;i++)
		{
			if(i!=0 && t[i]+1==t[i-1]) j++;
			else ans+=j%2,j=1;
		}
		if(t[n]!=1) ans+=j%2;
		printf("%i\n",ans);
	}
	return 0;
}