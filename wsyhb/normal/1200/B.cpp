#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=100+5;
int a[mx];
int _(int x)
{
	return x>0?x:0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		bool f=true;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		for(int i=1;i<n;i++)
		{
			m+=a[i]-_(a[i+1]-k);
			if(m<0)
			{
				printf("NO\n");
				f=false;
				break;
			}
		}
		if(f) printf("YES\n");
	}
	return 0;
}