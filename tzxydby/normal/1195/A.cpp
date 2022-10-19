#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int ans=0,k=(n+1)/2;
	for(int i=1;i<=s;i++)
	{
		if(a[i]>=2)
		{
			ans+=(a[i]/2)*2;
			k-=a[i]/2;	
		}
	}
	ans=min(ans+k,n);
	printf("%d\n",ans);
	return 0;
}