#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int f[300];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int n,m;
int z[10020],zc;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		z^=1;
		if(z==0)
		{
			U(x,y);
			U(x+n,y+n);
		}
		else if(z==1)
		{
			U(x,y+n);
			U(x+n,y);			
		}
	}
	for(int i=1;i<=n;i++)
		if(F(i)==F(i+n))
		{
			puts("Impossible");
			return 0;
		}
	for(int i=1;i<=n;i++)
		if(F(i)!=F(1)&&F(i+n)!=F(1))
			U(1,i);
	for(int i=1;i<=n;i++)
		if(F(i)==F(1))
			z[zc++]=i;
	cout<<zc<<endl;
	for(int i=0;i<zc;i++)
		printf("%d ",z[i]);
	return 0;
}