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
	int n, t;
	string s;
	cin >> n >> t;
	cin >> s;
	int x = 0;
	while (s[x] != '.') ++x;
	++x;
	while ((x < (int)s.size()) && (s[x] < '5')) ++x;
	if (x == (int)s.size()) {
		cout << s << endl;
		return 0;
	}
	--t;
	--x;
	while ((t > 0) && (s[x] != '.') && (s[x] - '0' + 1 >= 5)) {
		--x;
		--t;
	}
	if (s[x] != '.') {
		s[x] = s[x] + 1;
		s = s.substr(0, x + 1);
		cout << s << endl;
		return 0;
	} 
	s = s.substr(0, x);
	x = (int)s.size() - 1;
	while ((x >= 0) && (s[x] == '9')) {
		s[x] = '0';
		--x;
	}
	if (x < 0) s = '1' + s; else {
		s[x] = s[x] + 1;
	}
	cout << s << endl;
	return 0;
}