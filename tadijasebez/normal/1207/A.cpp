#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int a,b,c,d,e;
		scanf("%i %i %i %i %i",&a,&b,&c,&d,&e);
		if(d<e) swap(d,e),swap(b,c);
		a/=2;
		int p=min(a,b);
		int ans=0;
		ans+=p*d;
		a-=p;
		p=min(a,c);
		ans+=p*e;
		printf("%i\n",ans);
	}
	return 0;
}