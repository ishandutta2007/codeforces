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
    int n,q;
	q=read();
	for(int i=1;i<=q;i++)
	{
		n=read();
		if(n==2)printf("2\n");
		else if(n%2==1)printf("1\n");
		else printf("0\n");
	 } 
    return 0;
}