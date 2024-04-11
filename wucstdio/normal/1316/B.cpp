#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[5005],ans[5005],res[5005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)ans[i]=s[i];
		int len=1;
		for(int i=2;i<=n;i++)
		{
			int top=0;
			for(int j=i;j<=n;j++)res[++top]=s[j];
			if((n-i+1)&1)for(int j=i-1;j>=1;j--)res[++top]=s[j];
			else for(int j=1;j<i;j++)res[++top]=s[j];
			bool flag=0;
			for(int j=1;j<=n;j++)
			{
				if(res[j]<ans[j])
				{
					flag=1;
					break;
				}
				if(res[j]>ans[j])break;
			}
			if(flag)
			{
				len=i;
				for(int j=1;j<=n;j++)
				  ans[j]=res[j];
			}
		}
		ans[n+1]='\0';
		printf("%s\n",ans+1);
		printf("%d\n",len);
	}
	return 0;
}