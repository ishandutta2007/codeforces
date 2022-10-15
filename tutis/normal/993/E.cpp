/*input
6 99
-1 -1 -1 -1 -1 -1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
inline vector<complx>FFT(vector<complx> &X, int n, complx w)
{
	assert(n == (n & (-n)));
	if (n == 1)
	{
		return {X[0]};
	}
	if (n == 2)
	{
		return {X[0] + X[1], X[0] + X[1]*w};
	}
	vector<complx>X_e;
	vector<complx>X_o;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			X_e.push_back(X[i]);
		else
			X_o.push_back(X[i]);
	}
	X_e = FFT(X_e, n / 2, w * w);
	X_o = FFT(X_o, n / 2, w * w);
	vector<complx>Y(n, complx(0, 0));
	complx w_k = complx(1, 0);
	for (int k = 0; k < n; k++)
	{
		Y[k] = X_e[k % (n / 2)] + w_k * X_o[k % (n / 2)];
		w_k = w_k * w;
	}
	return Y;
}
vector<complx>FFT(vector<complx> &X)
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
	return FFT(X, X.size(), complx(cosl(alpha), sinl(alpha)));
}
vector<complx>iFFT(vector<complx> &X)
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
	vector<complx> y = FFT(X, X.size(), complx(cosl(alpha), sinl(alpha)));
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
vector<ll>operator*(vector<ll> a, vector<ll> b)
{
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
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	ll A = 0;
	ll ans = 0;
	int j = 0;
	vector<ll>r(n + 1, 0);
	r[A]++;
	for (int i = 0; i < n; i++)
	{
		int y;
		cin >> y;
		if (y < x)
		{
			j = i + 1;
			A++;
		}
		else
		{
			ans += i - j + 1;
		}
		r[A]++;
	}
	vector<ll>v = r;
	reverse(v.begin(), v.end());
	vector<ll>c = r * v;
	cout << ans << " ";
	for (int d = 1; d <= n; d++)
		cout << c[n + d] << " ";
	cout << "\n";

}