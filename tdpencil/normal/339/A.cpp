#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pr pair
#define pll pr<ll,ll>
#define all(x) x.begin(), x.end()
#define sumvt(x) accumulate(all(x), 0ll)
#define sumat(v, n) accumulate(v, v+n, 0ll)
#define vt vector
#define ar array
template<class t>
void read(t a) {
	cin >> a;
}
template<class t>
void read(vt<t> &a) {
	for(auto &b: a)
		cin >> b;
}
template<class t>
void read(vt<pair<t,t>> &a) {
	for(auto &b: a)
		cin >> b.first >> b.second;
}
template<class t>
void read(vt<ar<t,2>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1];
}
template<class t>
void read(vt<ar<t,3>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2];
}
template<class t>
void read(vt<ar<t,4>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2] >> b[3];
}

template<class t>
void print(t a) {
	cout << a << "\n";
}
template<class t>
void print(vt<t> &a) {
	for(auto &i: a)
		cout << i << " ";
	cout << "\n";
}
template<class t, class v>
void print(vt<pair<t, v>> &a) {
	for(auto &i: a)
		cout << i.first << " " << i.second << "\n";
	cout << "\n";
}

// q is horizontal
// p is vertical

ll gcd(ll x, ll y) {
	ll q,r;
	while(y > 0) {
		q = x / y;
		r = x - q * y;

		x = y;
		y = r;
	}

	return x;
}
struct pt {
	ll x, y;
	pt() : x(0), y(0) {}
	pt(ll a, ll b) : x(a), y(b) {}
	pt(const pt& a) : x(a.x), y(a.y) {}
	pr<ld, ll> slope(const pt& a) {
		ll slp;
		slp = a.y - this->y;
		assert(a.x != this->x);
		slp /= (a.x - this->x);
		ll b;
		b = this->y - (slp * this->x);
		return make_pair(slp, b);
	}
	ll dist(const pt &a) {
		ll d=0;
		d += abs(a.x - this->x);
		d += abs(a.y - this->y);
		return d;
	}
	ll product(const pt &a) {
		ll s =( this->x * (a.y) ) - (this->y * a.x);
		return s;
	}
	pt operator+(const pt &a) {
		pt t(a);
		t.x += this->x;
		t.y += this->y;
		return t;
	}
	pt operator-(const pt &a) {
		pt t(a);
		t.x -= this->x;
		t.y -= this->y;
		return t;
	}
	pt operator*(const pt &a) {
		pt t(a);
		t.x *= this->x;
		t.y *= this->y;
		return t;
	}
	pt operator/(const pt &a) {
		pt t(a);
		t.x /= this->x;
		t.y /= this->y;
		return t;
	}
};
void solve() {
	vt<int> ans;
	string s; cin >> s;
	for(auto ch: s) {
		if(ch == '+') continue;
		ans.push_back((ch-'0'));
	}

	sort(all(ans));
	for(int i=0; i < ans.size()-1; i++)
		cout << ans[i] << "+";
	cout << ans[int(ans.size())-1];


}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
//	int t; cin >> t; while(t--) solve();
	solve();
}