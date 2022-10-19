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
char s[100001],ts[100001];
bool check(int i,char c)
{
	if(s[i]==c||s[i]=='?')return true;
	return false;
}
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		flag=true;
		for(int i=n-6;i>=1;i--)
		{
			flag=true;
			if(check(i,'a')&&check(i+1,'b')&&check(i+2,'a')&&check(i+3,'c')&&check(i+4,'a')&&check(i+5,'b')&&check(i+6,'a'))
			{
				ts[i]='a';
				ts[i+1]='b';
				ts[i+2]='a';
				ts[i+3]='c';
				ts[i+4]='a';
				ts[i+5]='b';
				ts[i+6]='a';
				for(int j=1;j<=n;j++)
				{
					if(j>=i&&j<=i+6)continue;
					if(s[j]!='?')ts[j]=s[j];
					else ts[j]='d';
				}
				ts[n+1]=0;
				flag=false;
				for(int j=1;j<=n-6;j++)
				{
					if(j==i)continue;
					if(ts[j]=='a'&&ts[j+1]=='b'&&ts[j+2]=='a'&&ts[j+3]=='c'&&ts[j+4]=='a'&&ts[j+5]=='b'&&ts[j+6]=='a')
				    {
				    	flag=true;
				    	break;
					}
				}
				if(flag==false)
				{
					printf("Yes\n");
					printf("%s\n",ts+1);
					break;
				}
			}
		}
		if(flag==true)printf("No\n");
	}
	return 0;
}