/***
4
6 6 4 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bigint {
	static const int LEN = 6;
	static const int BIGMOD = 10000;

	int s;			// sign of big integer
	int vl, v[LEN];	// vl is length of v array

	bigint() : s(1) { vl = 0; }   // eg. bigint x;

	bigint(long long a) {			// eg. bigint x(a);
		s = 1; vl = 0;
		if (a < 0) { s = -1; a = -a; }
		while (a) {
			push_back(a % BIGMOD);
			a /= BIGMOD;
		}
	}

	bigint(string str) {			// eg. bigint x(str);
		s = 1; vl = 0;
		int stPos = 0, num = 0;
		if (!str.empty() && str[0] == '-') {
			stPos = 1;
			s = -1;
		}
		for (int i = str.length() - 1, q = 1; i >= stPos; i--) {
			num += (str[i] - '0') * q;
			if ((q *= 10) >= BIGMOD) {
				push_back(num);
				num = 0; q = 1;
			}
		}
		if (num) push_back(num);
	}

	int len() const {
		return vl;
	}

	bool empty() const { return len() == 0; }

	void push_back(int x) {
		v[vl++] = x;
	}

	void pop_back() {
		vl--;

	}

	int back() const {
		return v[vl - 1];
	}

	void n() {
		while (!empty() && !back()) pop_back();
	}

	void resize(int nl) {
		vl = nl;
		memset(v, 0, sizeof(int)*vl);
	}

	void print() const {
		if (empty()) { putchar('0'); return; }
		if (s == -1) putchar('-');
		printf("%d", back());
		for (int i = len() - 2; i >= 0; i--) printf("%.4d", v[i]);
	}

	friend std::ostream& operator << (std::ostream& out, const bigint &a) {
		if (a.empty()) { out << "0"; return out; }
		if (a.s == -1) out << "-";
		out << a.back();
		for (int i = a.len() - 2; i >= 0; i--) {
			char str[10];
			snprintf(str, 5, "%.4d", a.v[i]);
			out << str;
		}
		return out;
	}

	int compare(const bigint &b)const {
		if (s != b.s) return s - b.s;
		if (s == -1) return -(-*this).compare(-b);
		if (len() != b.len()) return len() - b.len(); //int
		for (int i = len() - 1; i >= 0; i--)
			if (v[i] != b.v[i]) return v[i] - b.v[i];
		return 0;
	}

	bool operator < (const bigint &b)const { return compare(b) < 0; }
	bool operator <= (const bigint &b)const { return compare(b) <= 0; }
	bool operator == (const bigint &b)const { return compare(b) == 0; }
	bool operator != (const bigint &b)const { return compare(b) != 0; }
	bool operator > (const bigint &b)const { return compare(b) > 0; }
	bool operator >= (const bigint &b)const { return compare(b) >= 0; }

	bigint operator - () const {
		bigint r = (*this);
		r.s = -r.s;
		return r;
	}
	bigint operator + (const bigint &b) const {
		if (s == -1) return -(-(*this) + (-b));
		if (b.s == -1) return (*this) - (-b);
		bigint r;
		int nl = max(len(), b.len());
		r.resize(nl + 1);
		for (int i = 0; i < nl; i++) {
			if (i < len()) r.v[i] += v[i];
			if (i < b.len()) r.v[i] += b.v[i];
			if (r.v[i] >= BIGMOD) {
				r.v[i + 1] += r.v[i] / BIGMOD;
				r.v[i] %= BIGMOD;
			}
		}
		r.n();
		return r;
	}
	bigint operator - (const bigint &b) const {
		if (s == -1) return -(-(*this) - (-b));
		if (b.s == -1) return (*this) + (-b);
		if ((*this) < b) return -(b - (*this));
		bigint r;
		r.resize(len());
		for (int i = 0; i < len(); i++) {
			r.v[i] += v[i];
			if (i < b.len()) r.v[i] -= b.v[i];
			if (r.v[i] < 0) {
				r.v[i] += BIGMOD;
				r.v[i + 1]--;
			}
		}
		r.n();
		return r;
	}
	bigint operator * (const bigint &b) {
		bigint r;
		r.resize(len() + b.len() + 1);
		r.s = s * b.s;
		for (int i = 0; i < len(); i++) {
			for (int j = 0; j < b.len(); j++) {
				r.v[i + j] += v[i] * b.v[j];
				if (r.v[i + j] >= BIGMOD) {
					r.v[i + j + 1] += r.v[i + j] / BIGMOD;
					r.v[i + j] %= BIGMOD;
				}
			}
		}
		r.n();
		return r;
	}
	bigint operator / (const bigint &b) {
		bigint r;
		r.resize(max(1, len() - b.len() + 1));
		int oriS = s;
		bigint b2 = b; // b2 = abs(b)
		s = b2.s = r.s = 1;
		for (int i = r.len() - 1; i >= 0; i--) {
			int d = 0, u = BIGMOD - 1;
			while (d < u) {
				int m = (d + u + 1) >> 1;
				r.v[i] = m;
				if ((r * b2) > (*this)) u = m - 1;
				else d = m;
			}
			r.v[i] = d;
		}
		s = oriS;
		r.s = s * b.s;
		r.n();
		return r;
	}
	bigint operator % (const bigint &b) {
		return (*this) - (*this) / b * b;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n + 1];
	a[0] = 0;
	ll s[n + 1];
	s[0] = 0;
	map<ll, ll>kiek;
	bigint ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		if (kiek.count(a[i]) == 0)
			kiek[a[i]] = 0;
		if (kiek.count(a[i] + 1) == 0)
			kiek[a[i] + 1] = 0;
		if (kiek.count(a[i] - 1) == 0)
			kiek[a[i] - 1] = 0;
		ll k = kiek[a[i]] + kiek[a[i] + 1] + kiek[a[i] - 1];
		ll pridek = (i - 1 - k) * a[i] + kiek[a[i]] * a[i] + kiek[a[i] + 1] * (a[i] + 1) + kiek[a[i] - 1] * (a[i] - 1) - s[i - 1];
		ans = ans + pridek;
		kiek[a[i]]++;
	}
	cout << ans;
}