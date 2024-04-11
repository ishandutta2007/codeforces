#include <bits/stdc++.h>
using namespace std;
long long all;
int n,a[200005];
double sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum/=2.0;
	for(int i=1;i<=n;i++)
	{
		all+=a[i];
		if(all>=sum){printf("%d",i);break;}
	}
	return 0;
}