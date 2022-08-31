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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

typedef unsigned int uint;

const int L = (int)2e4;
//const int L = 5;
int n;
int m;
bool p[L];
int ps[L];
int lst[L];

uint c[4];
inline uint getF(uint x) {
	uint res = 0;
	for (int i = 0; i < 4; i++) {
		res = res * x + c[i];
	}
	return res;
}

inline uint getP(int y) {
	uint res = 0;
	int x = n / y;
	while(x > 0) {
		res += x;
		x /= y;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> c[i];

	uint ans = 0;

	for (int i = 2; i < L; i++)
		p[i] = 1;
	for (int x = 2; x < L; x++) {
		if (!p[x]) continue;
		ps[m] = x;
		ans += getF(x) * getP(x);
		lst[m] = x + x;
		while(lst[m] < L) {
			p[lst[m]] = 0;
			lst[m] += x;
		}
		lst[m] -= L;
		m++;
	}
	for (int S = L; S <= n; S += L) {
		for (int i = 0; i < L; i++)
			p[i] = 1;
		for (int i = 0; i < m; i++) {
			while(lst[i] < L) {
				p[lst[i]] = 0;
				lst[i] += ps[i];
			}
			lst[i] -= L;
		}
		for (int i = 0; i < L; i++)
			if (p[i])
				ans += getF(S + i) * getP(S + i);
	}
	cout << ans << endl;

	return 0;
}