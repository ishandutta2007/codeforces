#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 12222;
const long long INF = 1e9 + 19;
 
using namespace std;

int f[N][10];

int main() {
	// freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	int n = (int)s.size();
	f[n][2] = 1;
	f[n][3] = 1;
	for (int i = n - 2; i >= 5; i--) {
		for (int j = 2; j <= 3; j++) {
			for (int k = 2; k <= 3; k++) {
				if (i + k > n) continue;
				if (!f[i + k][k]) continue;
				string t1, t2;
				for (int e = i; e < i + k; e++) t1 += s[e];
				for (int e = i-j; e < i; e++) t2 += s[e];
				if (t1 == t2) continue;
				f[i][j] = 1;
			}
		}
	}
	set<string> ans;
	for (int i = 5; i <= n; i++) {
		for (int j = 2; j <= 3; j++) {
			if (!f[i][j]) continue;
			if (i - j < 5) continue;
			string t;
			for (int e = i - j; e < i; e++) t += s[e];
			ans.insert(t);
		}
	}
	cout << (int)ans.size() << endl;
	for (string s : ans) {
		puts(s.c_str());
	}
	return 0;
}