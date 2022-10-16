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

int n;

void add_variant(set<ull>& res, ull a, ull b) {
	res.insert(b+a*(b-1)*b/2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	set<ull> res;
	for(int i = 1; i*i <= n; ++i) {
		if(n%i != 0) continue;
		add_variant(res, i, n/i);
		add_variant(res, n/i, i);
	}

	for(ll x : res)
		cout << x << ' ';
}