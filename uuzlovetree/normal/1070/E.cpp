#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
int T,n,m;
ll t,a[maxn],b[maxn];
int cnt;
int calc(int d)
{
	ll cnt=0,tim=0,res=0,sum=t;
	for(int i=1;i<=n;++i)if(a[i]<=d)
	{
		if(a[i]>sum)break;
		res++;cnt++;
		tim+=a[i];sum-=a[i];
		if(cnt==m)
		{
			cnt=0;
			sum-=tim;
			tim=0;
		}
	}
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		scanf("%d%d%I64d",&n,&m,&t);
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i]),b[++cnt]=a[i];
		sort(b+1,b+cnt+1);
		cnt=unique(b+1,b+cnt+1)-b-1;
		int l=1,r=cnt;
		while(l<r)
		{
			int dl=(2*l+r)/3,dr=(2*r+l+2)/3;
			if(calc(b[dl])<calc(b[dr]))l=dl+1;
			else r=dr-1;
		}
		if(b[l]>t)
		{
			printf("0 1\n");
			continue;
		}
		int id=l,ans=calc(b[l]);
		//for(int i=l+1;i<=max(cnt,l+5);++i)if(ans<calc(b[i]))id=i,ans=calc(b[i]);
		//for(int i=l-1;i>=min(cnt,l-5);--i)if(ans<calc(b[i]))id=i,ans=calc(b[i]);
		printf("%d %d\n",ans,b[id]);
	}
	return 0;
}