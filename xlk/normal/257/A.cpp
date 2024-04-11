#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[1020],m,k;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	if(k>=m)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		k+=a[i]-1;
		if(k>=m)
		{
			printf("%d",i+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}