#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = (int)1e6 + 10;
int n;
char str[N];
vector <int> stars;
vector <int> ps;
bool has_stars[N];

void solve_one()
{
	int cnt_left = 0, cnt_right = 0;
	int pos_left = ps[0], pos_right = ps[0];
	for (int x : stars)
	{
		if (x < ps[0])
		{
			cnt_left++;
			pos_left = min(pos_left, x);
		}
		else
		{
			cnt_right++;
			pos_right = max(pos_right, x);
		}
	}
	auto v1 = make_pair(cnt_left, -(ps[0] - pos_left));
	auto v2 = make_pair(cnt_right, -(pos_right - ps[0]));
	auto result = max(v1, v2);
	printf("%d %d\n", result.first, -result.second);
}

/*
void adjust_ps(int len, int &it, int &r)
{
	while (it < (int)ps.size() && ps[it] <= r)
	{
		r = max(r, ps[it] + len);
		it++;
	}
}
void adjust_stars(int len, int &it, int &r)
{
	while (it < (int)stars.size() && stars[it] <= r)
	{
		it++;
	}
}

bool check(int len)
{
	int right_border = -1;
	int p_it = 0, s_it = 0;
	while (s_it < (int)stars.size())
	{
		adjust_ps(len, p_it, right_border);
		adjust_stars(len, s_it, right_border);
		if (s_it == (int)stars.size())
			break;
		if (p_it < (int)ps.size() && ps[p_it] < stars[s_it])
		{
			right_border = ps[p_it];
			continue;
		}

		if (p_it == (int)ps.size())
			return false;
		int p1 = ps[p_it];
		if (p1 > stars[s_it] + len)
			return false;

		if (p_it == (int)ps.size() - 1)
			right_border = ps[p_it++];
		else
		{
			int p2 = ps[p_it + 1];
			if (p2 > stars[s_it] + len)
				right_border = ps[p_it++];
			else
			{
				if (has_stars[p_it])
					right_border = p1 + len;
				else
					right_border = p2 + len; 
				p_it += 2;
			}
		}
		s_it++;
	}
	return true;
}*/

int near_star[N];
int dp[N];

bool check(int len)
{
	fill(dp, dp + n + 1, -1);
	for (int i = 0; i < (int)ps.size(); i++)
	{
		dp[i] = min(dp[i], n);

		int star = (dp[i] == -1 ? stars[0] : near_star[dp[i]]);
		if (star > ps[i])
			dp[i + 1] = max(dp[i + 1], ps[i] + len);
		else
		{
			if (ps[i] - star > len)
				continue;
			dp[i + 1] = max(dp[i + 1], ps[i]);
			if (i < (int)ps.size() - 1 && ps[i + 1] - star <= len)
				dp[i + 2] = max(dp[i + 2], ps[i] + len);
		}
	}
	if (dp[(int)ps.size()] >= n || near_star[dp[(int)ps.size()]] == n)
		return true;
	return false;
}

void solve_many()
{
	int l = 0, r = n;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%d %d\n", (int)stars.size(), r);
}

void solve()
{
	scanf("%d", &n);
	scanf(" %s", str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'P')
			ps.push_back(i);
		else if (str[i] == '*')
			stars.push_back(i);
	}

	int last_star = n;
	near_star[n] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		near_star[i] = last_star;
		if (str[i] == '*')
			last_star = i;
	}

	for (int i = 0; i < (int)ps.size() - 1; i++)
	{
		auto it = lower_bound(stars.begin(), stars.end(), ps[i]);
		if (it != stars.end() && *it < ps[i + 1])
			has_stars[i] = true;
	}
	if (ps.size() == 1)
		solve_one();
	else
		solve_many();
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}