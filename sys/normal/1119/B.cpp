#include <bits/stdc++.h>
using namespace std;
const int Maxn=1005;
int n,h,a[Maxn],x,y,b[Maxn],ans;
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=i;j++)
			b[j]=a[j];
		ans=0;
		sort(b+1,b+1+i);
		if(i%2)
			for(int j=1;j<=i;j+=2)
				ans+=b[j];
		else
			for(int j=2;j<=i;j+=2)
				ans+=b[j];
		if(ans>h)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",n);
	return 0;
}