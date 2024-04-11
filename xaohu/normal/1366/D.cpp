#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
typedef long long ll;	
using namespace std;

const int N = 1e7 + 5;

int n, prime[N], res[N][2];

int main() {
	rep(i, 2, N) 
		if (!prime[i]) 
			rep(j, 1, (N - 1) / i + 1)
				prime[i * j] = i;
	
	cin >> n;
	rep(i, 0, n) {
		int a;
		cin >> a;
		int b = 1;
		int p = prime[a];
		while (a % p == 0) {
			b *= p;
			a /= p;
		}
		if (a == 1)
			res[i][0] = res[i][1] = -1;
		else {
			res[i][0] = a;
			res[i][1] = b;
		}
	}
	rep(j, 0, 2) {
		rep(i, 0, n) 
			cout << res[i][j] << " ";
		cout << "\n";
	}
	return 0;
}