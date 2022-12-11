#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n;i>=1;--i)printf("%d ",a[i]);
		puts("");
	}
}