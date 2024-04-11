#include<bits/stdc++.h>
using namespace std;
int n,p;
int a[210000];
struct pp
{
	int i;
	int aa;
}tt[210000];
bool cmp(pp aaa,pp bbb)
{
	return aaa.aa<bbb.aa;
}
int b[210000];
int c[210000];
bool is[210000];
bool ll[210000];
int main()
{
	int t;
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			tt[i].i=i;
			tt[i].aa=a[i];
		}
		sort(tt+1,tt+n+1,cmp);
		for(int i=1;i<=n;i++) b[i]=tt[i].i;
		for(int i=1;i<=n;i++) c[b[i]]=i;
		for(int i=1;i<n;i++) is[i]=false;
		for(int i=1;i<=n;i++) ll[i]=false;
		for(int i=1;i<=n;i++)
		{
			if(a[b[i]]>=p) break;
			if(ll[b[i]]) continue;
			ll[b[i]]=true;
			for(int j=b[i]+1;j<=n;j++)
			{
				if(a[j]%a[b[i]]!=0) break;
				is[j-1]=true;
				ans+=a[b[i]];
				if(ll[j]) break;
				ll[j]=true;
			}
			for(int j=b[i]-1;j>=1;j--)
			{
				if(a[j]%a[b[i]]!=0) break;
				is[j]=true;
				ans+=a[b[i]];
				if(ll[j]) break;
				ll[j]=true;
			}
		}
		for(int i=1;i<n;i++) 
		 if(!is[i]) ans+=p;
		printf("%lld",ans);
		if(o<t) printf("\n");
	}
	return 0;
}