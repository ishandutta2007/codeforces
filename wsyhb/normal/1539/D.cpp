#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
struct Product
{
	long long a,b;
}p[max_n];
inline bool operator < (const Product &x,const Product &y)
{
	return x.b<y.b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&p[i].a,&p[i].b);
	sort(p+1,p+n+1);
	int l=1,r=n;
	long long tot=0,ans=0;
	while(l<=r)
	{
		if(tot>=p[l].b)
		{
			tot+=p[l].a;
			ans+=p[l].a;
			p[l++].a=0;
		}
		else if(tot+p[r].a<=p[l].b)
		{
			tot+=p[r].a;
			ans+=2*p[r].a;
			p[r--].a=0;
		}
		else
		{
			long long delta=p[l].b-tot;
			tot+=delta;
			ans+=2*delta;
			p[r].a-=delta;
		}
	}
	printf("%lld\n",ans);
	return 0;
}