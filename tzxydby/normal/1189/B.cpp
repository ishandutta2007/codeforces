#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]<a[n-2]+a[n-1])
	{
		puts("YES");
		for(int j=1;j<=n-2;j++)
			printf("%d ",a[j]);
		printf("%d %d \n",a[n],a[n-1]);
		return 0;
	}
	puts("NO");
	return 0;
}