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
int n,k;
int c[1000020];
int main()
{
	cin>>n>>k;
	if(k*3>n)
	{
		puts("-1");
	}
	else
	{
		for(int i=1;i<k;i++)
		{
			if(i&1)
			{
				c[i*3-1]=i;
				c[i*3]=i;
				c[i*3+2]=i;
			}
			else
			{
				c[i*3-2]=i;
				c[i*3]=i;
				c[i*3+1]=i;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",c[i]+1);
	}
}