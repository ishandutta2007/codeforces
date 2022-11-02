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

map<int, int> cntX, cntY;
map< pair<int, int>, int > cntXY;

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans += cntX[x];
		ans += cntY[y];
		ans -= cntXY[mp(x, y)];
		cntX[x]++;
		cntY[y]++;
		cntXY[mp(x, y)]++;
	}	
	cout << ans << endl;
	return 0;
}