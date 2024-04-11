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
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		--a[i];
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		vector<int> cnt(n);
		int mx = -1, nom = -1;
		for (int j = i; j < n; j++) {
			++cnt[a[j]];
			if ((cnt[a[j]] > mx) || ((cnt[a[j]] == mx) && (a[j] < nom))) {
				mx = cnt[a[j]];
				nom = a[j];
			}
			++ans[nom];
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	puts("");
	return 0;
}