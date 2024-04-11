#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N],t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=0,l=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!a[i])	
				continue;
			if(l==0)
				l=i;
			else
			{
				ans+=i-l-1;
				l=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}