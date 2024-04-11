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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = (int)1e6 + 7;
vector<string> s;
int n, m, q;
int a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m - 1; j++)
			if (s[i][j] == 'X' && s[i - 1][j + 1] == 'X')
				a[j + 1] = 1;
	for (int i = 1; i < m; i++)
		a[i] += a[i - 1];
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;r--;
		if (a[l] == a[r])
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}