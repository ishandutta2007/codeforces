#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],cnt[100005],ccnt[100005],maxx;
int main()
{
	scanf("%d",&n);
	ccnt[0]=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ccnt[cnt[a[i]]]--;
		cnt[a[i]]++;
		ccnt[cnt[a[i]]]++;
		maxx=max(maxx,cnt[a[i]]);
	}
	for(int i=n;i>=1;i--)
	{
		if(maxx*ccnt[maxx]==i-1)
		{
			printf("%d\n",i);
			return 0;
		}
		else if((maxx-1)*(ccnt[maxx-1]+1)==i-1)
		{
			printf("%d\n",i);
			return 0;
		}
		else if(maxx==1)
		{
			printf("%d\n",i);
			return 0;
		}
		ccnt[cnt[a[i]]]--;
		if(cnt[a[i]]==maxx&&ccnt[cnt[a[i]]]==0)maxx--;
		cnt[a[i]]--;
		ccnt[cnt[a[i]]]++;
		maxx=max(maxx,cnt[a[i]]);
	}
	return 0;
}