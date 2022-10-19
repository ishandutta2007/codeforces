#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, A[N], S[N], MAX;

map <int, int> Map;

long long calc(int x) {
	return 1LL * x * (x - 1) / 2;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	int MAX = (1 << k) - 1;
	long long ans = 0, now = 0, res = 0;
	++ Map[0];
	now = 1LL * n * (n + 1) / 2;
	for(int i = 1; i <= n; ++ i) {
		A[i] ^= (A[i - 1]);
		if(A[i] < MAX - A[i]) ++ Map[A[i]];
		else ++ Map[MAX - A[i]];
	}
	for(map <int, int> :: iterator it = Map.begin(); it != Map.end(); ++ it) {
		now -= calc(it -> second / 2) + calc(it -> second - (it -> second) / 2);
	}	
	cout << now << endl;
}