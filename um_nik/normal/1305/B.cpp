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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
int n;
char s[N];
vector<int> ans;

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	int m = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == ')')
			m++;
	for (int i = 0; i < n; i++) {
		if (i < m) {
			if (s[i] == '(') ans.push_back(i + 1);
		} else {
			if (s[i] == ')') ans.push_back(i + 1);
		}
	}
	if (ans.empty()) {
		printf("0\n");
	} else {
		printf("1\n%d\n", (int)ans.size());
		for (int x : ans)
			printf("%d ", x);
		printf("\n");
	}

	return 0;
}