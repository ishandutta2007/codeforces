/*input
3
a*a
2
aaa
aba
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const ld MY_PI = 3.1415926535897932384626433832795028841971693;
struct complx
{
	ld x, y;
	complx(ld x = 0, ld y = 0): x(x), y(y)
	{

	}
	operator ld()const
	{
		return x;
	}
	operator ll()const
	{
		return round(x);
	}
	friend ostream&operator<<(ostream&stream, complx obj)
	{
		stream << obj.x;
		return stream;
	}
	friend complx operator!(complx a)
	{
		return complx(a.x, -a.y);
	}
	friend complx operator-(complx a)
	{
		return complx(-a.x, -a.y);
	}
	friend complx operator+(complx a)
	{
		return complx(a.x, a.y);
	}
	friend complx operator+(complx a, complx b)
	{
		return complx(a.x + b.x, a.y + b.y);
	}
	friend complx operator-(complx a, complx b)
	{
		return complx(a.x - b.x, a.y - b.y);
	}
	friend complx operator*(complx a, complx b)
	{
		return complx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
	}
	friend complx operator*(complx a, ld b)
	{
		return complx(a.x * b, a.y * b);
	}
	friend complx operator/(complx a, ld b)
	{
		return complx(a.x / b, a.y / b);
	}
	friend complx operator/(complx a, complx b)
	{
		return (a * (!b)) / ld(b * (!b));
	}
};
void FFT(int a, int b, vector<complx> &X, vector<complx> &Y, int n, complx w)
{
	assert(n == (n & (-n)));
	if (n == 1)
	{
		Y[0] = X[0];
		return;
	}
	vector<complx>X_e(n / 2);
	for (int i = 0; i < n; i += 2)
		X_e[i / 2] = X[i];
	vector<complx>Y_e(n / 2);
	FFT(a, (a + b) / 2, X_e, Y_e, n / 2, w * w);
	vector<complx>X_o(n / 2);
	for (int i = 1; i < n; i += 2)
		X_o[i / 2] = X[i];
	vector<complx>Y_o(n / 2);
	FFT((a + b) / 2 + 1, b, X_o, Y_o, n / 2, w * w);
	complx w_k = complx(1, 0);
	for (int k = 0; k < n; k++)
	{
		Y[k] = Y_e[k % (n / 2)] + w_k * Y_o[k % (n / 2)];
		w_k = w_k * w;
	}
}
vector<complx>FFT(vector<complx> X)
{
	while (true)
	{
		int n = X.size();
		if (n != (n & (-n)))
			X.push_back(complx(0, 0));
		else break;
	}
	int n = X.size();
	assert(n == (n & (-n)));
	ld alpha = 2.0 * MY_PI / n;
	vector<complx> y(n);
	FFT(0, X.size() - 1, X, y, X.size(), complx(cosl(alpha), sinl(alpha)));
	return y;
}
vector<complx>iFFT(vector<complx> X)
{
	while (true)
	{
		int n = X.size();
		if (n != (n & (-n)))
			X.push_back(complx(0, 0));
		else break;
	}
	int n = X.size();
	assert(n == (n & (-n)));
	ld alpha = -2.0 * MY_PI / n;
	vector<complx> y(n);
	FFT(0, X.size() - 1, X, y, X.size(), complx(cosl(alpha), sinl(alpha)));
	for (complx &i : y)
		i = i / ld(n);
	return y;
}
vector<complx>multiply(vector<complx> &a, vector<complx> &b)
{
	int n = a.size() + b.size() - 1;
	while (n != (n & (-n)))
		n++;
	while (a.size() < n)
		a.push_back(complx(0, 0));
	while (b.size() < n)
		b.push_back(complx(0, 0));
	vector<complx>A = FFT(a);
	vector<complx>B = FFT(b);
	for (int i = 0; i < A.size(); i++)
		A[i] = A[i] * B[i];
	return iFFT(A);
}
ll convert(string a)
{
	ll w = 1;
	ll ret = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		ret += (a[i] - '0') * w;
		w *= 10;
	}
	return ret;
}
const ll base = 1000;
void fix(vector<ll> &x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != 0 && i + 1 == x.size())
			x.push_back(0);
		while (x[i] < 0)
		{
			x[i] += base;
			x[i + 1]--;
		}
		x[i + 1] += x[i] / base;
		x[i] %= base;
	}
}
void nutrink(vector<ll> &x)
{
	while (!x.empty() && x.back() == 0)
		x.pop_back();
	if (x.empty())
		x.push_back(0);
}
vector<ll>operator*(vector<ll> a, vector<ll> b)
{
	fix(a);
	nutrink(a);
	fix(b);
	nutrink(b);
	vector<complx>A;
	vector<complx>B;
	for (ll i : a)
		A.push_back(complx(i, 0));
	for (ll i : b)
		B.push_back(complx(i, 0));
	vector<complx>C = multiply(A, B);
	vector<ll>ret;
	for (complx i : C)
		ret.push_back(ll(i));
	fix(ret);
	nutrink(ret);
	return ret;
}
vector<ll>operator*(vector<ll> a, ll b)
{
	fix(a);
	nutrink(a);
	vector<ll>ret = a;
	for (ll &i : ret)
		i *= b;
	fix(ret);
	nutrink(ret);
	return ret;
}
vector<ll> p_3 = {1};
void power(ll pow)
{
	if (pow == 0)
	{
		p_3 = {1};
		return;
	}
	if (pow % 2 == 1)
	{
		power(pow - 1);
		p_3 = p_3 * 3;
		return;
	}
	power(pow / 2);
	p_3 = p_3 * p_3;
	return;
}
bool maziau(vector<ll> a, vector<ll> &b)
{
	for (int i = max(a.size(), b.size()) - 1; i >= 0; i--)
	{
		int a_i = 0, b_i = 0;
		if (i < a.size())
			a_i = a[i];
		if (i < b.size())
			b_i = b[i];
		if (a_i != b_i)
			return a_i < b_i;
	}
	return false;
}
bool daugiaul(vector<ll> &a, vector<ll> &b)
{
	for (int i = max(a.size(), b.size()) - 1; i >= 0; i--)
	{
		int a_i = 0, b_i = 0;
		if (i < a.size())
			a_i = a[i];
		if (i < b.size())
			b_i = b[i];
		if (a_i != b_i)
			return a_i >= b_i;
	}
	return true;
}
void print(vector<ll>a)
{
	fix(a);
	if (a.empty())
	{
		cout << "0\n";
		return;
	}
	cout << a.back();
	for (int i = a.size() - 2; i >= 0; i--)
		cout << setw(3) << setfill('0') << a[i];
}
bool revealed[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n) {
		string x;
		cin >> x;
		for (char a : x)
		{
			if (a != '*')
				revealed[a - 'a'] = true;
		}
		int m;
		cin >> m;
		vector<string>gal;
		while (m--)
		{
			string a;
			cin >> a;
			string b = a;
			for (char &i : b)
			{
				if (!revealed[i - 'a'])
					i = '*';
			}
			if (b == x)
			{
				gal.push_back(a);
			}
		}
		int ans = 0;
		for (char t = 'a'; t <= 'z'; t++)
		{
			if (revealed[t - 'a'])
				continue;
			revealed[t - 'a'] = true;
			bool ok = true;
			for (string g : gal)
			{
				for (char &i : g)
				{
					if (!revealed[i - 'a'])
						i = '*';
				}
				if (g == x)
					ok = false;
			}
			ans += ok;
			revealed[t - 'a'] = false;
		}
		cout << ans << "\n";
	}

}