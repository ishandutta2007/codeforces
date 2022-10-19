
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
char s[200005];
char tans1[200005],tans2[200005];
int main()
{
	int t,n,x,y,sl;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		x=0;
		y=0;
		sl=0;
		for(int i=1;i<=n;i++)if(s[i]=='1')sl++;
		if(sl%2!=0)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				x++;
				if(x<=sl/2)tans2[i]=tans1[i]='(';
				else tans2[i]=tans1[i]=')';
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				y++;
				if(y%2==1)tans2[i]=')',tans1[i]='(';
				else tans2[i]='(',tans1[i]=')';
			}
		}
		tans1[n+1]=tans2[n+1]=0;
		flag=false;
		x=0;
		y=0;
		for(int i=1;i<=n;i++)
		{
			if(tans1[i]=='(')x++;
			else x--;
			if(tans2[i]=='(')y++;
			else y--;
			if(x<0||y<0)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("NO\n");
		else
		{
			printf("YES\n%s\n%s\n",tans1+1,tans2+1);
		}
	}
	return 0;
}