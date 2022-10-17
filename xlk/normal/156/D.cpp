#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int f[1000020];
int c[1000020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	int fx=F(x);
	int fy=F(y);
	if(fx==fy)
	    return;
	c[fx]+=c[fy];
	f[fy]=fx;
	return;
}
vector<int>a;
long long z=1;
int n,m,p,x,y,i;
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for(i=1;i<=n;i++)
		c[f[i]=i]=1;
	while(m--)
	    scanf("%d %d",&x,&y),U(x,y);
	for(i=1;i<=n;i++)
		if(f[i]==i)
		    a.push_back(c[i]);
	if(a.size()>1)
	{
	    for(i=0;i<a.size()-2;i++)
	        z=z*n%p;
	    for(i=0;i<a.size();i++)
	        z=z*a[i]%p;
	}
	printf("%I64d",z%p);
	return 0;
}