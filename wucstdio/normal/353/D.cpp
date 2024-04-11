#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1000005],t,now,ans=1;
char s[1000005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]=='F';
	int i=1;
	while(a[i]==1&&i<=n)i++,now++;
	for(;i<=n;i++)
	{
		if(a[i]==0)t=max(t-1,0);
		else
		{
			t++;
			now++;
			ans=max(ans,t+i-now);
		}
//		printf("%d ",t);
	}
	printf("%d\n",ans-1);
	return 0;
}