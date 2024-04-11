using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 3000001
#define ll long long
int L,R;
int cur[N*2];
int n,m;
int a[N*2];
ll ans=0;
ll res=0;
int it=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<i)R++;else L++;
		if(a[i]>=i) cur[a[i]-i]++;
		ans+=abs(a[i]-i);
	}
	res=ans;
	for(int i=0;i<=n-2;i++)//edge
	{
		L-=cur[i];
		R+=cur[i];
		res=res-L+R-abs(a[n-i]-n)-1+a[n-i]-1;
		cur[a[n-i]+i]++;
		L++;R--;
		if(res<ans)
		{
			ans=res;
			it=i+1;
		}
	}
	printf("%lld %d\n",ans,it);
}