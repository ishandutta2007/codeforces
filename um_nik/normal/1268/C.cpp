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
int fenv[N];
int n;
int a[N];
set<int> lft, rgt;
ll sumLeft, sumRight;
ll sumInv;

void addFenv(int p, int x) {
	for(; p < N; p |= p + 1)
		fenv[p] += x;
}
int getFenv(int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}

void normalize() {
	while((int)lft.size() > (int)rgt.size()) {
		int x = *lft.rbegin();
		sumLeft -= x;
		sumRight += x;
		lft.erase(x);
		rgt.insert(x);
	}
	while((int)rgt.size() - 1 >= (int)lft.size() + 1) {
		int x = *rgt.begin();
		sumLeft += x;
		sumRight -= x;
		lft.insert(x);
		rgt.erase(x);
	}
}
void myIns(int x) {
	sumInv += getFenv(n) - getFenv(x);
	addFenv(x, 1);
	if (rgt.empty() || x < *rgt.begin()) {
		lft.insert(x);
		sumLeft += x;
	} else {
		rgt.insert(x);
		sumRight += x;
	}
	normalize();
}

void printAns() {
	ll mid = *rgt.begin();
	ll ans = sumInv;
	ll L = (ll)lft.size(), R = (ll)rgt.size();
	ans += (mid - L + mid - 1) * L / 2 - sumLeft;
	ans += sumRight - (mid + mid + R - 1) * R / 2;
	printf("%lld ", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		a[x] = i;
	}
	for (int i = 0; i < n; i++) {
		myIns(a[i]);
		printAns();
	}
	printf("\n");

	return 0;
}