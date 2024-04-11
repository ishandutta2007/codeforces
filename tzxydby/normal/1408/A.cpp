#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,a[N],b[N],c[N],ans[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<n;i++)
		{
			ans[i]=a[i];
			if(ans[i]==ans[i-1])
				ans[i]=b[i];
		}
		if(ans[1]==a[n]||ans[n-1]==a[n])
		{
			if(ans[1]==b[n]||ans[n-1]==b[n])
				ans[n]=c[n];
			else
				ans[n]=b[n];
		}
		else
			ans[n]=a[n];
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}