#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int t,n,a[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int fl=0,mx=1,ans;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>a[mx])
				mx=i;
			if(a[i]!=a[1])
				fl=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[mx])
			{
				if(i!=1&&a[i-1]!=a[mx])
					ans=i;
				if(i!=n&&a[i+1]!=a[mx])
					ans=i;
			}
		}
		if(fl)
			printf("%d\n",ans);
		else
			puts("-1");
	}
	return 0;
}