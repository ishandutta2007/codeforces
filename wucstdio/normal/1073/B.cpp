#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],b[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	  a[b[i]]=i;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		printf("%d ",max(a[b[i]]-last,0));
		last=max(last,a[b[i]]);
	}
	printf("\n");
	return 0;
}