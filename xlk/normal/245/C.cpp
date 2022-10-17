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
int n,a[10020],z;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>0;i--)
	{
		while(i*2+1<=n&&a[i*2]||a[i*2+1])
		{
			a[i]=max(0,a[i]-1);
			a[i*2]=max(0,a[i*2]-1);
			a[i*2+1]=max(0,a[i*2+1]-1);
			z++;
		}
	}
	z+=a[1];
	if(n%2==0||n<3&&a[2]+a[1])
		z=-1;
	printf("%d",z);
}