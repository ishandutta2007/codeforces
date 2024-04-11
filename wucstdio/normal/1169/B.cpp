#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[300005],b[300005],cnt[300005],maxx,num;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&a[i],&b[i]);
	int x=a[1];
	memset(cnt,0,sizeof(cnt));
	maxx=num=0;
	for(int i=2;i<=m;i++)
	{
		if(a[i]==x||b[i]==x)continue;
		cnt[a[i]]++,cnt[b[i]]++;
		maxx=max(maxx,cnt[a[i]]);
		maxx=max(maxx,cnt[b[i]]);
		num++;
	}
	if(maxx==num)
	{
		printf("YES\n");
		return 0;
	}
	x=b[1];
	memset(cnt,0,sizeof(cnt));
	maxx=num=0;
	for(int i=2;i<=m;i++)
	{
		if(a[i]==x||b[i]==x)continue;
		cnt[a[i]]++,cnt[b[i]]++;
		maxx=max(maxx,cnt[a[i]]);
		maxx=max(maxx,cnt[b[i]]);
		num++;
	}
	if(maxx==num)
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}