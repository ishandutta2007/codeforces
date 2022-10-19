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
int rd[200001];
int main()
{
	int n,mb,x,y,t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	n=read();
	mb=read();
	for(int i=1;i<=n;i++)rd[i]=0;
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		rd[x]++;
		rd[y]++;
	}
	if(rd[mb]<=1)
	{
	    printf("Ayush\n");
	    continue;
    }
    if(n%2==0)printf("Ayush\n");
    else printf("Ashish\n");
    }
	return 0;
}