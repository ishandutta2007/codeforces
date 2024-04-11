#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[105];
int main()
{
	scanf("%d",&n);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)res++;
	}
	printf("%d\n",min(res,n-res));
	return 0;
}