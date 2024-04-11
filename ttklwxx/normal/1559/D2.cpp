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
int f1[200005],f2[200005];
int findf1(int n)
{
	if(f1[n]==n)return n;
	return f1[n]=findf1(f1[n]);
}
int findf2(int n)
{
	if(f2[n]==n)return n;
	return f2[n]=findf2(f2[n]);
}
int ansu[200005],ansv[200005],cnt;
int s1[200005],t1;
int s2[200005],t2;
int main()
{
	int n,m1,m2;
	n=read();
	m1=read();
	m2=read();
	int x,y;
	for(int i=1;i<=n;i++)f1[i]=f2[i]=i;
	for(int i=1;i<=m1;i++)
	{
		x=read();
		y=read();
		x=findf1(x);
		y=findf1(y);
		f1[x]=y;
	}
	for(int i=1;i<=m2;i++)
	{
		x=read();
		y=read();
		x=findf2(x);
		y=findf2(y);
		f2[x]=y;
	}
	int sth=0; 
	for(int i=2;i<=n;i++)
	{
		if(findf1(i)!=findf1(1)&&findf2(i)!=findf2(1))
		{
			ansu[++cnt]=1;
			ansv[cnt]=i;
			x=findf1(1);
			y=findf1(i);
			f1[y]=x;
			x=findf2(1);
			y=findf2(i);
			f2[y]=x;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(findf1(i)==findf1(1)&&findf2(i)!=findf2(1))s1[++t1]=i;
		if(findf1(i)!=findf1(1)&&findf2(i)==findf2(1))s2[++t2]=i;
	}
	while(1)
	{
		while(t1>=1&&(findf1(s1[t1])!=findf1(1)||findf2(s1[t1])==findf2(1)))t1--;
		while(t2>=1&&(findf1(s2[t2])==findf1(1)||findf2(s2[t2])!=findf2(1)))t2--;
		if(t1==0||t2==0)break;
		ansu[++cnt]=s1[t1];
		ansv[cnt]=s2[t2];
		x=findf1(s1[t1]);
		y=findf1(s2[t2]);
		f1[y]=x;
		x=findf2(s1[t1]);
		y=findf2(s2[t2]);
		f2[y]=x;
		t1--;
		t2--;
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%lld %lld\n",ansu[i],ansv[i]);
	return 0;
}