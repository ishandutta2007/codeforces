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
char s[N], p[N];
vector<int> AB, BA;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", p);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a' && p[i] == 'b')
			AB.push_back(i + 1);
		else if (s[i] == 'b' && p[i] == 'a')
			BA.push_back(i + 1);
	}
	int sum = (int)AB.size() + (int)BA.size();
	if (sum & 1) {
		printf("-1\n");
		return 0;
	}
	if ((int)AB.size() & 1) {
		printf("%d\n", sum / 2 + 1);
		int x = AB.back();
		printf("%d %d\n", x, x);
		BA.push_back(x);
		AB.pop_back();
	} else {
		printf("%d\n", sum / 2);
	}
	while(!AB.empty()) {
		int x = AB.back();
		AB.pop_back();
		int y = AB.back();
		AB.pop_back();
		printf("%d %d\n", x, y);
	}
	while(!BA.empty()) {
		int x = BA.back();
		BA.pop_back();
		int y = BA.back();
		BA.pop_back();
		printf("%d %d\n", x, y);
	}

	return 0;
}