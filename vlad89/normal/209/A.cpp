#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <sstream>
#include <set>
#include <time.h>
#include <memory.h>
#include <queue>
#include <bitset>
#include <functional>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define UNIQUE(x) sort(all(x)),(x).resize(unique(all(x))-(x).begin())
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long ll;

const int mod = 1000000007;
int d[1234567][2];

int main () {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i][0] = d[i-1][0];
		d[i][1] = d[i-1][1];
		d[i][i%2] += d[i-1][1 - (i%2)]+1;
		d[i][i%2] %= mod;
	}
	cout << (d[n][0] + d[n][1]) % mod << endl;
#ifdef LocalHost
	cout << "--FINISHED--" << endl;
	while (1);
#endif
	return 0;
}