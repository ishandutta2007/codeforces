#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
int n,q;
ll a[200005],c[200005],sum;
map<pair<int,int>,int>mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	scanf("%d",&q);
	while(q--)
	{
		int s,t,u;
		scanf("%d%d%d",&s,&t,&u);
		int&x=mp[make_pair(s,t)];
		if(x)
		{
			c[x]--;
			if(c[x]<a[x])sum++;
			x=0;
		}
		if(u)
		{
			x=u;
			c[x]++;
			if(c[x]<=a[x])sum--;
		}
		printf("%lld\n",sum);
	}
	return 0;
}