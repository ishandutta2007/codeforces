#include<iostream>
#include<cstdio>
#include<algorithm>
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
int pos[200005];
int n,m; 
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int dis(int pos)
{
	int x=(pos-1)/m+1,y=(pos-1)%m+1;
	return jdz(2*x-n-1)+jdz(2*y-m-1);
}
bool bi(int x,int y)
{
	return dis(x)<dis(y); 
}
int main()
{
	int t,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		x=1;
		for(int i=1;i<=n*m;i++)pos[i]=i;
		sort(pos+1,pos+n*m+1,bi);
		for(int i=1;i<=n*m;i++)
		{
			if(n%2==1&&m%2==1)printf("%d ",(n-1)/2+(m-1)/2+dis(pos[i])/2);
			else printf("%d ",(n-1)/2+(m-1)/2+dis(pos[i])/2+1);
		}
		printf("\n");
	}
	return 0;
}