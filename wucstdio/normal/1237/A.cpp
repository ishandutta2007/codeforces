#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],flag;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==0)printf("%d\n",a[i]/2);
		else
		{
			if(flag)printf("%d\n",(a[i]+1)/2);
			else printf("%d\n",(a[i]-1)/2);
			flag^=1;
		}
	}
	return 0;
}