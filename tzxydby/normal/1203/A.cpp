#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N];
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,p,flag,i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1) p=i;
		}
		flag=1; 
		i=p,j=1;
		while(j!=n)
		{
			if(a[i]!=j) flag=0;
			i=(i+1)%n;
			j++;
		}
		if(flag)
		{
			puts("YES");
			continue;
		}
		flag=1;
		i=p,j=1;
		while(j!=n)
		{
			if(a[i]!=j) flag=0;
			i=i-1;
			if(i<0) i=n-1;
			j++;
		}
		if(flag)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}