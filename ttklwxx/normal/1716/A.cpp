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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=1000000000;
		if((n-2)%3==0)ans=min(ans,jdz((n-2)/3)+1);
		if((n-4)%3==0)ans=min(ans,jdz((n-4)/3)+2);
		if((n+2)%3==0)ans=min(ans,jdz((n+2)/3)+1);
		if((n+4)%3==0)ans=min(ans,jdz((n+4)/3)+2);
		if(n%3==0)ans=min(ans,jdz(n/3));
		printf("%d\n",ans);
	}
	return 0;
}