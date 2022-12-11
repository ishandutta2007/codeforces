#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N],l[N],r[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		memset(l,0,sizeof(l));
		l[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(l[i-1]==1e9) l[i]=1e9;
			else if(a[i]>l[i-1]) l[i]=l[i-1]+1;
			else l[i]=1e9;
		}
		memset(r,0,sizeof(r));
		r[n+1]=-1;
		for(int i=n;i>=1;i--)
		{
			if(r[i+1]==1e9) r[i]=1e9;
			else if(a[i]>r[i+1]) r[i]=r[i+1]+1;
			else r[i]=1e9;
		}
		bool f=false;
		for(int i=1;i<=n;i++)
			if(l[i]!=1e9&&r[i]!=1e9)
			{
				f=true;
				break;
			}
		if(f) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}