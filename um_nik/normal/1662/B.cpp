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

const int A = 26;
const int N = 3030;
char s[N];
int a[3][A];
string ans[N];
vector<int> b[3];
vector<char> c[3];
pii d[3];
int n;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int M = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%s", s);
		int L = strlen(s);
		for (int j = 0; j < L; j++)
			a[i][(int)(s[j] - 'A')]++;
		M = max(M, L);
	}
	for (int x = 0; x < A; x++) {
		while(n < M) {
			for (int i = 0; i < 3; i++)
				d[i] = mp(a[i][x], i);
			sort(d, d + 3);
			if (d[1].first == 0) break;
			ans[n].push_back('A' + x);
			a[d[1].second][x]--;
			a[d[2].second][x]--;
			b[d[0].second].push_back(n);
			n++;
		}
	}
	for (int i = 0; i < 3; i++)
		for (int x = 0; x < A; x++)
			while(a[i][x]--) {
				c[i].push_back('A' + x);
			}
	for (int i = 0; i < 3; i++) {
		while(!b[i].empty() && !c[i].empty()) {
			ans[b[i].back()].push_back(c[i].back());
			b[i].pop_back();
			c[i].pop_back();
		}
	}
	while(true) {
		for (int i = 0; i < 3; i++)
			d[i] = mp((int)c[i].size(), i);
		sort(d, d + 3);
		if (d[2].first == 0) break;
		for (int i = 2; i > 0; i--) {
			if (d[i].first == 0) break;
			ans[n].push_back(c[d[i].second].back());
			c[d[i].second].pop_back();
		}
		n++;
	}
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		while((int)ans[i].size() < 2) ans[i].push_back('A');
		cout << ans[i] << endl;
	}

	return 0;
}