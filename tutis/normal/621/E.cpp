/***
3 2 1 2
3 1 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[50001];
ll n, b, k, x;
struct box
{
	ll A[100];
	ll sz;
	box(string a)
	{
		fill_n(A, 100, 0);
		if (a == "empty")
			A[0] = 1;
		sz = 1;
	}
	box(int param)
	{
		fill_n(A, 100, 0);
		for (int i = 0; i < n; i++)
			A[a[i] % x]++;
		sz = 10 % x;
	}
};
#define MOD (1000000007ll)
box operator*(box a, box b)
{
	box c("");
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			c.A[(i * b.sz + j) % x] =
			    (c.A[(i * b.sz + j) % x] + a.A[i] * b.A[j]) % MOD;
	c.sz = (a.sz * b.sz) % x;
	return c;
}
box power(box a, int i)
{
	if (i == 0)
		return box("empty");
	if (i == 1)
		return a;
	if (i == 2)
		return a * a;
	if (i % 2 == 0)
		return power(power(a, i / 2), 2);
	return power(power(a, i / 2), 2) * a;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> b >> k >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << power(box(7), b).A[k] << "\n";
}