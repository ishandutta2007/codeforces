#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 21;
const int P = 998244353;

int n, d[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 2; i < N; i += 2)
		for (int j = 2 * i; j < N; j += i)
			d[j]++;
	int s = 1;
	rep(i, 1, n - 1) 
		s = (2 * s % P + d[2 * i]) % P;
	cout << (s + d[2 * n]) % P << "\n";
	return 0;
}