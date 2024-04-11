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
char s[200005];
int sl[10];
bool check(int n)
{
	int x=0;
	for(int i=1;i<=n;i++)
	{
		x+=sl[s[i]-'A'+1];
		if(x<0)return false;
	}
	if(x==0)return true;
	else return false;
}
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		flag=false;
		for(sl[1]=-1;sl[1]<=1;sl[1]+=2)for(sl[2]=-1;sl[2]<=1;sl[2]+=2)for(sl[3]=-1;sl[3]<=1;sl[3]+=2)
	    {
	    	if(check(n)==true)
	    	{
	    		flag=true;
	    		break;
			}
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}