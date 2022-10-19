#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;

int A[N] , inv[N] , all[N] , who[N] , a , b , p , x;

int Pow(int x , int y) {
	if(y == 0) return 1;
	if(y == 1) return x % p;
	int it = Pow(x * x % p , y >> 1);
	if(y & 1) it = it * x % p;
	return it;
}

main(void) {
	cin >> a >> b >> p >> x;
	A[0] = 1;
	all[0] = 0; who[0] = 0;
	for(int i = 1;i < p;++ i) {
		all[i] = i * (p - 1) % p;
		who[all[i]] = i;
	}
	int ans = 0;
	for(int i = 1;i < p;++ i) A[i] = A[i - 1] * 1ll * a % p;
	for(int i = 0;i < p - 1;++ i) {
		//b / n
		int T = A[i];
		int n = Pow(T , p - 2) * b % p;
		// %p wei n; % (p - 1) wei i;
		int now = n - i + p;
		now %= p;
		int first = i + (who[now]) * (p - 1);
		if(first > x) continue;
		ans += (x - first) / (p * (p - 1)) + 1;   
	}
	cout << ans << endl;
}