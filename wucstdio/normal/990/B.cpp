#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[200005],ans,num=1;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		if(a[i]+k<a[i+1])
		{
			ans+=num;
			num=1;
		}
		else if(a[i]==a[i+1])num++;
		else num=1;
	}
	printf("%d\n",ans+num);
	return 0;
}