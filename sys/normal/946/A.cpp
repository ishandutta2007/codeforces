#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int sum[105],num[105],n,a,b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
        if(num[i]<=0) b+=num[i];
        else a+=num[i];
	}
	printf("%d",a-b);
	return 0;
}