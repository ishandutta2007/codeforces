#include <bits/stdc++.h>
using namespace std;
 
int M;
struct modular {
	int x;
	modular(int x) : x(x) {}
	modular operator+=(modular oth) { x += oth.x; if (x >= M) { x -= M; } return *this; }
	modular operator-=(modular oth) { x -= oth.x; if (x < 0) { x += M; } return *this; }
	modular operator*=(modular oth) { x = (long long)x * oth.x % M; return *this; }
	//modular operator/=(modular oth) { return x *= modinv(oth.x, M); }
	modular operator++() { return *this += 1; }
	modular operator--() { return *this -= 1; }
	modular operator-() { return modular(0) -= *this; }
};
bool operator==(modular a, modular b) { return a.x == b.x; }
bool operator!=(modular a, modular b) { return a.x != b.x; }
modular operator+(modular a, modular b) { return a += b; }
modular operator-(modular a, modular b) { return a -= b; }
modular operator*(modular a, modular b) { return a *= b; }
//modular operator/(modular a, modular b) { return a /= b; }
ostream& operator<<(ostream &os, modular a) { return os << a.x; }
 
using mint = modular;

void solve() {
	int d;
	cin >> d >> M;
	mint ans = 2;
	for (int i = 1; i < 30; ++i) {
		ans = mint(min(1 << i, max(0, d - (1 << i) + 1))) * ans + ans;
	}
	cout << --ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}