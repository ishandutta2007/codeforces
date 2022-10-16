#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double ld;

int n;
ld r, a, R;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> r;
	a = sin(M_PI/n);
	cout << setprecision(9) << fixed << r*a/(1-a);
}