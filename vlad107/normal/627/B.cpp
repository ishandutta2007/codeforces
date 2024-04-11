#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 1e6;

int n, k, a, b, q, cnt1[N], cnt2[N], sa[N], sb[N];

void add1(int x, int val) {
	for (int i = x + 1; i <= n; i = (i | (i - 1)) + 1) sa[i] += val;
}

void add2(int x, int val) {
	for (int i = x + 1; i > 0; i = (i & (i - 1))) sb[i] += val;
}

int fsum1(int x) {
	int res = 0;
	for (int i = x + 1; i > 0; i = (i & (i - 1))) res += sa[i];
	return res;
}

int fsum2(int x) {
	int res = 0;
	for (int i = x + 1; i <= n; i = (i | (i - 1)) + 1) res += sb[i];
	return res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	while (q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int d, x;
			scanf("%d%d", &d, &x);
			--d;
			int old;
			old = cnt1[d]; cnt1[d] = min(cnt1[d] + x, b);
			add1(d, cnt1[d] - old);
			old = cnt2[d]; cnt2[d] = min(cnt2[d] + x, a);
			add2(d, cnt2[d] - old);
		} else {
			int p;
			scanf("%d", &p);
			--p;
			int sum = fsum1(p - 1) + fsum2(p + k);
			printf("%d\n", sum);
		}
	}
	return 0;	
}