#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, n, m;
string s;

const int N = 1 << 20;
const int P = 988244353;

struct hash {
	int b;
	ll base[N], h[N];
	
	void build(string a, int n, int x) {
		b = x;
		base[0] = 1;
		rep(i, 1, n + 1)
			base[i] = base[i - 1] * b % P;
		rep(i, 0, n) 
			h[i + 1] = (h[i] * b + a[i]) % P;
	}
	
	ll ask(int l, int r) {
		return (h[r] - h[l - 1] * base[r - l + 1] % P + P) % P;
	}
} A, B, A1, B1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> s;
		n = sz(s);
		vector<char> front;
		int k = 0;
		while (k < n - 1 - k && s[k] == s[n - 1 - k]) 
			front.push_back(s[k++]);
		m = n - 2 * k;
		string t = s.substr(k, m);
		A.build(t, m, 31);
		A1.build(t, m, 37);
		reverse(t.begin(), t.end());
		B.build(t, m, 31);
		B1.build(t, m, 37);
		reverse(t.begin(), t.end());
		
		int best = 0, l = 0, r = -1;
		rep(i, 0, m) {
			if (A.ask(1, i + 1) == B.ask(m - i, m) && 
				A1.ask(1, i + 1) == B1.ask(m - i, m)) {
				best = i + 1;
				l = 0;
				r = i;
			}
		}
		
		rep(i, 0, m) {
			if (A.ask(m - i, m) == B.ask(1, i + 1) &&
				A1.ask(m - i, m) == B1.ask(1, i + 1) && i + 1 > best) {
				best = i + 1;
				l = m - 1 - i;
				r = m - 1;
			}
		}
		
		for (auto x : front)
			cout << x;
		rep(i, l, r + 1)
			cout << t[i];
		reverse(front.begin(), front.end());
		for (auto x : front)
			cout << x;
		cout << endl;
	}
	return 0;
}