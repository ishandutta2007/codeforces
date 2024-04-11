#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,k,a[100005],b[100005],l,r;
int main()
{
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1]-1;
	}
	b[1]=0;
	for(int i=2;i<=n;i++)b[i]+=b[i-1];
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",(b[r]-b[l])*2+(k-a[r])+(a[l]-1));
	}
	return 0;
}