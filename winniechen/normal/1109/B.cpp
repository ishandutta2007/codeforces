#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 5005
#define ll long long
char a[N];int n;
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	if(n==1||n==2)return puts("Impossible"),0;
	register int i,j,mid=n>>1;
	for(i=mid;i>=1;i--)
	{
		for(j=1;j<=i;j++)if(a[j]!=a[i-j+1])break;
		if(j!=i+1)break;
	}
	if(i==0)return puts("Impossible"),0;
	if(i*2==n)return puts("1"),0;
	else
	{
		for(i=n+1;i<=2*n;i++)a[i]=a[i-n];
		for(i=2;i<=n;i++)
		{
			for(j=i;j<=i+n-1;j++)if(a[j]!=a[i+i+n-j-1])break;
			if(j==i+n)
			{
				for(j=i;j<=i+n-1;j++)if(a[j]!=a[j-i+1])break;
				if(j!=i+n)return puts("1"),0;
			}
		}
		puts("2");
	}
}