#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x=0,k;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		k=a[n];
		for(int i=n-1;i>=1;i--)
		{
			x+=k<a[i];
			k=min(k,a[i]);
		}
		printf("%d\n",x); 
	}
	return 0;
}