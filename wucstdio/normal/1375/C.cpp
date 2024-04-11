#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[300005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(a[1]<a[n])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}