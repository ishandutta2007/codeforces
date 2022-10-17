#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,i,j,z,k,cnt;
int a[1020];
int b[1020];
int v[1020];
int main()
{
	scanf("%d",&n);
	k=1;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",a+i,b+i);
		if(b[i])
		{
			z+=a[i];
			k+=b[i]-1;	
		}
		else
		{
			v[cnt++]=a[i];	
		}
	}
	sort(v,v+cnt);
	for(i=cnt-1;i>=0;i--)
	{
		if(k==0)
			break;
		z+=v[i];
		k--;
	}
	printf("%d",z);
	return 0;
}