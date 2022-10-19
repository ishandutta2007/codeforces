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
char str[300005];
int qz[300005];
int main()
{
	int t,n,q,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='+')
			{
				if(i%2==1)qz[i]=qz[i-1]+1;
				else qz[i]=qz[i-1]-1;
			}
			else
			{
				if(i%2==1)qz[i]=qz[i-1]-1;
				else qz[i]=qz[i-1]+1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			l=read();
			r=read();
			if((qz[r]-qz[l-1])==0)printf("0\n");
			else if((qz[r]-qz[l-1])%2==0)printf("%d\n",2);
			else printf("%d\n",1);
		}
	}
	return 0;
}