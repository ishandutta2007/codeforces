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

const int N = 205;
const int INF = 1e9 + 19;

bool was[N][N][N];
queue< pair< int, pair<int, int> > > q;

void add(int r, int g, int b) {
	// cerr << r << " " << g << " " << b << endl;
	if ((r < 0) || (g < 0) || (b < 0)) return;
	if (was[r][g][b]) return;
	was[r][g][b] = true;
	q.push(mp(r,mp(g,b)));
}
 
int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') b++;
		else if (s[i] == 'R') r++;
		else if (s[i] == 'G') g++;
		else assert(false);
	}
	was[r][g][b] = 1;
	q.push(mp(r,mp(g,b)));
	while (!q.empty()) {
		int r = q.front().fr;
		int g = q.front().sc.fr;
		int b = q.front().sc.sc;
		q.pop();
		add(r-1,g-1,b+1);
		add(r-1,g+1,b-1);
		add(r+1,g-1,b-1);
		if (r >= 2) add(r-1,g,b);
		if (g >= 2) add(r,g-1,b);
		if (b >= 2) add(r,g,b-1);
	}
	if (was[0][0][1]) putchar('B');
	if (was[0][1][0]) putchar('G');
	if (was[1][0][0]) putchar('R');
	puts("");
}