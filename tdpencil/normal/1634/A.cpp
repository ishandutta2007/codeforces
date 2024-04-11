#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct fenwick {
private:
    vector<T> fenw;
    int n;
public:
    fenwick (int _n) : n(_n){
        fenw.resize(_n);
    }

    void modify(int x, T v) {
        while(x<n) {
            fenw[x]+=v;
            x |= (x+1);
        }
    }

    T get(int x) {
        T v{};
        while(~x) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
bool isprime(long long n) {
    return isPrime(n);
}
void run_test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t(all(s));
    reverse(all(t));
    if(t==s||k==0) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << "\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int test_case;
	cin >> test_case;

	while(test_case--) {
		run_test_case();
	}
}