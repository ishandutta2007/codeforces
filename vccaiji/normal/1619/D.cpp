#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110000];
bool check(int t)
{
	for(int j=0;j<n;j++)
	{
		int num=0;
		for(int i=j;i<m*n;i+=n)
		 if(a[i]>=t) num++;
		if(num==0) return false;
	}
	for(int j=0;j<m*n;j+=n)
	{
		int num=0;
		for(int i=0;i<n;i++)
		{
			if(a[i+j]>=t) num++;
		}
		if(num>=2) return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<m*n;i++) scanf("%d",&a[i]);
		int l=1,r=1e9+10;
		for(;l<r;)
		{
			int mid=(l+r)/2;
			if(check(mid+1)) l=mid+1; 
			else r=mid;
		}
		printf("%d",l);
		if(i<t) printf("\n");
	}
	return 0;
}