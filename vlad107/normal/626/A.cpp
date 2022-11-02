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
	//freopen("input.txt", "r", stdin);
	int n;
	string s;
	cin >> n;
	cin >> s;
	// cerr << s << endl;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == 'U') ++y; else
			if (s[j] == 'D') --y; else
			if (s[j] == 'L') --x; else
			if (s[j] == 'R') ++x; else
			assert(false);
			if ((x == 0) && (y == 0)) ++ans;
		}
	}
	cout << ans << endl;
}