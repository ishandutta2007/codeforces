#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[2005],a[2005],b[2005];
int t,n,cnt[35];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
		int tot1=0,tot2=0;
		for(int i=24;i>=0;i-=2)
		{
			while(cnt[i])
			{
				a[++tot1]=(char)(i+'a');
				cnt[i]--;
			}
		}
		for(int i=25;i>=1;i-=2)
		{
			while(cnt[i])
			{
				b[++tot2]=(char)(i+'a');
				cnt[i]--;
			}
		}
		a[tot1+1]='\0';
		b[tot2+1]='\0';
		if(fabs(a[1]-b[tot2])!=1)printf("%s%s\n",b+1,a+1);
		else if(fabs(a[tot1]-b[1])!=1)printf("%s%s\n",a+1,b+1);
		else printf("No answer\n");
	}
	return 0;
}