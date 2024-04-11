#include <iostream>
#include <algorithm>

using namespace std;

const int N = 107;

typedef long long ll;

int n, a[N], q[N], m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			q[i] += a[j] * (i + abs(j - i) + j);
		if(q[i] < q[m]) m = i;
	}

	cout << q[m] * 2;
}