#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1005
int a[N],n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)ans+=a[i]-a[i-1]-1;
	printf("%d\n",ans);return 0;
}