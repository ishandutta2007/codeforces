#include <cstdio>
#include <algorithm>
//using scanf due to larger input

const int ms=3*int(1e5);

typedef long long int ll;

ll n;//number of pots

int m;//number of reducing
int k;//number of insta

ll x;//normal cost
ll s;//mana

ll a[ms];//first
ll ca[ms];//cost
//ll suma[ms];
//ll sumca[ms];

ll b[ms];
ll cb[ms];
//ll sumb[ms];
//ll sumcb[ms];

int main()
{
	scanf("%lli %i %i",&n,&m,&k);
	scanf("%lli %lli",&x,&s);
	for(int i=1;i<=m;i++)
	{
		scanf("%lli",a+i);
		//suma[i]=suma[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lli",ca+i);
		//sumca[i]=sumca[i-1]+ca[i];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lli",b+i);
		if(b[i]>n)
			b[i]=n;
		//sumb[i]=sumb[i-1]+b[i];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lli",cb+i);
		//sumcb[i]=sumcb[i-1]+cb[i];
	}
	ll total=x*n;
	ll ans=total;
	ca[0]=0;
	a[0]=x;
	for(int i=0;i<=m;i++)
	{
		if(ca[i]>s) continue;
		int left=0;
		int right=k;
		while(left!=right)
		{
			int mid=(left+right+1)/2;
			if(ca[i]+cb[mid]>s)
				right=mid-1;
			else
				left=mid;
		}
		ll cur_ans=a[i]*(n-b[left]);
		ans=std::min(cur_ans,ans);
	}
	printf("%lli\n",ans);
}