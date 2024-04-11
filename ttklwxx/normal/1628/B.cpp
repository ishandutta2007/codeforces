#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[100005][10];
int len[100005];
int sz[100005];
int cz[100005];
int main()
{
	int t,n,x,sth,gre;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			len[i]=strlen(s[i]+1);
			sz[i]=0;
			for(int j=1;j<=len[i];j++)sz[i]=sz[i]*27+s[i][j]-'a'+1;
			cz[sz[i]]++;
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(len[i]==1)
			{
				flag=true;
				break;
			}
			if(len[i]==2)
			{
				if(s[i][1]==s[i][2])
				{
					flag=true;
					break;
				}
				sth=(s[i][2]-'a'+1)*27+s[i][1]-'a'+1;
				for(int j=0;j<=26;j++)
				{
					if(cz[j*27*27+sth])
					{
						flag=true;
						break;
					}
				}
			}
			if(len[i]==3)
			{
				if(s[i][1]==s[i][3])
				{
					flag=true;
					break;
				}
				sth=(s[i][2]-'a'+1)*27+(s[i][1]-'a'+1);
				if(cz[sth])
				{
					flag=true;
					break;
				}
				sth+=(s[i][3]-'a'+1)*27*27; 
				if(cz[sth])
				{
					flag=true;
					break;
				}
			}
			if(flag==true)break;
			cz[sz[i]]--;
		}
		for(int i=1;i<=n;i++)cz[sz[i]]=0;
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}