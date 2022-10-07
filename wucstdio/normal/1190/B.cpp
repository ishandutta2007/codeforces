#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int num=0;
	a[0]=-1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1]&&a[i]==a[i-1]+1)return puts("cslnb"),0;
		if(a[i]==a[i+1])num++;
	}
	if(num>=2)return puts("cslnb"),0;
	int tot=0;
	for(int i=1;i<=n;i++)tot^=(a[i]-i+1)&1;
	puts(tot?"sjfnb":"cslnb");
	return 0;
}