#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,x,a[N],s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		s=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		if(s==x)
			puts("NO");
		else
		{
			sort(a+1,a+n+1);
			int t=0;
			for(int i=1;i<=n;i++)
			{
				t+=a[i];
				if(t==x)
				{
					swap(a[i],a[i+1]);
					break;
				}
			}
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
}