#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = (int)1e5 + 10;

ll cnt[N], a[N], b[N];
ll delta[N];
int p[N];
ll S;
int n;

ll get_pizza(ll x)
{
	return (x + S - 1) / S;
}

ll solve(int type, ll cnt1, ll cnt2, ll optimal_count)
{
	ll sum_delta = 0;
	for (int i = 0; i < n; i++)
	{
		int id = p[i];
		int cur_type = (a[id] >= b[id] ? 1 : 2);
		if (cur_type != type) continue;
		ll current_cnt = cnt[id];
		if (type == 1)
		{
			while (current_cnt > 0 && get_pizza(cnt1) + get_pizza(cnt2) > optimal_count)
			{
				current_cnt--;
				cnt1--;
				cnt2++;
				sum_delta += delta[id];
			}
		}
		else
		{
			while (current_cnt > 0 && get_pizza(cnt1) + get_pizza(cnt2) > optimal_count)
			{
				current_cnt--;
				cnt1++;
				cnt2--;
				sum_delta += delta[id];
			}
		}
	}
	return sum_delta;
}

void solve()
{
	scanf("%d%lld", &n, &S);
	ll optimal_count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld%lld", &cnt[i], &a[i], &b[i]);
		optimal_count += cnt[i];
	}
	optimal_count = get_pizza(optimal_count);

	ll cnt1 = 0, cnt2 = 0;
	ll happiness = 0;
	for (int i = 0; i < n; i++)
	{
		happiness += max(a[i], b[i]) * cnt[i];
		if (a[i] >= b[i])
			cnt1 += cnt[i];
		else
			cnt2 += cnt[i];
		delta[i] = max(a[i], b[i]) - min(a[i], b[i]);
		p[i] = i;
	}
	if (get_pizza(cnt1) + get_pizza(cnt2) == optimal_count)
	{
		printf("%lld\n", happiness);
		return;
	}
	sort(p, p + n, [](int x, int y) { return delta[x] < delta[y]; });
	happiness = happiness - min(solve(1, cnt1, cnt2, optimal_count), solve(2, cnt1, cnt2, optimal_count));
	printf("%lld\n", happiness);
}

int main()
{
	solve();
	return 0;
}