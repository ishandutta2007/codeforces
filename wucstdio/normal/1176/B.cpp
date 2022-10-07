#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[10005],cnt[5];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]%3]++;
		}
		int x=min(cnt[1],cnt[2]);
		int ans=cnt[0]+min(cnt[1],cnt[2]);
		cnt[1]-=x,cnt[2]-=x;
		printf("%d\n",ans+(cnt[1]+cnt[2])/3);
	}
	return 0;
}