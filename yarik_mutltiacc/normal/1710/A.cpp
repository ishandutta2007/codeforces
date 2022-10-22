// Problem: A. Color the Picture
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/A
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
	cout << (ok?"Yes":"No") << '\n';
}

int main() {
	#define int ll
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		int AH = 0, AL = 0, BH = 0, BL = 0;
		for(auto &i : a) {
			cin >> i;
			AH += (i/n) < 2 ? 0 : ((i/n) - 2);
			BH += (i/m) < 2 ? 0 : ((i/m) - 2);
			
			AL += (i/n) < 2 ? 0 : 1;
			BL += (i/m) < 2 ? 0 : 1;
		}
		
		auto check = [](int cnt, int r, int n) ->bool {
			if((n % 2) == 1 && r == 0) return 0;
			return 2*cnt + r >= n;
		};
		report(check(AL, AH, m)|| check(BL, BH, n));
	});
	
}