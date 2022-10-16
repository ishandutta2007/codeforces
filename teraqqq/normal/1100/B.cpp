#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5+7;
const int M = 1e5+7;

int n, m, a, b[M], q[M], bmin;
char s[M];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for(int k = 0; k < m; ++k) {
		cin >> a; --a;
		s[k] = n == ++q[b[--a]++] ? '1' : '0';
	}

	cout << s;
}