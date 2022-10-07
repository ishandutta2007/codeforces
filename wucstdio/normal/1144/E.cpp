#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005],t[200005];
int n,num[200005],ans[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)
	  num[i]=t[i]-s[i];
	for(int i=n;i>=1;i--)
	{
		if(num[i]<0)
		{
			num[i]+=26;
			num[i-1]--;
		}
		if(num[i]&1)num[i]--,num[i+1]+=26;
	}
	for(int i=n;i>=1;i--)
		ans[i]=s[i]+num[i]/2-'a';
	for(int i=n;i>=1;i--)
	{
		ans[i-1]+=ans[i]/26;
		ans[i]%=26;
	}
	for(int i=1;i<=n;i++)
	  putchar(ans[i]+'a');
	putchar('\n');
	return 0;
}