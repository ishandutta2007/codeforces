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
char s[400005];
int qzh[400005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=2*n;i++)
		{
			if(s[i]=='(')qzh[i]=qzh[i-1]+1;
			else qzh[i]=qzh[i-1]-1;
		}
		int nl=-1,nr=-1,mpos=2*n;
		for(int i=1;i<=2*n;i++)
		{
			if(qzh[i]<0)
			{
				if(nl==-1)nl=i;
				nr=i;
			}
			if(qzh[mpos]<qzh[i])mpos=i;
		}
		if(nl==-1)
		{
			printf("0\n");
			continue;
		}
		int maxl=0,maxr=2*n;
		for(int i=1;i<nl;i++)if(qzh[maxl]<qzh[i])maxl=i;
		for(int i=nr+1;i<=2*n;i++)if(qzh[maxr]<qzh[i])maxr=i;
	//	printf("%d %d %d\n",maxl,maxr,mpos);
		if(qzh[maxl]+qzh[maxr]>=qzh[mpos])
		{
			printf("1\n%d %d\n",maxl+1,maxr);
		}
		else
		{
			printf("2\n%d %d\n%d %d\n",maxl+1,mpos,mpos+1,maxr);
		}
	}
	return 0;
}