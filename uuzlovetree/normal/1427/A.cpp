#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int T,n;
int a[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
		if(s==0)puts("NO");
		else
		{
			puts("YES");
			sort(a+1,a+n+1);
			if(s<0)
			{
				for(int i=1;i<=n;++i)printf("%d ",a[i]);
			}
			else
			{
				for(int i=n;i>=1;--i)printf("%d ",a[i]);
			}
			puts("");
		}
	}
}