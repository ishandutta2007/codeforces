#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

const int INF = 1e9;
const ll LINF = 1e18;

int n, t, a, d, res = INF, k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t;
	for(int i = 0; i < n; ++i) {
		cin >> a >> d;
		if(a < t) a += (t-a+d-1)/d*d;
		if(res > a) res = a, k = i;
	}

	cout << k+1;
}