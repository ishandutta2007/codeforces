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
int n,x;
int a[120];
int b[120];
int c[10];
int main()
{
	cin>>n;
	cin>>x;
	if(x>3)
		x=7-x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		scanf("%d",b+i);
		if(a[i]>3)
			a[i]=7-a[i];
		if(b[i]>3)
			b[i]=7-b[i];
	}
	for(int i=0;i<n;i++)
	{
		c[6-a[i]-b[i]]++;
	}
	for(int i=1;i<4;i++)
		if(c[i]==n)
		{
			if(i==x)
			{
				puts("YES");
				return 0;
			}
		}
	puts("NO");
	return 0;
}