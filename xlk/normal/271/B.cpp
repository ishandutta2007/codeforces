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
int a[520][520];
int b[520][520];
int p[110020];
int n,m;
int P(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",a[i]+j);
	for(int i=0;i<110000;i++)
		p[i]=P(i);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			b[i][j]=0;
			while(!p[a[i][j]+b[i][j]])
				b[i][j]++;
		}
	long long z=0x3f3f3f3f3f3fLL;
	for(int i=0;i<n;i++)
	{
		long long u=0;
		for(int j=0;j<m;j++)
			u+=b[i][j];
		z=min(z,u);
	}
	for(int j=0;j<m;j++)
	{
		long long u=0;
		for(int i=0;i<n;i++)
			u+=b[i][j];
		z=min(z,u);
	}
	cout << z << endl;
}