/*input
3
1 5
10 11
8 8
2
12
5
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

const int maxN = 1e5 + 5;

int N;
int L[maxN + 1], R[maxN + 1];

map<int, int> precomputedAnswer;

int computeAnswer(int k)
{
	int entireInterval = 0;
	int mod = 1<<k;

	// cout << "mod = " << mod << endl;

	vector<pair<int, int> > pts;
	for(int i = 0; i < N; i++)
	{
		if(R[i] - L[i] + 1 >= mod)
			entireInterval++;
		else
		{
			int rem1 = L[i] % mod, rem2 = R[i] % mod;
			if(rem1 <= rem2)
			{
				pts.push_back(mp(rem1, 1));
				pts.push_back(mp(rem2 + 1, - 1));
			}
			else
			{
				pts.push_back(mp(0, 1));
				pts.push_back(mp(rem2 + 1, -1));

				pts.push_back(mp(rem1, 1));
				pts.push_back(mp(mod, -1));
			}
		}
	}

	int midInterval = 0, cum = 0;
	sort(pts.begin(), pts.end());
	for(auto p : pts)
	{
		cum += p.second;
		midInterval = max(cum, midInterval);
	}

	return entireInterval + midInterval;
}

int answer(int k)
{
	if(precomputedAnswer.find(k) != precomputedAnswer.end())
		return precomputedAnswer[k];
	return precomputedAnswer[k] = computeAnswer(k);
}

int findK(int W)
{
	int k = __builtin_ctz(W); 
	// cout << "W = " << W << endl;
	// cout << "k = " << k << endl;
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> L[i] >> R[i];

	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		int W;
		cin >> W;
		cout << answer(findK(W)) << "\n";
	}

	return 0;
}