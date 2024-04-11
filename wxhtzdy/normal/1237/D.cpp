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

const int N = 200333;
const int LOG = 19;
int n;
int a[N];
int mn[N][LOG];
int mx[N][LOG];
int logs[N];
int nxtL[N];
int nxtR[N];
int ans[N];

int getMax(int l, int r) {
	int k = logs[r - l + 1];
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int getMin(int l, int r) {
	int k = logs[r - l + 1];
	return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

bool vis[N];
void dfs(int i) {
	if(vis[i])
		return;
	vis[i] = true;
	if(nxtL[i] < nxtR[i])
		ans[i] = nxtL[i] - i;
	else
		dfs(nxtR[i] % n), ans[i] = ans[nxtR[i] % n] + nxtR[i] - i;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = n; i < 2 * n; i++)
		a[i] = a[i - n];
	for(int i = 2; i <= 2 * n; i++)
		logs[i] = logs[i >> 1] + 1;
	for(int i = 0; i < 2 * n; i++)
		mn[i][0] = a[i], mx[i][0] = a[i];
	for(int j = 1; j < LOG; j++)
		for(int i = 0; i + (1 << j) <= 2 * n; i++) {
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	if(getMin(0, n - 1) * 2 >= getMax(0, n - 1)) {
		for(int i = 0; i < n; i++)
			printf("-1 ");
		return 0;
	}
	for(int i = 0; i < n; i++) {
		{
			int l = i - 1, r = 2 * n - 1;
			while(l + 1 < r) {
				int m = (l + r + 1) >> 1;
				if(getMin(i, m) * 2 >= a[i])
					l = m;
				else 
					r = m;
			}
			nxtL[i] = r;
		}
		{
			int l = i - 1, r = 2 * n - 1;
			while(l + 1 < r) {
				int m = (l + r + 1) >> 1;
				if(getMax(i, m) == a[i]) 
					l = m;
				else 
					r = m;
			}
			nxtR[i] = r;
		}
		if(nxtL[i] < nxtR[i])
			ans[i] = nxtL[i] - i;
	}
	for(int i = 0; i < n; i++)
		if(nxtL[i] > nxtR[i])
			dfs(i);
	for(int i = 0; i < n; i++) 
		printf("%d ", ans[i]);
	return 0;
}