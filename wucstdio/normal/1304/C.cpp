#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll m,l,r,t;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&m);
		t=0,l=r=m;
		bool flag=1;
		while(n--)
		{
			ll ti,x,y;
			scanf("%lld%lld%lld",&ti,&x,&y);
			l-=ti-t,r+=ti-t;
			t=ti;
			l=max(l,x),r=min(r,y);
			if(l>r)flag=0;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}