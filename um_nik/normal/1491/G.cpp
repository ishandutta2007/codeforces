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
int p[N];
int pp[N];
bool used[N];
bool ww[N];
vector<pii> ans;
vector<vector<int>> cycles;
int n;

void read() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		p[x] = i;
	}
}

void solveTwo(vector<int> C1, vector<int> C2) {
	int x = C1[0], y = C2[0];
	ans.push_back(mp(x, y));
	while((int)C1.size() > 1) {
		int z = C1.back();
		ans.push_back(mp(x, z));
		x = z;
		C1.pop_back();
	}
	while((int)C2.size() > 1) {
		int z = C2.back();
		ans.push_back(mp(y, z));
		y = z;
		C2.pop_back();
	}
	ans.push_back(mp(x, y));
}

void solveThree(vector<int> C1, vector<int> C2, vector<int> C3) {
	int x = C1[0], y = C2[0];
	ans.push_back(mp(x, y));
	while((int)C1.size() > 1) {
		int z = C1.back();
		ans.push_back(mp(x, z));
		x = z;
		C1.pop_back();
	}
	while((int)C2.size() > 1) {
		int z = C2.back();
		ans.push_back(mp(y, z));
		y = z;
		C2.pop_back();
	}
	int v = C3[0];
	ans.push_back(mp(x, v));
	while((int)C3.size() > 1) {
		int z = C3.back();
		ans.push_back(mp(v, z));
		v = z;
		C3.pop_back();
	}
	ans.push_back(mp(x, v));
	ans.push_back(mp(x, y));
}

void solveOneBig(vector<int> cyc) {
	int x = cyc[0];
	int y = cyc[1];
	int z = cyc[2];
	ans.push_back(mp(x, y));
	ans.push_back(mp(y, z));
	swap(cyc[1], cyc[2]);
	while((int)cyc.size() > 1) {
		int v = cyc.back();
		ans.push_back(mp(v, x));
		x = v;
		cyc.pop_back();
	}
}

void solveOneSmall(vector<int> cyc) {
	int z = 1;
	while(z == cyc[0] || z == cyc[1]) z++;
	assert(p[z] == z);
	solveTwo(cyc, {z});
}

void checkAndPrint() {
	for (int i = 1; i <= n; i++) {
		ww[i] = 0;
		pp[i] = p[i];
	}
	printf("%d\n", (int)ans.size());
	for (pii t : ans) {
		int x = t.first, y = t.second;
		printf("%d %d\n", pp[x], pp[y]);
		swap(pp[x], pp[y]);
		ww[x] ^= 1;
		ww[y] ^= 1;
	}
	for (int i = 1; i <= n; i++) {
		assert(pp[i] == i);
		assert(!ww[i]);
	}
	
}

void solve() {
	for (int i = 1; i <= n; i++)
		used[i] = 0;
	ans.clear();
	cycles.clear();
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		vector<int> cyc;
		int x = i;
		while(!used[x]) {
			cyc.push_back(x);
			used[x] = 1;
			x = p[x];
		}
		if ((int)cyc.size() == 1) continue;
		cycles.push_back(cyc);
	}
	if ((int)cycles.size() % 2 == 0) {
		for (int i = 0; i < (int)cycles.size(); i += 2)
			solveTwo(cycles[i], cycles[i + 1]);
	} else if ((int)cycles.size() >= 3) {
		solveThree(cycles[0], cycles[1], cycles[2]);
		for (int i = 3; i < (int)cycles.size(); i += 2)
			solveTwo(cycles[i], cycles[i + 1]);
	} else {
		if ((int)cycles[0].size() >= 3)
			solveOneBig(cycles[0]);
		else
			solveOneSmall(cycles[0]);
	}
//	for (pii t : ans)
//		eprintf("%d %d\n", t.first, t.second);
	assert((int)ans.size() <= n + 1);
	checkAndPrint();
	/*
	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first, t.second);
	*/
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	read();
	solve();

	return 0;

	for (n = 3; n < 7; n++) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
		do {
			for (int i = 1; i <= n; i++)
				eprintf("%d ", p[i]);
			eprintf("\n");
			solve();
		} while(next_permutation(p + 1, p + n + 1));
	}

	return 0;
}