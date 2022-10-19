#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,l,r,a[N];
void sol()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<=n;i++)
		a[i]=0;
	for(int i=1;i<=l;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=r;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]--;
	}
	int s1=0,s2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)
			s1+=a[i];
		else
			s2-=a[i];
	}
	if(s1<s2)
	{
		for(int i=1;i<=n;i++)
			a[i]=-a[i];
		swap(s1,s2);
	}
	int ans=s2,t=0;
	for(int i=1;i<=n;i++)
		if(a[i]>0)
			t+=a[i]/2;
	t=min(t,(s1-s2)/2);
	ans+=t+2*((s1-s2)/2-t);
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}