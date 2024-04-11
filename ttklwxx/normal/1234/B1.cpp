#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
int dy[200001];
int main()
{
    int n,k,x,nown;
    n=read();
    k=read();
    nown=0;
    for(int i=1;i<=n;i++)
    {
    	x=read();
    	if(ma[x]!=0&&ma[x]>=nown-k+1)continue;
    	ma[x]=++nown;
    	dy[nown]=x;
	}
	printf("%d\n",min(nown,k));
	for(int i=nown;i>=nown-min(nown,k)+1;i--)printf("%d ",dy[i]);
    return 0;
}