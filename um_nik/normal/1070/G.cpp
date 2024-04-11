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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 105;
int n, m;
bool canGo[N][N];
int hp[N];
pii heroes[N];
int a[N];
int dpL[N], dpR[N];
int posL[N], posR[N];
int idL[N], idR[N];
bool used[N];

bool solveRight(int k, int f) {
	int s = 0;
	for (int i = 0; i < k; i++) {
		idR[s] = heroes[i].second;
		posR[s] = heroes[i].first;
		s++;
	}
	posR[s] = f + 1;
	for (int i = 0; i <= s; i++)
		dpR[i] = -1;
	dpR[s] = -2;
	for (int i = s - 1; i >= 0; i--)
		for (int j = i + 1; j <= s; j++) {
			if (dpR[j] != -1 && canGo[idR[i]][posR[j] - 1]) {
				dpR[i] = j;
				break;
			}
		}
	return dpR[0] != -1;
}
bool solveLeft(int k, int f) {
	int s = 0;
	for (int i = m - 1; i >= k; i--) {
		idL[s] = heroes[i].second;
		posL[s] = heroes[i].first;
		s++;
	}
	posL[s] = f - 1;
	for (int i = 0; i <= s; i++)
		dpL[i] = -1;
	dpL[s] = -2;
	for (int i = s - 1; i >= 0; i--)
		for (int j = i + 1; j <= s; j++) {
			if (dpL[j] != -1 && canGo[idL[i]][posL[j] + 1]) {
				dpL[i] = j;
				break;
			}
		}
	return dpL[0] != -1;
}

void printAnsRight(int k, int f) {
	int s = k;
	for (int i = 0; i < s; i++)
		used[i] = false;
	vector<int> ans;
	int v = 0;
	while(v < s) {
		ans.push_back(idR[v]);
		used[v] = 1;
		v = dpR[v];
	}
	reverse(ans.begin(), ans.end());
	for (int x : ans)
		printf("%d ", x + 1);
	for (int i = 0; i < s; i++)
		if (!used[i])
			printf("%d ", idR[i] + 1);
}
void printAnsLeft(int k, int f) {
	int s = m - k;
	for (int i = 0; i < s; i++)
		used[i] = false;
	vector<int> ans;
	int v = 0;
	while(v < s) {
		ans.push_back(idL[v]);
		used[v] = 1;
		v = dpL[v];
	}
	reverse(ans.begin(), ans.end());
	for (int x : ans)
		printf("%d ", x + 1);
	for (int i = 0; i < s; i++)
		if (!used[i])
			printf("%d ", idL[i] + 1);
}

bool solve(int f) {
	int pos = 0;
	while(heroes[pos].first < f) pos++;
	if (solveRight(pos, f - 1) && solveLeft(pos, f)) {
		printf("%d\n", f + 1);
		printAnsLeft(pos, f);
		printAnsRight(pos, f - 1);
		printf("\n");
		return true;
	}
	if ((pos == m || heroes[pos].first != f) && solveRight(pos, f) && solveLeft(pos, f + 1)) {
		printf("%d\n", f + 1);
		printAnsRight(pos, f);
		printAnsLeft(pos, f + 1);
		printf("\n");
		return true;
	}
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &heroes[i].first, &hp[i]);
		heroes[i].first--;
		heroes[i].second = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int s = heroes[i].first;
		int cur = hp[i];
		canGo[i][s] = 1;
		for (int x = s - 1; x >= 0; x--) {
			cur += a[x];
			if (cur < 0) break;
			canGo[i][x] = 1;
		}
		cur = hp[i];
		for (int x = s + 1; x < n; x++) {
			cur += a[x];
			if (cur < 0) break;
			canGo[i][x] = 1;
		}
	}
	sort(heroes, heroes + m);
	for (int x = heroes[0].first; x <= heroes[m - 1].first; x++)
		if (solve(x))
			return 0;
	printf("-1\n");

	return 0;
}