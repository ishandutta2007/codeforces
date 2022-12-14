#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <bitset>
using namespace std;
#define N 100005
int a[N],n,p[N],sp,b[N],K;
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=a[i];
	sort(p+1,p+n+1);sp=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(p+1,p+sp+1,a[i])-p;
	for(int i=1;i<=n;i++)b[a[i]]=1;
	for(int i=1,last=0;i<=sp;i++)
	{
		if(b[i])
		{
			printf("%d\n",p[i]-last);
			K--;last=p[i];
		}
		if(!K)break;
	}
	while(K--)puts("0");
}