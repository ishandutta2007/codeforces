#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long int ll;
typedef std::pair<ll, ll> ii;

std::priority_queue<ll,std::vector<ll>, std::greater<ll> > higher;
std::priority_queue<ii> lower;

int main()
{
	int n;
	ll b, w;
	scanf("%i %lli %lli",&n,&b,&w);
	ll myb=b;
	ll myw=w;
	for(int i=1;i<n;i++)
	{
		scanf("%lli %lli",&b,&w);
		if(b<=myb)
			lower.push(ii(b,w));
		else
			higher.push(w-b+1);
	}

	int min_pos=(int)higher.size()+1;
	while(!higher.empty())
	{
		ll cost=higher.top();
		higher.pop();
		//std::cout << "trying to persuade with " << cost << " ballons\n";
		if(cost>myb) break;
		myb-=cost;
		//std::cout << "gave away " << cost << " ballons\n";
		while(!lower.empty() && lower.top().first>myb)
		{
			higher.push(lower.top().second-lower.top().first+1);
			lower.pop();
		}
		min_pos=std::min(min_pos, (int)higher.size()+1);

	}
	printf("%i\n",min_pos);

}