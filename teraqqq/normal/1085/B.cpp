#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int n, k;
long long x = INF;

long long find_x(int m) {
	return m<k ? ((long long)n/m)*k+m : INF;
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		if(n%i==0) {
			x = min(x, find_x(i));
			x = min(x, find_x(n/i));
		}
	}
	cout << x;
}