#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using ld = long double;

const int INF = 1e8;
const ll LINF = 1e17;

const int N = 1e5+7;

int n, h, t, p, a, b, res;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; p = t, ++i) {
		cin >> t;

		if(t == 1) a = p == t ? a+1 : 1;
		if(t == 2) b = p == t ? b+1 : 1;

		res = max(res, min(a, b));  
		//cout << a << ": " << b << endl;
	}

	cout << 2*res;
}