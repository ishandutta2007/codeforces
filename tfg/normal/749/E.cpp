#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <cstdio>

const int ms=100100;
//const int ms=100;

typedef std::pair<int, int> ii;
typedef long double ld;
typedef long long int ll;



class BIT
{
public:
	BIT()
	{
		init();
	}

	void init()
	{
		for(int i=0;i<ms;i++)
			bit[i]=0;
	}

	void upd(int on, ll val)
	{
		//on=std::max(on, 0);
		//on=std::min(on, ms);
		if(!on)
			return;
		for(;on<ms;on+=on&-on)
		{
			bit[on]+=val;
			//std::cout << "on " << on << " has " << bit[on] << '\n';
		}
	}

	ll qry(int on)
	{
		ll ans=0;
		//int wut=on;
		on=std::max(on, 0);
		on=std::min(on, ms-1);
		for(;on>0;on-=on&-on)
			ans+=bit[on];
		//std::cout << "on qry " << wut << " returning " << ans << '\n';
		return ans;
	}

	ll qry(int l, int r)
	{
		return qry(r)-qry(l-1);
	}

	ll bit[ms];
};

ii a[ms];
int b[ms];

int main()
{
	int n;
	std::cin >> n;
	for(int i=1;i<=n;i++)
	{
		std::cin >> a[i].first;
		a[i].second=i;
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[a[i].second]=i;

	ll total_inv=0;
	BIT fw;
	for(int i=1;i<=n;i++)
	{
		total_inv+=fw.qry(b[i],n);
		fw.upd(b[i],1);
	}
	//std::cout << "has " << total_inv << " total inversions\n";
	fw.init();

	ll inside=0;
	for(int i=n;i>0;i--)
	{
		inside+=(ld)fw.qry(1,b[i])*(ld)i;
		fw.upd(b[i],n-i+1);
	}
	//std::cout << "inside is " << (double)inside << '\n';

	ld avg=0.0;
	for(int i=1;i<=n;i++)
	{
		ld len=i;
		ld cur_avg=(len-1)*(len)/4.0;
		//std::cout << "avg of " << i << " is " << cur_avg << '\n';
		cur_avg*=(n-i+1);
		avg+=cur_avg;
	}

	//std::cout << "avg is " << (double)avg << '\n';

	ll combs=((ll)n*(ll)(n+1))/2.0;
	ld total_ans=total_inv+(ld)((ld)avg/(ld)1.0-inside)/(ld)combs;
	printf("%.20lf\n",(double)total_ans);
	//std::cout << std::fixed << std::setprecision(20) << (double)total_ans << '\n';
}