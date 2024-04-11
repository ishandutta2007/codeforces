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
int main()
{
	int t,n,x,y,maxx,minx,maxy,miny;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		maxx=0;
		minx=0;
		maxy=0;
		miny=0;
		for(int i=1;i<=n;i++)
		{
			x=read();
			y=read();
			maxx=max(maxx,x);
			minx=min(minx,x);
			maxy=max(maxy,y);
			miny=min(miny,y);
		}
		printf("%d\n",2*maxy-2*miny+2*maxx-2*minx);
	}
	return 0;
}