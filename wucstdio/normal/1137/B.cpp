#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[500005],t[500005],ans[500005];
int n,m,nxt[500005],num1,num0;
int main()
{
	scanf("%s%s",s+1,t+1);
	n=(int)strlen(s+1);
	m=(int)strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')num1++;
		else num0++;
	}
	for(int i=2;i<=m;i++)
	{
		int j=nxt[i-1];
		while(j&&t[j+1]!=t[i])j=nxt[j];
		if(t[j+1]==t[i])nxt[i]=j+1;
		else nxt[i]=0;
	}
	int p=nxt[m]+1;
	int top=0;
	for(int i=1;i<=m;i++)
	{
		if(t[i]=='1')
		{
			if(num1==0)
			{
				printf("%s\n",s+1);
				return 0;
			}
			num1--;
			ans[++top]='1';
		}
		else
		{
			if(num0==0)
			{
				printf("%s\n",s+1);
				return 0;
			}
			num0--;
			ans[++top]='0';
		}
	}
	while(num1||num0)
	{
		for(int i=p;i<=m;i++)
		{
			if(t[i]=='1')
			{
				if(num1==0)
				{
					while(num0)
					{
						num0--;
						ans[++top]='0';
					}
					break;
				}
				num1--;
				ans[++top]='1';
			}
			else
			{
				if(num0==0)
				{
					while(num1)
					{
						num1--;
						ans[++top]='1';
					}
					break;
				}
				num0--;
				ans[++top]='0';
			}
		}
	}
	ans[++top]='\0';
	printf("%s\n",ans+1);
	return 0;
}