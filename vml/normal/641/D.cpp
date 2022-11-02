#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld long double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = (int)1e5 + 10;

ld a[maxn], b[maxn];
ld ansa[maxn], ansb[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		//scanf("%lf", &a[i]);
		cin >> a[i];
		//a[i] = ((i + 1) * (i + 1) - i * i) / 36.0;
	}

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	for (int i = 0; i < n; i++) {
	//	scanf("%lf", &b[i]);
	    cin >> b[i];
		//b[n - i - 1] = ((i + 1) * (i + 1) - i * i) / 36.0;
	}

	for (int i = n - 2; i >= 0; i--) {
		b[i] += b[i + 1];
	}

	if (n == 1) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}

	for (int i = 0; i < n - 1; i++) {
		ld x = a[i];

		ld y = b[i + 1];

		y = -y + x + 1;

		ld c = -y;
		ld e = x;

		ld d = sqrt(fabs(c * c - 4 * e));

		ld ans = (-c + d) / 2;

		ansa[i] = ans;
		ansb[i] = y - ans;
	}

	ansa[n - 1] = 1;
	ansb[n - 1] = 1;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("%lf ", (double)fabs(ansa[i]));
		} else {
			printf("%lf ", (double)fabs(ansa[i] - ansa[i - 1]));
		}
	}

	printf("\n");

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("%lf ", (double)fabs(ansb[i]));
		} else {
    		printf("%lf ", (double)fabs(ansb[i] - ansb[i - 1]));
		}
	}

	return 0;
}