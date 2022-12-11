#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int j=i+1,L=a[i]-x,R=a[i]+x;
			while(j<=n)
			{
				L=max(L,a[j]-x);
				R=min(R,a[j]+x);
				if(L>R)
					break;
				++j;
			}
			++ans;
			i=j-1;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}