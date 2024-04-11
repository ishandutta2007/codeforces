#include <bits/stdc++.h>
using namespace std;
int a[1005],n;
int main()
{
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	 	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d",a[(n+1)/2]);
	return 0;
}