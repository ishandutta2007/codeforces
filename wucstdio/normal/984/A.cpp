#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",a[(n+1)/2]);
	return 0;
}