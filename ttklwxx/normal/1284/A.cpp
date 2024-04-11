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
char strn[101][101],strm[101][101]; 
int main()
{
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)scanf("%s",strn[i]);
    for(int i=1;i<=m;i++)scanf("%s",strm[i]);
    int q,x;
    q=read();
    for(int i=1;i<=q;i++)
    {
    	x=read()-1;
    	printf("%s%s\n",strn[x%n+1],strm[x%m+1]);
	}
    return 0;
}