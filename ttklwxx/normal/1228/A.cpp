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
int l,r;
bool b[10];
bool check(int x)
{
	for(int i=0;i<=9;i++)b[i]=0;
	while(x!=0)
	{
		if(b[x%10]==1)return false;
		b[x%10]=1;
		x/=10;
	}
	return true;
} 
int main()
{
    l=read();
    r=read();
    for(int i=l;i<=r;i++)
    {
    	if(check(i))
		{
    		printf("%d\n",i);
    		return 0;
		}
	}
	printf("-1\n");
    return 0;
}