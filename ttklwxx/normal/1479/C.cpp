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
int ansu[200005],ansv[200005],answ[200005],cnt;
int main()
{
	int l,r,n=32;
	l=read();
	r=read();
	for(int i=0;i<=20;i++)
	{
		ansu[++cnt]=1;
		ansv[cnt]=i+2;
		answ[cnt]=1;
		for(int j=2;j<=i+1;j++)
		{
			ansu[++cnt]=j;
			ansv[cnt]=i+2;
			answ[cnt]=(1<<(j-2));
		}
	}
	if(l==1)
	{
		ansu[++cnt]=1;
		ansv[cnt]=n;
		answ[cnt]=1;
		l++;
	}
	for(int j=19;j>=0;j--)
	{
		if((1<<j)<=r-l+1)
		{
			ansu[++cnt]=j+2;
			ansv[cnt]=n;
			answ[cnt]=l-1;
			l+=(1<<j);
		}
	}
	printf("YES\n");
	printf("%d %d\n",n,cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d %d\n",ansu[i],ansv[i],answ[i]);
	return 0;
}