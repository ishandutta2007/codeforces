#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;

typedef long long ll;

int n;
ll s, v[N], vmin, vsum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		vmin = i == 0 ? v[i] : min(vmin, v[i]);
		vsum += v[i];
	}

	if(vsum < s) {
		cout << -1;
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		s -= v[i] - vmin;
		vsum -= v[i] - vmin;
	}
	cout << (s <= 0 ? vmin : vmin - (s+n-1)/n);
}