#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1010;

int n, k, id, a[N][N], s[N], s2[N];

int sq(int x) {
	return x * x;
}

int formula(int a, int b, int c) {
	return c + a - 2 * b;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	rep(i, 0, k) {
		rep(j, 0, n) {
			cin >> a[i][j];
			s[i] += a[i][j];
			s2[i] += sq(a[i][j]);
		}
	}

	int sum = (s[k - 1] - s[0]) / (k - 1);

	rep(i, 1, k - 1)
		if (s[i] != s[0] + sum * i)
			id = i;

	assert(id);

	int sum2 = (id >= 3 ? formula(s2[0], s2[1], s2[2]) : formula(s2[id + 1], s2[id + 2], s2[id + 3]));

	int dif = (s[0] + id * sum) - s[id];

	rep(i, 0, n) {
		if (formula(s2[id - 1], s2[id], s2[id + 1]) + 2 * (sq(a[id][i]) - sq(a[id][i] + dif)) == sum2) {
			cout << id << " " << a[id][i] + dif << endl;
			return 0;
		}
	}

	return 0;
}