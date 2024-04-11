#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main()
{
	int n,sum=1,ans=1;
	scanf("%d%d",&n,&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=a[i-1]*2)
			sum++;
		else
		{
			ans=max(ans,sum);
			sum=1; 
		}
	}
	ans=max(ans,sum);
	printf("%d\n",ans);
	return 0;
}