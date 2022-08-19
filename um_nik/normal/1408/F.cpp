#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

struct Ans {
	vector<int> a, b;
	vector<pii> mv;

	Ans() : a(), b(), mv() {}

	void print() {
		printf("%d\n", (int)mv.size());
		for (pii z : mv)
			printf("%d %d\n", z.first, z.second);
	}
};

Ans solve(int n) {
	if (n == 1) {
		Ans ans = Ans();
		ans.a.push_back(1);
		return ans;
	}
	if (n % 2 == 0) {
		n /= 2;
		Ans cur = solve(n);
		Ans ans = Ans();
		for (pii t : cur.mv) {
			ans.mv.push_back(t);
			ans.mv.push_back(mp(t.first + n, t.second + n));
		}
		for (int x : cur.a) {
			ans.a.push_back(x);
			ans.a.push_back(x + n);
			ans.mv.push_back(mp(x, x + n));
		}
		for (int x : cur.b) {
			ans.b.push_back(x);
			ans.b.push_back(x + n);
			ans.mv.push_back(mp(x, x + n));
		}
		return ans;
	} else {
		Ans cur = solve(n - 1);
		vector<int> a = cur.a, b = cur.b, c = {n};
		if ((int)a.size() < (int)b.size()) swap(a, b);
		while(!b.empty()) {
			int z = (int)c.size();
			if ((int)b.size() & z) {
				vector<int> nc;
				for (int x : c) {
					int y = b.back();
					b.pop_back();
					cur.mv.push_back(mp(x, y));
					nc.push_back(x);
					nc.push_back(y);
				}
				c = nc;
			} else {
				vector<int> nc;
				for (int x : c) {
					assert(!a.empty());
					int y = a.back();
					a.pop_back();
					cur.mv.push_back(mp(x, y));
					nc.push_back(x);
					nc.push_back(y);
				}
				c = nc;
			}
		}
		cur.a = a;
		cur.b = c;
		return cur;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	auto ans = solve(n);
	ans.print();

	return 0;
}