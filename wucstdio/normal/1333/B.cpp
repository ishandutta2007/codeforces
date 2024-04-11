#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005],b[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		bool f1=0,f2=0,flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<b[i]&&!f1)flag=0;
			if(a[i]>b[i]&&!f2)flag=0;
			if(a[i]==1)f1=1;
			if(a[i]==-1)f2=1;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}