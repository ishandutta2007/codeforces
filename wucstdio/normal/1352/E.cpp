#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[8005];
bool flag[8005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),flag[i]=0;
		for(int i=1;i<=n;i++)
		{
			int s=a[i];
			for(int j=i+1;j<=n;j++)
			{
				s+=a[j];
				if(s<=n)flag[s]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		  if(flag[a[i]])ans++;
		printf("%d\n",ans);
	}
	return 0;
}