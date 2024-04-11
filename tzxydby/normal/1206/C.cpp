#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==0)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			a[i]=i*2-1;
			a[n+i]=i*2;
		}
		else
		{
			a[i]=i*2;
			a[n+i]=i*2-1;
		}
	}
	puts("YES");
	for(int i=1;i<=2*n;i++)
		printf("%d ",a[i]);
	return 0;
}