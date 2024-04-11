#include<iostream>
#include<cstdio>
#define mod 1000000007
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
int ksm(int n,int k)
{
	if(k==0)return 1;
	if(k==1)return n;
	int nn=ksm(n,k/2);
	if(k%2==1)return 1LL*nn*nn%mod*1LL*n%mod;
	else return 1LL*nn*nn%mod; 
}
int a[1005][1005];
int main()
{
    int n,m,x,sth;
    n=read();
    m=read();
    sth=n*m;
    for(int i=1;i<=n;i++)
    {
    	x=read();
    	for(int j=1;j<=x;j++)
    	{
    		if(a[i][j]==1)
    		{
    			printf("0\n");
    			return 0;
			}
			if(a[i][j]==0)sth--;
			a[i][j]=2;
		}
		if(x!=m)
		{
			if(a[i][x+1]==2)
			{
				printf("0\n");
				return 0;
			}
			if(a[i][x+1]==0)sth--;
			a[i][x+1]=1;
		}
	}
	for(int i=1;i<=m;i++)
    {
    	x=read();
    	for(int j=1;j<=x;j++)
    	{
    		if(a[j][i]==1)
    		{
    			printf("0\n");
    			return 0;
			}
			if(a[j][i]==0)sth--;
			a[j][i]=2;
		}
		if(x!=n)
		{
			if(a[x+1][i]==2)
			{
				printf("0\n");
				return 0;
			}
			if(a[x+1][i]==0)sth--;
			a[x+1][i]=1;
		}
	}
	printf("%d\n",ksm(2,sth));
    return 0;
}