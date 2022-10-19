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
int a[200005];
int f(int x,int y)
{
   if(x==y) return 1;
   int k=1<<__lg(a[x]^a[y]);
   int i;
   for(i=x;i<=y;i++) if(a[i]&k) break;
   return 1+max(f(x,i-1),f(i,y));
}
int main()
{
    int n,i;
    n=read();
    for(i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    printf("%d\n",n-f(1,n));
    return 0;
}