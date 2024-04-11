#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;			//  ll - signed int64
typedef unsigned long long ull;	// ull - unsigned int64
typedef double df;				//  df - double
typedef long double lf;			//  lf - long double

int a, b, c, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> a >> b >> c;
	cout << 6 + 3*min(a-1, min(b-2, c-3));
}