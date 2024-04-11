#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,k,e,z,y;
int a[100020];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;)
	{
		for(;e<n&&k>=a[i]-a[e];e++)
			k-=a[i]-a[e];
		if(e-i>=z)
		{
			z=e-i;
			y=a[i];
		}
		i++;
		k+=(a[i-1]-a[i])*(e-i);
	}
	printf("%d %d\n",z,y);
	return 0;
}