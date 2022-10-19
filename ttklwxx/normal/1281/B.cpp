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
char c[100001],s[100001];
int clen,slen,cmin,smin;
bool change()
{
	for(int i=1;i<=min(clen,slen);i++)
	{
		if(c[i]<s[i])return true;
		else if(c[i]==s[i])
		{
			for(int j=i+1;j<=clen;j++)
			{
				if(c[j]<c[i])
				{
					swap(c[i],c[j]);
					return true;
				}
			}
		}
		else
		{
			for(int j=i+1;j<=clen;j++)
			{
				if(c[j]<s[i])
				{
					swap(c[i],c[j]);
					return true;
				}
			}
			for(int j=clen;j>=i+1;j--)
			{
				if(c[j]==s[i])
				{
					swap(c[i],c[j]);
					for(int k=i+1;k<=min(clen,slen);k++)
					{
						if(c[k]<s[k])return true;
						if(c[k]>s[k])return false;
					}
					if(clen<slen)return true;
					else return false;
				}
			}
			return false;
		}
	}
	if(clen<slen)return true;
	else return false;
}
int main()
{
    int n,len;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	scanf("%s%s",c+1,s+1);
    	clen=strlen(c+1);
    	slen=strlen(s+1);
    	if(!change())printf("---\n");
    	else printf("%s\n",c+1);
	}
    return 0;
}