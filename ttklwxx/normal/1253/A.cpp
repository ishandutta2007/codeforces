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
int a[200001],b[200001];
int main()
{
    int t,n,l,r;
    bool flag;
    t=read();
    for(int greg=1;greg<=t;greg++)
    {
    	n=read();
    	for(int i=1;i<=n;i++)a[i]=read();
    	for(int i=1;i<=n;i++)b[i]=read()-a[i];
    	l=1;
    	while(l<=n&&b[l]==0)l++;
    	r=n;
    	while(r>=1&&b[r]==0)r--;
    	if(l>r)
    	{
    		printf("Yes\n");
    		continue;
		}
    	if(b[l]<0)
    	{
    		printf("No\n");
    		continue;
		}
    	if(l>=r)
    	{
    		printf("Yes\n");
    		continue;
		}
		flag=false;
		for(int i=l+1;i<=r;i++)
		{
			if(b[i]!=b[l])
			{
				printf("No\n");
				flag=true;
				break;
			}
		}
		if(flag==false)printf("Yes\n");
	}
	return 0;
}