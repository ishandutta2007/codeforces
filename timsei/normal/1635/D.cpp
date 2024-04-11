#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n, p, A[N], fib[N];

map <int, int> Map;

int add(int x) {return (x >= mod) ? x - mod : x;}

int main() {
	scanf("%d%d", &n, &p);
	fib[0] = 1; fib[1] = 1;
	fib[2] = 2;
	for(int i = 3; i <= p; ++ i) fib[i] = add(fib[i - 1] + fib[i - 2]);
	for(int i = 1; i <= p; ++ i) fib[i] = add(fib[i - 1] + fib[i]);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &A[i]);
		Map[A[i]] = 1;
	}
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; ++ i) {
		int now = A[i];
		while(1) {
			if(now == 2) break;
			if(now == 1) break;
			if(now % 2 == 0 && now % 4 != 0) break;
			if(now & 1) {
				now = now / 2;
			} else now = now / 4;
			if(Map.count(now)) {
				Map.erase(A[i]); break;
			}
		}
	}
	long long ans = 0;
	for(auto V : Map) {
		int it = 0;
		int x = V.first;
		while((1ll << it) <= x) ++ it;
		if(it > p) break;
		ans += fib[(p - it)];
	}
	cout << ans % mod << endl;
}