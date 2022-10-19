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
char s[100005],str[100005];
int n;
int sl[105];
int slb[105];
int main()
{
	int t,n,m;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",str+1);
		scanf("%s",s+1);
		n=strlen(str+1);
		m=strlen(s+1);
		for(int i=1;i<=26;i++)sl[i]=0,slb[i]=0;
		for(int i=1;i<=n;i++)sl[str[i]-'a'+1]++;
		for(int i=1;i<=m;i++)slb[s[i]-'a'+1]++;
		flag=true;
		for(int i=1;i<=m;i++)
		{
			if(sl[s[i]-'a'+1]<slb[s[i]-'a'+1])
			{
				flag=false;
				break;
			}
			else if(i>=2&&s[i]<s[i-1])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			for(int i=1;i<=26;i++)
			{
				for(int j=1;j<=sl[i];j++)printf("%c",'a'+i-1);
			}
			printf("\n");
			continue;
		}
		for(int i=1;i<=26;i++)
		{
			if(i==s[m-1]-'a'+1)
			{
				for(int j=1;j<=slb[i]-1;j++)printf("%d ",'a'+i-1);
				continue;
			}
			for(int j=1;j<=sl[i];j++)printf("%c",'a'+i-1);
			if(i==s[m]-'a'+1)
			{
				for(int j=1;j<=sl[s[m-1]-'a'+1]-slb[i]+1;j++)printf("%c",s[m-1]);
			}
		}
		printf("\n");
	} 
	return 0;
}