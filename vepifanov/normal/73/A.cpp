#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int x, y, z, k;

int main() {
	cin >> x >> y >> z >> k;
	if (x > y) swap (x, y);
	if (y > z) swap (y, z);
	if (x > y) swap (x, y);
	int a = min (x - 1, k / 3);
	k -= a;
	int b = min (y - 1, k / 2);
	k -= b;
	int c = min (z - 1, k);
	cout << (ll)(a + 1) * (b + 1) * (c + 1) << endl;
	return 0;
}