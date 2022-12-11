#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[35];
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i)
	{
		printf("%d\n",i+1);
		fflush(stdout);
		int opt;
		scanf("%d",&opt);
		if(opt==0)
		{
			return 0;
		}
		if(opt==1)a[i]=1;
		if(opt==-1)a[i]=-1;
	}
	int l=1,r=m;
	for(int T=0;T<30;++T)
	{
		int x=T%n;
		int mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		int opt;
		scanf("%d",&opt);
		if(opt==0)
		{
			return 0;
		}
		opt*=a[x];
		if(opt==-1)r=mid-1;
		if(opt==1)l=mid+1;
	}
	return 0;
}