#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=a[i-1]+x;
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",(a[r]-a[l-1])/10);
	}
	return 0;
}