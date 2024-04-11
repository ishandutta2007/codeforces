#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5;
const int M1 = 1e9 + 7;
const int M2 = (119 << 23) + 1;
const int B = 137;

struct Node {
	int len = 0;
	bool left = false, right = false;
	pair<int, int> hsh = {0, 0};
} st[MX * 2];

pair<int, int> _powB[MX + 1], *powB = _powB + 1;
int n;

int add(int a, int b, int m) {
	return (a += b) < m ? a : a - m;
}

int sub(int a, int b, int m) {
	return (a -= b) < 0 ? a + m : a;
}

int mul(int a, int b, int m) {
	return (ll)a * b % m;
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {add(a.first, b.first, M1), add(a.second, b.second, M2)};
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
	return {sub(a.first, b.first, M1), sub(a.second, b.second, M2)};
}

pair<int, int> operator*(pair<int, int> a, pair<int, int> b) {
	return {mul(a.first, b.first, M1), mul(a.second, b.second, M2)};
}

int modPow(int b, int e, int m) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, modPow(b, e - 1, m), m);
	int tmp = modPow(b, e / 2, m);
	return mul(tmp, tmp, m);
}

void init() {
	powB[-1] = {modPow(B, M1 - 2, M1), modPow(B, M2 - 2, M2)};
	for (int i = 0; i < MX; ++i) {
		powB[i] = powB[i - 1] * make_pair(B, B);
	}
}

Node combine(Node a, Node b) {
	Node res = {
			a.len + b.len, 
			a.len ? a.left : b.left, 
			b.len ? b.right : a.right,
			a.hsh + b.hsh * powB[a.len] 
	};

	if (a.len && b.len && a.right && b.left) {
		res.len -= 2;
		res.hsh = a.hsh - powB[a.len - 1] + (b.hsh - powB[0]) * powB[a.len - 2];
	}
	return res;
}

Node qry(int a, int b) {
	Node resL, resR;
	for (a += n - 1, b += n - 1; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			resL = combine(resL, st[a++]);
		}
		if (b % 2 == 0) {
			resR = combine(st[b--], resR);
		}
	}
	return combine(resL, resR);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	string t;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		int a = t[i] - '0';
		st[i + n] = {1, a, a, {a, a}};
	}
	for (int i = n - 1; i; --i) {
		st[i] = combine(st[i * 2], st[i * 2 + 1]);
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b, len;
		cin >> a >> b >> len;
		Node hshA = qry(a, a + len - 1);
		Node hshB = qry(b, b + len - 1);
		cout << (hshA.hsh == hshB.hsh && hshA.len == hshB.len ? "YES" : "NO") << '\n';
	}
}