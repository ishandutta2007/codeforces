#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
int n,a[N],x[N],y[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int r=a[i]+a[j];
			if(x[r])
			{
				if(i!=x[r]&&i!=y[r]&&j!=x[r]&&j!=y[r])
				{
					puts("YES");
					printf("%d %d %d %d\n",i,j,x[r],y[r]);
					return 0;
				}
			}
			x[r]=i,y[r]=j;
		}
	}
	puts("NO");
	return 0;
}