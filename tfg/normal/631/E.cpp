#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

typedef long long int ll;

int n;

const ll INF=0x3f3f3f3f3f3f3f3fLL;

ll a[200200];
ll sum[200200];
ll start=0;

ll left_to_right(int l, int r)
{
	if(l>=r)
		return start;
	ll ans=start+(r-l)*a[l]-(sum[r]-sum[l]);
	return ans;
}

ll right_to_left(int l, int r)
{
	if(l>=r)
		return start;
	ll ans=start-(r-l)*a[r]+(sum[r-1]-sum[l-1]);
	return ans;
}

ll solve1(int l, int r, int lll, int lr)
{
	if(l>r) return -INF;
	int mid=(l+r)/2;
	int limit=std::min(mid,lr);
	ll ans=-INF;
	int opt;
	for(int i=lll;i<=limit;i++)
	{
		if(ans<=left_to_right(i,mid))
		{
			ans=left_to_right(i,mid);
			opt=i;
		}
	}
	//std::cout << "on (" << l << ',' << mid << ',' << r << ") ans is " << ans  << " interval is (" << lll << ',' << lr << "), opt is "<< opt << '\n';
	if(l==r)
		return ans;
	ans=std::max(ans,std::max(solve1(l,mid-1,lll,opt),solve1(mid+1,r,opt,lr)));
	return ans;
}

ll solve2(int l, int r, int lll, int lr)
{
	if(l>r) return -INF;
	int mid=(l+r)/2;
	int limit=std::max(mid,lll);
	ll ans=-INF;
	int opt;
	for(int i=lr;i>=limit;i--)
	{
		//std::cout << "trying right(" << mid << ',' << i << "), it is " << right_to_left(mid,i) << '\n';
		if(ans<=right_to_left(mid,i))
		{
			//std::cout << "new ans\n";
			ans=right_to_left(mid,i);
			opt=i;
		}
	}
	//std::cout << "on (" << l << ',' << mid << ',' << r << ") ans is " << ans  << " interval is (" << lll << ',' << lr << "), opt is "<< opt << '\n';
	if(l==r)
		return ans;
	ans=std::max(ans,std::max(solve2(l,mid-1,lll,opt),solve2(mid+1,r,opt,lr)));
	return ans;
}


int main()
{
	scanf("%i",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lli",a+i);
		ans+=a[i]*i;
		sum[i]=sum[i-1]+a[i];
	}
	//std::cout << "start is " << ans << '\n';
	start=ans;
	ans=std::max(ans,solve1(1,n,1,n));
	//std::cout << '\n';
	ans=std::max(ans,solve2(1,n,1,n));
	
	printf("%lli\n",ans);


}