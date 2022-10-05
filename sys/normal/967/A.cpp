#include <bits/stdc++.h>
using namespace std;
struct tim
{
	int h,m;
	int operator - (tim a)
	{
		return 60*(h-a.h)+m-a.m;
	}
}timm[105];
int n,s;
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&timm[i].h,&timm[i].m);
	timm[0]=(tim){0,-s-1}; 
	timm[n+1]=(tim){100000,0};
	for(int i=1;i<=n+1;i++)
	{
		if(60*(timm[i].h-timm[i-1].h)+timm[i].m-timm[i-1].m>s*2+1) 
		{
			tim ans;
			ans=timm[i-1];
			ans.m+=(s+1);
			while(ans.m>=60) ans.m-=60,ans.h++;
			printf("%d %d",ans.h,ans.m);
			goto A;
		}
	}
	A:return 0;
}