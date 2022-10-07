#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,a[300005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",(a[r]-a[l-1])/10);
	}
	return 0;
}