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

const int N = 1e6+7;
const int MOD = 998244353;

int d[N], f[N], n;

int add(int a, int b) {
	return ((ll)a+b)%MOD;
}

int sub(int a, int b) {
	return ((ll)a-b+MOD)%MOD;
}

int mul(int a, int b) {
	return ((ll)a*b)%MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	d[1] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; ++i) {
		f[i] = mul(f[i-1], i);
		d[i] = add(mul(d[i-1], i), mul(i-1, i-1));
	}

	cout << sub(mul(n, sub(f[n],1)), sub(d[n],1));
}