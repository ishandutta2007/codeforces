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

const int N = 200200;
int a[N];
int d[N][2];
int n;
int cnt[N];
vector<int> posForX[N];
int ans = 0;

int countLower(int b, int x) {
	return lower_bound(posForX[b].begin(), posForX[b].end(), x) - posForX[b].begin();	
}

void solve(int b, int c) {
	set<int> intPos;
	for (int i = 0; i < cnt[c]; i++) {
		int x = posForX[c][i];
		int z = countLower(b, x);
		int bal = cnt[b] - z + i;
		intPos.insert(bal);
		intPos.insert(bal + 1);
	}
	for (int x : intPos) {
		d[x][0] = n;
		d[x][1] = -1;
	}
	set<int> setik;
	setik = intPos;
	vector<int> pp;
	pp.push_back(-1);
	for (int x : posForX[c])
		pp.push_back(x);
	pp.push_back(n);
	for (int i = 1; i < (int)pp.size(); i++) {
		int x = pp[i], y = pp[i - 1];
		int maxBal = cnt[b] - countLower(b, y) + i - 1;
		int minBal = cnt[b] - countLower(b, x) + i - 1;
		while(true) {
			auto it = setik.lower_bound(minBal);
			if (it == setik.end()) break;
			int bal = *it;
			if (bal > maxBal) break;
			int toW = bal;
			setik.erase(it);
			bal = cnt[b] - bal + i - 1;
			assert(bal >= 0);
			if (toW == maxBal) {
				d[toW][0] = y + 1;
			} else {
				assert(bal > 0);
				d[toW][0] = posForX[b][bal - 1] + 1;
			}
		}
	}
	setik = intPos;
	for (int i = (int)pp.size() - 1; i > 0; i--) {
		int x = pp[i], y = pp[i - 1];
		int maxBal = cnt[b] - countLower(b, y) + i - 1;
		int minBal = cnt[b] - countLower(b, x) + i - 1;
		while(true) {
			auto it = setik.lower_bound(minBal);
			if (it == setik.end()) break;
			int bal = *it;
			if (bal > maxBal) break;
			int toW = bal;
			setik.erase(it);
			bal = cnt[b] - bal + i - 1;
			assert(bal >= 0);
			if (toW == minBal) {
				d[toW][1] = x;
			} else {
				d[toW][1] = posForX[b][bal];
			}
		}
	}
	for (int x : intPos)
		ans = max(ans, d[x][1] - d[x][0]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		posForX[a[i]].push_back(i);
		cnt[a[i]]++;
	}
	int b = 0;
	for (int i = 0; i < N; i++) {
		if (cnt[i] > cnt[b])
			b = i;
	}
	for (int i = 0; i < N; i++) {
		if (posForX[i].empty()) continue;
		if (i == b) continue;
		solve(b, i);
	}
	printf("%d\n", ans);

	return 0;
}