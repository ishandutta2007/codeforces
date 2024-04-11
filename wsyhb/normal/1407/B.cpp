#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
int a[max_n];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		int d=0,id;
		for(int i=1;i<=n;++i)
			if(a[i]>d) d=a[i],id=i;
		printf("%d%c",d,n>1?' ':'\n');
		a[id]=0;
		for(int i=1;i<n;++i)
		{
			int max_d=0,id;
			for(int j=1;j<=n;++j)
				if(a[j]) 
				{
					int v=gcd(a[j],d);
					if(v>max_d) max_d=v,id=j;
				}
			printf("%d%c",a[id],i<n-1?' ':'\n');
			a[id]=0;
			d=max_d;
		}
	}
	return 0;
}