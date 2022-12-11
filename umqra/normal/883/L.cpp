#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <functional>
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

const int N = 200500;
const ll INF = (ll)2e18;

struct Car
{
	int x;
	ll park;
	int id;
	Car(): x(), park(), id() {}
	Car(int _x, ll _park, int _id): x(_x), park(_park), id(_id) {}
	bool operator<(const Car& o) const
	{
		if (x != o.x)
			return x < o.x;
		if (park != o.park)
			return park < o.park;
		return id < o.id;
	}
};

struct Cmp
{
	bool operator()(const Car& a, const Car& o) const
	{
		if (a.x != o.x)
			return a.x > o.x;
		if (a.park != o.park)
			return a.park < o.park;
		return a.id < o.id;
	}
};

struct Person
{
	ll t;
	int a, b, id;
	Person(): t(), a(), b(), id() {}
	Person(ll _t, int _a, int _b, int _id): t(_t), a(_a), b(_b), id(_id) {}
};

int n, k, m;
int car_pos[N];
ll park_time[N];
set<Car> right_set;
set<Car, Cmp> left_set;
set<pair<ll, int>> events;
queue<Person> delayed;
int ans_num[N];
ll ans_wait[N];

void add_car(int id)
{
	left_set.emplace(car_pos[id], park_time[id], id);
	right_set.emplace(car_pos[id], park_time[id], id);
}

Car pick_best(set<Car, greater<Car>>::iterator lit, set<Car>::iterator rit, const Person& p)
{
	if (lit == left_set.end())
		return *rit;
	if (rit == right_set.end())
		return *lit;
	int d1 = abs(lit->x - p.a);
	int d2 = abs(rit->x - p.a);
	if (d1 != d2)
		return d1 < d2 ? *lit : *rit;
	if (lit->park != rit->park)
		return lit->park < rit->park ? *lit : *rit;
	return lit->id < rit->id ? *lit : *rit;
}

void assign_car(const Person& p)
{
	Car mock(p.a, -INF, -1);
	auto it1 = left_set.lower_bound(mock);
	auto it2 = right_set.lower_bound(mock);
	auto car = pick_best(it1, it2, p);
	left_set.erase(car);
	right_set.erase(car);

	ans_num[p.id] = car.id;
	ans_wait[p.id] = max(0LL, car.park - p.t) + abs(car.x - p.a);
	car_pos[car.id] = p.b;
	park_time[car.id] = max(car.park, p.t) + abs(car.x - p.a) + abs(p.a - p.b);
	events.emplace(park_time[car.id], car.id);
}

void go_to_taxi(ll until)
{
	while (!left_set.empty() && !delayed.empty() && delayed.front().t <= until)
	{
		auto p = delayed.front();
		if (!events.empty() && events.begin()->first <= p.t)
			break;
		delayed.pop();
		assign_car(p);
	}
}

void process_events(ll until)
{
	while (!events.empty() && events.begin()->first <= until)
	{
		ll t = events.begin()->first;
		while (!events.empty() && events.begin()->first == t)
		{
			int id = events.begin()->second;
			add_car(id);
			events.erase(events.begin());
		}
		go_to_taxi(t);
	}
	go_to_taxi(until);
}

void solve()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &car_pos[i]);
		car_pos[i]--;
		add_car(i);
	}

	for (int i = 0; i < m; i++)
	{
		ll t;
		int a, b;
		scanf("%lld%d%d", &t, &a, &b);
		a--, b--;

		delayed.push({ t, a, b, i });
		process_events(t);
	}

	process_events(INF);

	for (int i = 0; i < m; i++)
		printf("%d %lld\n", ans_num[i] + 1, ans_wait[i]);
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