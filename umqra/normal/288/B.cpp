#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
int perm[10];
int n, k;
int used[10];
int cc = 1;
const int mod = (int)1e9 + 7;

int mult(int a, int b)
{
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

bool check()
{
	for (int i = 0; i < k; i++)
	{
		cc++;
		int st = perm[i];
		bool h = true;
		while (st != 0)
		{
			if (used[st] == cc)
			{
				h = false;
				break;
			}
			used[st] = cc;
			st = perm[st];
		}
		if (!h)
			return false;
	}                 
	return true;
}

int fact(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

int myPow(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	cin >> n >> k;

	int ans = 0;
	for (int i = 0; i < k; i++)
		perm[i] = 0;

	for (int i = 0; i < myPow(k, k); i++)
	{                                     
		if (check())
			ans++;
		perm[k - 1]++;
		if (perm[k - 1] == k)
		{
			int ind = k - 1;
			while (ind >= 0)
			{
				if (perm[ind] == k)
				{
					perm[ind] = 0;
					if (ind != 0)
						perm[ind - 1]++;
				}
				ind--;
			}
		}
	}

	int t = 1;
	for (int i = 1; i <= n - k; i++)
		t = mult(t, n - k);	

	ans = mult(ans, t);
	cout << ans;

	return 0;
}