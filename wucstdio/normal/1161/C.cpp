#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[55];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n/2+1]==a[1])printf("Bob\n");
	else printf("Alice\n");
	return 0;
}