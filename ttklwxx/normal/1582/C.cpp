#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char str[200005];
int sl[200005],zm[200005],cnt;
signed main()
{
	int t,n,ans,now;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str+1);
		ans=1000000000;
		for(int i=0;i<=25;i++)
		{
			cnt=0;
			for(int j=0;j<=n;j++)sl[j]=0;
			for(int j=1;j<=n;j++)
			{
				if(str[j]!='a'+i)
				{
					zm[++cnt]=str[j];
				}
				else
				{
					sl[cnt]++;
				}
			}
			flag=false;
			for(int j=1;j<=cnt;j++)
			{
				if(zm[j]!=zm[cnt+1-j])
				{
					flag=true;
					break;
				}
			}
			if(flag==true)continue;
			now=0;
			for(int j=0;j<=cnt/2;j++)
			{
				now+=max(sl[j],sl[cnt-j])-min(sl[j],sl[cnt-j]);
			//	printf("%d %d\n",sl[j],sl[cnt-j]);
			}
			ans=min(ans,now);
		}
		if(ans!=1000000000)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}