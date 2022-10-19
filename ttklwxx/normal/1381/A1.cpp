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
char s[200001],t[200001];
int nz,ji;
int cz[300001],sl;
int f(int x)
{
	if(nz==1)return ji-x;
	else return x+ji;
}
int main()
{
	int tttt,n;
	tttt=read();
	for(int greg=1;greg<=tttt;greg++)
	{
		n=read();
		scanf("%s",s+1);
		scanf("%s",t+1);
		nz=0;
		ji=0;
		sl=0;
		for(int i=n;i>=1;i--)
		{
			if(nz==0&&s[f(1)]==t[i])cz[++sl]=1,s[f(1)]='0'+'1'-s[f(1)];
			if(nz==1&&s[f(1)]!=t[i])cz[++sl]=1,s[f(1)]='0'+'1'-s[f(1)];
			if(nz==0)
			{
				nz=1;
				ji=n+1-ji;
			}
			else
			{
				nz=0;
				ji=n+2-ji;
			}
			cz[++sl]=i;
		}
		printf("%d ",sl);
		for(int i=1;i<=sl;i++)printf("%d ",cz[i]);
		printf("\n");
	} 
	return 0;
}