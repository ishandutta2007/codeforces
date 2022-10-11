#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

const int ms = 100100;

typedef long long ll;
typedef std::pair<ll, ll> ii;

using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
std::less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
	ll n, t;
	std::cin >> n >> t;
	ordered_set lis;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll cur;
		std::cin >> cur;
		cur = std::max(cur, (ll)i);
		cur -= i;
		lis.insert(ii(cur, i));
		ans = std::max(ans, (int)lis.order_of_key(ii(t - i, -1)));
	}
	std::cout << ans << '\n';
}