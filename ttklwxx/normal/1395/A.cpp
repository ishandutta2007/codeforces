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
int sl[2];
int main()
{
	int t,r,g,b,w;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		r=read();
		b=read();
		g=read();
		w=read();
		sl[0]=sl[1]=0;
		sl[r%2]++;
		sl[b%2]++;
		sl[g%2]++;
		sl[w%2]++;
		if(sl[0]>=3)printf("Yes\n");
		else if(sl[1]>=3)
		{
			if(r==0||b==0||g==0)printf("No\n");
			else printf("Yes\n");
		}
		else printf("No\n");
	} 
	return 0;
}