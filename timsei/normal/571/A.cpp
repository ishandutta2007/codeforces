#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

const int mod = 27000000000000007LL;

namespace {
	int add(int x) {
		return (x >= mod) ? x - mod : x;
	}
	
	int sub(int x) {
		return (x < 0) ? x + mod : x;
	}
	
	void Add(int &x, int y) {
		x = add(x + y);
	}
	
	void Sub(int &x, int y) {
		x = sub(x - y);
	}
	
	int Mul(int x, int y) {
		int res = 0;
		for(; y; y >>= 1, x = add(x + x)) {
			if(y & 1) {
				Add(res, x);
			}
		}
		return res;
	}
	
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = Mul(x, x)) {
			if(y & 1) {
				res = Mul(res, x);
			}
		}
		return res;
	}
}

int A, B, C, L, fac[N], inv[N];

int Ch(int x, int y) {
	if(x < y) return 0;
	return Mul(Mul(fac[x], inv[y]), inv[x - y]);
}

int solve(int l) {
	int a = A, b = B, c = C + l, LMAX = L - l;
	if(a + b > c)
	return 0;
	LMAX = min(LMAX, c - a - b);
	return (LMAX + 1) * (LMAX + 2) / 2;
}

main(void) {
	cin >> A >> B >> C >> L;
	swap(A, C);
	int n = 1e6, ans = 0;
	//fac[0] = 1;
	//for(int i = 1; i <= n; ++ i) fac[i] = Mul(fac[i - 1], i);
	//inv[n] = Pow(fac[n], mod - 2);
	//for(int i = n - 1; i >= 1; -- i)
	//inv[i] = Mul(inv[i + 1], i + 1);
	for(int i = 0; i <= L; ++ i) {
		ans += solve(i);
	}
	swap(A, C);
	for(int i = 0; i <= L; ++ i)
	ans += solve(i);
	swap(B, C);
	for(int i = 0; i <= L; ++ i)
	ans += solve(i);
	
	ans = - ans;
	
	for(int i = 0; i <= L; ++ i) ans += (i + 2) * (i + 1) / 2;
	
	cout << ans << endl;
}