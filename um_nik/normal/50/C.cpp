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

const int C = (int)1e7;
const int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int DY[] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[8][2];



int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 8; i++) {
		a[i][0] = C;
		a[i][1] = -C;
	}

	int n;
	scanf("%d", &n);
	while(n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 0; i < 8; i += 2) {
			int xx = x + DX[i], yy = y + DY[i];
			for (int j = 0; j < 8; j++) {
				int z = xx * DX[j] + yy * DY[j];
				a[j][0] = min(a[j][0], z);
				a[j][1] = max(a[j][1], z);
			}
		}
	}
	int minX = a[0][0], maxX = a[0][1];
	int minY = a[2][0], maxY = a[2][1];
	eprintf("%d %d %d %d\n", minX, maxX, minY, maxY);
	int ans = 2 * (maxX - minX + maxY - minY);
	for (int i = 1; i < 8; i += 2) {
		int z = a[i][1];
		if (DX[i] == 1) {
			z -= maxX;
		} else {
			z += minX;
		}
		if (DY[i] == 1) {
			z -= maxY;
		} else {
			z += minY;
		}
		ans -= abs(z);
	}
	printf("%d\n", ans);

	return 0;
}