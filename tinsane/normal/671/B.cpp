#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
//const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

struct Trip
{
	int less, more;
	int val;
	void read()
	{
		scanf("%d", &val);
		less = 1;
		more = 0;
	}
	bool operator< (const Trip& t) const
	{
		return val < t.val;
	}
};

const int N = 5e5 + 10;
int n, k;
deque<Trip> now;

void solve()
{
	scanf("%d%d", &n, &k);
	now.resize(n);
	for (int i = 0; i < n; ++i)
		now[i].read();
	sort(now.begin(), now.end());
	while (now.size() > 1 && k > 0)
	{
		while (true)
		{
			if (now[0].less == 0)
			{
				++now[0].val;
				now[0].less = now[0].more;
				now[0].more = 0;
			}
			int si = now.size();
			if (si == 1)
				break;
			for (; now.size() > 1 && now[0].val == now[1].val; now[1].less += now[0].less, now[1].more += now[0].more, now.pop_front()) {}
			if (si == now.size())
			{
				if (now[1].val == now[0].val + 1)
				{
					now[1].less += now[0].more;
					now[0].more = 0;
				}
				break;
			}
		}
		while (true)
		{
			if (now[now.size() - 1].less == 0)
			{
				++now[now.size() - 1].val;
				now[now.size() - 1].less = now[now.size() - 1].more;
				now[now.size() - 1].more = 0;
			}
			int si = now.size();
			if (si == 1)
				break;
			for (; now.size() > 1 && now[now.size() - 1].val == now[now.size() - 2].val;
			now[now.size() - 2].less += now[now.size() - 1].less, now[now.size() - 2].more += now[now.size() - 1].more, now.pop_back()) {}
			if (si == now.size())
			{
				if (now.back().more == 0 && now.back().val == now[now.size() - 2].val + 1)
				{
					now[now.size() - 2].more += now.back().less;
					now.pop_back();
					continue;
				}
				break;
			}
		}
		if (now.size() == 1)
			break;
		int add = now[1].val - now[0].val;
		ll sum_add = (ll) add * now[0].less + (ll) (add - 1) * now[0].more;
		int sub = now.back().val - now[now.size() - 2].val;
		ll sum_sub = (ll) sub * now.back().less + (ll) (sub + 1) * now.back().more;
		int delta = min(min(sum_add, sum_sub), (ll)k);
		if (now.size() == 2)
		{
			ll s = 0;
			for (int i = 0; i < now.size(); ++i)
				s += (ll) (now[i].less + now[i].more) * now[i].val + now[i].more;
			int mid = s / n;
			add = mid - now[0].val;
			sum_add = (ll) (now[0].less + now[0].more) * add - now[0].more;
			if (sum_add <= k)
			{
				printf("%d", s % n != 0);
				return;
			}
			if (now[0].less > delta)
			{
				now[0].more += delta;
				now[0].less -= delta;
			}
			else
			{
				int loc_delta = delta - now[0].less;
				now[0].less += now[0].more;
				++now[0].val;
				int add = loc_delta / now[0].less;
				int more = loc_delta % now[0].less;
				now[0].val += add;
				now[0].more = more;
				now[0].less -= more;
			}
			if (now.back().more > delta)
			{
				now.back().less += delta;
				now.back().more -= delta;
			}
			else
			{
				int loc_delta = delta - now.back().more;
				now.back().less += now.back().more;
				int sub = loc_delta / now.back().less + 1;
				int more = now.back().less - loc_delta % now.back().less;
				now.back().val -= sub;
				now.back().less -= more;
				now.back().more = more;
			}

			break;
		}
		if (now[0].less > delta)
		{
			now[0].more += delta;
			now[0].less -= delta;
		}
		else
		{
			int loc_delta = delta - now[0].less;
			now[0].less += now[0].more;
			++now[0].val;
			int add = loc_delta / now[0].less;
			int more = loc_delta % now[0].less;
			now[0].val += add;
			now[0].more = more;
			now[0].less -= more;
		}
		if (now.back().more > delta)
		{
			now.back().less += delta;
			now.back().more -= delta;
		}
		else
		{
			int loc_delta = delta - now.back().more;
			now.back().less += now.back().more;
			int sub = loc_delta / now.back().less + 1;
			int more = now.back().less - loc_delta % now.back().less;
			now.back().val -= sub;
			now.back().less -= more;
			now.back().more = more;
		}
		k -= delta;
	}
	int ma = now.back().more ? now.back().val + 1 : now.back().val;
	int mi = now.front().less == 0 ? now.front().val + 1 : now.front().val;
	printf("%d\n", ma - mi);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}