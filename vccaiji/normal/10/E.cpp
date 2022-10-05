#include<bits/stdc++.h>
using namespace std;
int n;
int a[410];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int minn=0x7fffffff;//
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int u=a[i-1]-1;
			int ans1=0,x=0;
			for(int t=i;t<=j-1;t++)
			{
				x+=(u/a[t])*a[t];
				ans1+=u/a[t];
				u%=a[t];
			}
			x+=(u/a[j]+1)*a[j];
			ans1+=u/a[j]+1;
			int ans2=0,y=x;
			for(int t=1;t<=n;t++)
			{
				ans2+=y/a[t];
				y%=a[t];
			}
			if((ans1<ans2)&&(minn>x)) minn=x;
		}
	}
	if(minn==0x7fffffff) printf("-1");
	else printf("%d",minn);
	return 0;
}