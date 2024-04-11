#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],n,mx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
		printf("%d ",a[i]);
	}
	return 0;
}