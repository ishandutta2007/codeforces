#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
int n,a[200005],maxx=-1;
map<ll,int>last;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll s=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		if(last[s]||s==0)maxx=max(maxx,last[s]);
		ans+=i-maxx-1;
		last[s]=i;
	}
	printf("%lld\n",ans);
	return 0;
}