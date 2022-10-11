#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstdio>

typedef long long int ll;
typedef std::pair<int, int> ii;

int n;
std::vector<ll> a;
std::vector<ll> p;

bool pass[300300];

std::vector<ll>::iterator up,low;

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		ll temp;std::cin>>temp;
		a.push_back(temp);
	}
	std::sort(a.begin(),a.end());
	p=a;
	ll ans=0;
	for(int i=0;;i++)
	{
		ans=std::max(ans, (ll)p[i]);
		if(i==n-1) break;
		ll cur_p=a[i];
		if(pass[cur_p])
			continue;
		//printf("on %i\n",cur_p);
		for(ll j=cur_p;j<=a[n-1];j+=cur_p)
		{
			pass[j]=true;
 			up= std::upper_bound (a.begin(), a.end(), j+cur_p-1);
 			low= std::lower_bound (a.begin(), a.end(), j);
 			int b_ind=(int)(low - a.begin());
 			if(cur_p==j) b_ind++;
 			int f_ind=(int)(up - a.begin());
 			//printf("found %i times %lli.\n",(f_ind-b_ind),j);
 			p[i]+=(f_ind-b_ind)*j;

		}
		ans=std::max(ans, (ll)p[i]);
	}
	std::cout << ans << std::endl;
}