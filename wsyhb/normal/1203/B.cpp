#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=400+5,mx1=200+5;
int a[mx],s[mx1];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=4*n;i++) scanf("%d",a+i);
		sort(a+1,a+4*n+1);
		bool f=false;
		for(int i=1;i<=4*n;i+=2)
			if(a[i]!=a[i+1])
			{
				f=true;
				break;
			}
		if(f)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=4*n;i+=2) s[(i+1)/2]=a[i];
		int q=0;
		for(int i=1;i<=n;i++)
		{
			if(!q) q=s[i]*s[2*n-i+1];
			else if(s[i]*s[2*n-i+1]!=q)
			{
				f=true;
				break;
			}
		}
		if(f) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}