/*input
10
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int klausimas(int l, int r)
{
	string x(n, '0');
	for (int i = l - 1; i < r; i++)
		x[i] = '1';
	cout << "? " << x << endl << flush;
	int h;
	cin >> h;
	return h;
}
string S = "001010101010101010101";
int KLAUSIMAS(int l, int r)
{
	int ret = 0;
	string x(n + 1, '0');
	for (int i = l; i <= r; i++)
		x[i] = '1';
	for (int i = 1; i <= n; i++)
		if (x[i] != S[i])
			ret++;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int l = 1;
	int r = n;
	int k0 = klausimas(l, r);
	int kl0 = k0;
	int pos0 = -1;
	int pos1 = -1;
	while (r >= l)
	{
		int m = (l + r) / 2;
		int h = klausimas(m + 1, r);
		int d = m - l + 1;
		int sk = h - kl0;
		int kk0 = (d - sk) / 2;
		int kkk0 = k0 - kk0;
		int d1 = r - l + 1 - d;
		int kkk1 = d1 - kkk0;
		if (m + 1 <= r)
		{
			if (kkk1 == d1)
			{
				pos1 = r;
			}
			if (kkk0 == d1)
			{
				pos0 = r;
			}
		}
		if (kk0 == 0)
		{
			pos1 = l;
		}
		if (kk0 == d)
		{
			pos0 = l;
		}
		if (pos0 != -1 && pos1 != -1)
		{
			cout << "! " << pos0 << " " << pos1 << endl << flush;
			exit(0);
		}
		if (l == r)
		{
			cout << "! ";
			if (pos0 != -1)
				cout << rand() % n + 1 << " ";
			else
				cout << pos0 << " ";
			if (pos1 != -1)
				cout << rand() % n + 1;
			else
				cout << pos1 << " ";
			cout << endl << flush;
			exit(0);
		}
		if (kk0 < d && kk0 != 0)
		{
			r = m;
			k0 = kk0;
			kl0 -= kkk0;
			kl0 += kkk1;
		}
		else
		{
			l = m + 1;
			k0 = kkk0;
			kl0 = h;
		}
	}
}