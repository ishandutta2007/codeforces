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
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

struct Problem
{
	ll cost, time, min_time, max_time;
	Problem() : cost(), time() {}
	Problem(ll cost, ll time) : cost(cost), time(time) {}
	bool operator< (const Problem& p) const
	{
		return cost * p.time > time * p.cost;
	}
	bool operator!= (const Problem& p) const
	{
		return cost * p.time != p.cost * time;
	}
};

const int N = 2e5;
int n;
ll sum_t;
Problem problems[N];
vector< vector<Problem> > blocks;
vector< ll > block_times;

bool good(double c)
{
	double max_cost = -LINF;
	for (auto& problem : blocks[0])
		max_cost = max(max_cost, problem.cost * (1 - c * problem.min_time / sum_t));
	for (int b = 1; b < blocks.size(); ++b)
	{
		for (auto& problem : blocks[b])
			if (problem.cost * (1 - c * problem.max_time / sum_t) < max_cost)
				return false;
		for (auto& problem : blocks[b])
			max_cost = max(max_cost, problem.cost * (1 - c * problem.min_time / sum_t));
	}
	return true;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> problems[i].cost;
	for (int i = 0; i < n; ++i)
	{
		cin >> problems[i].time;
		sum_t += problems[i].time;
	}
	sort(problems, problems + n);
	blocks.emplace_back();
	blocks.back().push_back(problems[0]);
	block_times.push_back(problems[0].time);
	for (int i = 1; i < n; ++i)
	{
		if (problems[i] != problems[i - 1])
		{
			blocks.emplace_back();
			block_times.push_back(0);
		}
		blocks.back().push_back(problems[i]);
		block_times.back() += problems[i].time;
	}
	ll now = 0;
	for (int b = 0, p = 0; b < blocks.size(); ++b)
	{
		for (auto& problem : blocks[b])
		{
			problem.min_time = now + problem.time;
			problem.max_time = now + block_times[b];
			problems[p++] = problem;
		}
		now += block_times[b];
	}
	sort(problems, problems + n, [] (const Problem& f, const Problem& s) { return f.cost < s.cost; });
	blocks.clear();
	blocks.emplace_back();
	blocks[0].push_back(problems[0]);
	for (int i = 1; i < n; ++i)
	{
		if (problems[i].cost != problems[i - 1].cost)
			blocks.emplace_back();
		blocks.back().push_back(problems[i]);
	}
	double l = 0, r = 1;
	for (int it = 0; it < 40; ++it)
	{
		double m = (l + r) / 2;
		if (good(m))
			l = m;
		else
			r = m;
	}
	cout << setprecision(9) << fixed << l;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}