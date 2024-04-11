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
int n,m;
int a[100];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(m==0)
				goto end;
			m--;
			printf("%d ",i+1);
			for(int k=0;k<i;k++)
				printf("%d ",a[k]);
			printf("%d\n",a[j]);
		}
	}
	end:;
}