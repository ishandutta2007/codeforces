#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans;
char a[100005],b[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s%s",a,b);
	n--;
	for(int i=0;i*2<n;i++)
	{
		if(a[i]==a[n-i])
		{
			if(b[i]==b[n-i])continue;
			else if(b[i]==a[i]||b[n-i]==a[n-i])
			{
				ans++;
				continue;
			}
			else
			{
				ans+=2;
				continue;
			}
		}
		else
		{
			if(b[i]==a[i]&&b[n-i]==a[n-i]||b[i]==a[n-i]&&b[n-i]==a[i])continue;
			else if(b[i]==b[n-i])
			{
				ans++;
				continue;
			}
			else if(a[i]==b[i]||a[n-i]==b[i]||a[i]==b[n-i]||a[n-i]==b[n-i])
			{
				ans++;
				continue;
			}
			else ans+=2;
		}
	}
	if(n%2==0&&a[n/2]!=b[n/2])ans++;
	printf("%d\n",ans);
	return 0;
}