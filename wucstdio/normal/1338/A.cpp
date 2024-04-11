#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int last=-1000000001,maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<last)maxx=max(maxx,last-a[i]),a[i]=last;
			last=a[i];
		}
		int ans=0;
		while(maxx)
		{
			ans++;
			maxx>>=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}