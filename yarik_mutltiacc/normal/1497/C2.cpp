// Problem: C1. k-LCM (easy version)
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/contest/1497/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, k;
		cin >> n >> k;
		while(k>3) {
			cout << "1 ";
			k--;n--;
		}
		if(n == 4) {
			cout << "1 1 2\n";
		} else if(n%3 == 0) {
			cout << n/3 << " " << n/3 << " " << n/3 << '\n';
		} else if(n%2 == 1) {
			cout << 1 << " " << n/2 << " " << n/2 << '\n';
		} else if(n%4 == 2) {
			cout<< 2 << " " << (n/4)*2 << " " << (n/4)*2 << '\n';
		} else if(n%4 == 0) {
			cout << n/4 << " " << (2*n)/4 << " " << n/4 << '\n';
		}
	});
	
}
//10 = 2 4 4
//16 = 4 8 4
//22 = 2 10 10
//28 =