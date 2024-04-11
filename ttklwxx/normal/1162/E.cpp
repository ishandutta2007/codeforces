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
int a[1001];
int main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	if(a[1]==a[n/2+1])printf("Bob\n");
	else printf("Alice\n");
	return 0;
}