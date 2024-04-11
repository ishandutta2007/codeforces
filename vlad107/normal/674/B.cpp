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

const int N = -1;
const int C = -1;

int main() {
	// freopen("input.txt", "r", stdin);
	int n, m, a, b, c, d;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	--a; --b; --c; --d;
	if ((m < n + 1) || (n == 4)) {
		puts("-1");
		return 0;
	}
	vector<int> w1, w2;
	vector<int> used(n);
	used[a] = used[b] = used[c] = used[d] = 1;
	int u = 0;
	while (used[u]) ++u;
	used[u] = 1;
	w1.pb(a);
	w1.pb(c);
	w1.pb(u);
	w1.pb(d);
	for (int i = 0; i < n; i++) {
		if (!used[i]) w1.pb(i);
	}
	w1.pb(b);

	w2.pb(c);
	w2.pb(a);
	w2.pb(u);
	for (int i = w1.size() - 1; i >= 3; i--) w2.pb(w1[i]);
		
	for (int i = 0; i < n; i++) printf("%d ", w1[i] + 1);
	puts("");
	for (int i = 0; i < n; i++) printf("%d ", w2[i] + 1);
	puts("");
	return 0;
}