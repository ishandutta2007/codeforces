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
double f[106];
int id[15][15],nex[105],cnt;
int main()
{
    for(int i=10;i>=1;i--)
    {
    	if(i&1)
    	{
    		for(int j=10;j>=1;j--)id[i][j]=++cnt;
		}
		else
		{
			for(int j=1;j<=10;j++)id[i][j]=++cnt;
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			nex[id[i][j]]=id[i-read()][j];
		}
	}
	for(int i=99;i>=94;i--)f[i]=6;
	for(int i=93;i>=1;i--)
	{
		for(int j=1;j<=6;j++)f[i]+=min(f[i+j],f[nex[i+j]]);
		f[i]=f[i]/6+1;
	}
	printf("%.10lf\n",f[1]);
	return 0;
}