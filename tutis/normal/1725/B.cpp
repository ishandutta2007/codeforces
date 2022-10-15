/*input
6 180
90 80 70 60 50 100
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>
using namespace __gnu_pbds;
using namespace std;

#define ws(x) cerr << #x << " is " << x << endl

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> orderedTree;

#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll N, D;
	cin >> N >> D;
	vector<ll> P(N);
	for(ll i = 0; i < N; i++)
		cin >> P[i];
	sort(P.begin(), P.end(), greater<>());

	ll ans = 0;
	for(ll i = 0; i < P.size(); i++)
	{
		ll needed = D / P[i];
		while(needed * P[i] <= D)
			needed++;
		if(i + needed > P.size())
			break;
		ans++;
		while(needed > 1)
		{
			needed--;
			P.pop_back();
		}
	}

	cout << ans;

	return 0;
}