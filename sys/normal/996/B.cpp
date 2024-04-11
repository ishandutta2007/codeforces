#include <bits/stdc++.h>
using namespace std;
int pnt,minn=0x7fffffff,n,a[100005],tim[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tim[i]=(a[i]+n-i)/n;
	}
	for(int i=1;i<=n;i++)
	{
		if(minn>tim[i])
		{
			minn=tim[i];
			pnt=i;
		}
	}
	printf("%d",pnt);
	return 0;
}