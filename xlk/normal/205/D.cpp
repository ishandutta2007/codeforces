#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[100020][2];
int n,x,y,z=0x3f3f3f3f;
map<int,int>c;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",a[i]+0,a[i]+1);
		c[a[i][0]]++;
		c[a[i][1]]++;
	}
	fe(i,c)
		if(i->Y>=(n+1)/2)
		{
			int t=i->X;
			x=y=0;
			for(int i=0;i<n;i++)
				if(a[i][0]==t)
					x++;
				else if(a[i][1]==t)
					y++;
			if(x+y>=(n+1)/2)
				z=min(z,(n+1)/2-x);
		}
	z=max(z,0);
	if(z==0x3f3f3f3f)
		puts("-1");
	else
		printf("%d",z);
}