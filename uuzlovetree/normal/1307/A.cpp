#include<bits/stdc++.h>
using namespace std;
int T,n,d; 
int a[1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=2;i<=n;++i)
		{
			while(d>=i-1&&a[i]>0)
			{
				a[1]++;
				a[i]--;
				d-=i-1;
			}
		}
		printf("%d\n",a[1]);
	}
}