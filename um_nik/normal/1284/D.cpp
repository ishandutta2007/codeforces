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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int a[N][4];
int n;

struct Event {
	int x;
	int t;
	int id;

	Event() : x(), t(), id() {}
	Event(int _x, int _t, int _id) : x(_x), t(_t), id(_id) {}

	bool operator < (const Event &e) const {
		if (x != e.x) return x < e.x;
		return t < e.t;
	}
};
Event ev[N];
multiset<int> L, R;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a[i][j]);
		}

	for (int it = 0; it < 2; it++) {

		for (int i = 0; i < n; i++) {
			ev[2 * i] = Event(a[i][0], 0, i);
			ev[2 * i + 1] = Event(a[i][1], 1, i);
		}
		sort(ev, ev + 2 * n);
		L.clear();
		R.clear();

		for (int i = 0; i < 2 * n; i++) {
			Event e = ev[i];
			int p = e.id;
			if (e.t == 0) {
				L.insert(-a[p][2]);
				R.insert(a[p][3]);
			} else {
				L.erase(L.find(-a[p][2]));
				R.erase(R.find(a[p][3]));
				if (!L.empty() && -(*L.begin()) > a[p][3]) {
					printf("NO\n");
					return 0;
				}
				if (!R.empty() && *R.begin() < a[p][2]) {
					printf("NO\n");
					return 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++)
				swap(a[i][j], a[i][j + 2]);
		}
	}
	printf("YES\n");

	return 0;
}