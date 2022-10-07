#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],ans,p[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==i)ans++;
		p[a[i]]=i;
	}
	if(ans==n)
	{
		printf("%d\n",n);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i]!=i&&p[p[i]]==i)
		{
			printf("%d\n",ans+2);
			return 0;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}