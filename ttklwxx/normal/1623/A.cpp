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
	int t,n,m,x1,y1,x2,y2,tx,ty,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		tx=1;
		ty=1;
		ans=0;
		while(x1!=x2&&y1!=y2)
		{
			//printf("%d %d\n",x1,y1);
			if(x1+tx>n||x1+tx<=0)tx=-tx;
			if(y1+ty>m||y1+ty<=0)ty=-ty;
			x1+=tx;
			y1+=ty;
			ans++;
		}
		printf("%d\n",ans);
	} 
	return 0;
}