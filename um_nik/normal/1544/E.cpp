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

const int A = 26;
const int N = 100100;
int n;
char s[N];
int c[A];

void solve() {
	int p = 0;
	for (int i = 0; i < A; i++)
		c[i] = 0;
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		c[(int)(s[i] - 'a')]++;
	for (int i = 0; i < A; i++) {
		if (c[i] == n) {
			printf("%s\n", s);
			return;
		}
	}
	int x = 0;
	while(x < A && c[x] != 1) x++;
	if (x < A) {
		s[p++] = 'a' + x;
		c[x]--;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < c[i]; j++)
				s[p++] = 'a' + i;
		printf("%s\n", s);
		return;
	}
	x = 0;
	while(x < A && c[x] == 0) x++;
	assert(x < A);
	if (2 * c[x] <= n + 2) {
		s[p++] = 'a' + x;
		s[p++] = 'a' + x;
		c[x] -= 2;
		int y = x + 1;
		while(c[x] > 0) {
			while(y < A && c[y] == 0) y++;
			assert(y < A);
			s[p++] = 'a' + y;
			c[y]--;
			s[p++] = 'a' + x;
			c[x]--;
		}
		for (int i = 0; i < A; i++)
			for (int j = 0; j < c[i]; j++)
				s[p++] = 'a' + i;
		printf("%s\n", s);
		return;
	}
	int y = x + 1;
	while(y < A && c[y] == 0) y++;
	assert(y < A);
	if (c[x] + c[y] == n) {
		s[p++] = 'a' + x;
		for (int i = 0; i < c[y]; i++)
			s[p++] = 'a' + y;
		for (int i = 1; i < c[x]; i++)
			s[p++] = 'a' + x;
		printf("%s\n", s);
		return;
	}
	s[p++] = 'a' + x;
	c[x]--;
	s[p++] = 'a' + y;
	c[y]--;
	for (int i = 0; i < c[x]; i++)
		s[p++] = 'a' + x;
	c[x] = 0;
	x = y + 1;
	while(x < A && c[x] == 0) x++;
	assert(x < A);
	s[p++] = 'a' + x;
	c[x]--;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < c[i]; j++)
			s[p++] = 'a' + i;
	printf("%s\n", s);
	return;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}