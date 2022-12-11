#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		int ans=n;
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])
			{
				ans=1;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}