/*input
2 1
3 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>
using namespace __gnu_pbds;
using namespace std;

#define ws(x) cerr << #x << " is " << x << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedTree;

typedef long long ll;
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll N, M;
	cin >> N >> M;

	if(M == 1)
		cout << N - 1;
	else
		cout << N * (M - 1);

	return 0;
}