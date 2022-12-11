#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=15e4+5;
int a[mx];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		int Min=1e6+1,ans=0;
		for(int i=n;i>=1;i--)
		{
			if(Min<a[i]) ans++;
			Min=min(Min,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}