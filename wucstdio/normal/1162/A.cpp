#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,h,a[55];
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	for(int i=1;i<=n;i++)a[i]=h;
	while(m--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		for(int i=l;i<=r;i++)a[i]=min(a[i],x);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[i]*a[i];
	printf("%d\n",ans);
	return 0;
}