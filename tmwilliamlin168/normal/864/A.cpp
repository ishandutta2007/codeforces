#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int a[110];
int main()
{
	int n;
	scanf("%d",&n);
	if(n&1)
	{
		printf("NO\n");
		return 0;
	}
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m=n/2;
	for(i=1;i<m;i++)
		if(a[i]!=a[i+1])
		{
			printf("NO\n");
			return 0;
		}
	for(i=m+1;i<n;i++)
		if(a[i]!=a[i+1])
		{
			printf("NO\n");
			return 0;
		}
	if(a[m]==a[m+1])
	{
		printf("No\n");
		return 0;
	}
	printf("YES\n");
	printf("%d %d\n",a[1],a[m+1]);
	return 0;
}