#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

const int N = 20;
const int A = 360;

int da, n;
bool d[N][A];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	d[0][0] = true;
	cin >> n;
	for(int k = 0; k < n; ++k) {
		cin >> da;

		for(int i = 0; i < A; ++i)
			if(d[k][i]) d[k+1][(i+da)%A] = d[k+1][(i-da+A)%A] = true;
	}

	cout << (d[n][0] ? "YES" : "NO");
}