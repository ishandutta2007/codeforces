#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cnt[N],tot[N],a[N],Log[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
		while(x)
		{
			cnt[x]++;
			x/=2;
		}
	}
	int ans;
	for(int i=1e5;i>=1;i--)
		if(cnt[i]==n)
		{
			ans=i;
			break;
		}
	Log[0]=-1;
	for(int i=1;i<=1e5;i++) Log[i]=Log[i/2]+1;
	int Ans=1e9;
	while(ans<=1e5)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			while(ans%x)
			{
				sum++;
				x/=2;
			}
			sum+=Log[ans/x];
		}
		Ans=min(Ans,sum);
		ans*=2;
	}
	printf("%d",Ans);
	return 0;
}