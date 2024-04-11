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
int main()
{
    int t,n;
    bool flag;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	for(int j=1;j<=n;j++)a[j]=read();
    	flag=false;
    	for(int j=2;j<=n;j++)
    	{
    		if(a[j]-a[j-1]>1||a[j-1]-a[j]>1)
    		{
    			printf("YES\n%d %d\n",j-1,j);
    			flag=true;
    			break;
			}
		}
		if(flag==false)
		{
			printf("NO\n");
		}
	}
    return 0;
}