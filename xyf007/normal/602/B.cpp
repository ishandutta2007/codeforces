#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[100001],f[100001];
void checkmax(int &x,int y)
{
	if(x<y)
	{
		x=y;
	}
}
void checkmin(int &x,int y)
{
	if(x>y)
	{
		x=y;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0,l=1,min=2147483647,max=0;
	for(int r=1;r<=n;r++)
	{
		f[a[r]]++;
		checkmax(max,a[r]);
		checkmin(min,a[r]);
		while(max-min>1)
		{
			f[a[l]]--;
			l++;
			while(!f[min])
			{
				min++;
			}
			while(!f[max])
			{
				max--;
			}
		}
		checkmax(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}