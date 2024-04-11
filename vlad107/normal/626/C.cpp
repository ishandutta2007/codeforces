#include <iostream>
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

const int N = 1e5;
const int INF = 1e9 + 19;
 
int main() {
	// freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	long long ll = 1, rr = 1e18;
	while (ll < rr - 1) {
		long long mid = (ll+rr)/2;
		long long x = mid / 2 - mid / 6;
		long long y = mid / 3 - mid / 6;
		long long z = mid / 6;
		if (((x >= n) && (y + z >= m)) || ((x < n) && (z >= n - x) && (y + z - (n - x) >= m))) {
			rr = mid;
		} else {
			ll = mid;
		}
	}	
	cout << rr << endl;
}