#include <bits/stdc++.h>
#define adj_list vector<vi>
#define endl "\n"
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pair<int, int> >
#define pl pair<ll, ll>
#define pll pair<ll, pair<ll, ll> >
#define vi vector<int>
#define vl vector<ll>
using namespace std;
typedef long long int ll;

int lsone(int n)
{
	return (n&-n);
}

void mult(ll a[matmax][matmax], ll b[matmax][matmax], ll c[matmax][matmax], int m, int n, int p)
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			c[i][j] = 0;
			for (int k = 1; k <= n; k++)
			{
				c[i][j] += (a[i][k]*b[k][j])%mod;
				c[i][j] %= mod;
			}
		}
	}
}

void mat_pow(ll a[matmax][matmax], ll c[matmax][matmax], int n, ll p)
{
	if (p == 0)
	{
		for (int i = 1; i <= n; i++)
			c[i][i] = 1;
	}
	else if (p == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				c[i][j] = a[i][j];
		}
	}
	else
	{
		ll d[matmax][matmax];
		mat_pow(a, d, n, p/2);
		if (p % 2)
		{
			ll e[matmax][matmax];
			mult(d, d, e, n, n, n);
			mult(e, a, c, n, n, n);
		}
		else
		{
			mult(d, d, c, n, n, n);
		}
	}
}

ll pow(ll a, ll b)
{
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = pow(a, b/2);
		x *= x;
		x %= mod;
		if (b%2)
		{
			x *= a;
			x %= mod;
		}
		return x;
	}
}

void flip1(int a[110][110], int b[110][110], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[n-i-1][j] = a[i][j];
		}
	}
}

void flip2(int a[110][110], int b[110][110], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][n-j-1] = a[i][j];
		}
	}
}

bool same(int a[110][110], int b[110][110], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}

void rotate(int a[110][110], int n)
{
	int b[110][110];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j][n-i-1] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}	

int n, arr1[110][110], arr2[110][110], arr3[110][110], arr4[110][110], arr5[110][110];
char c;
int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>c;
			arr1[i][j] = (c == 'X');
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>c;
			arr5[i][j] = (c == 'X');
		}
	}

	flip1(arr1, arr2, n);
	flip2(arr1, arr3, n);
	flip2(arr2, arr4, n);

	for (int i = 0; i < 6; i++)
	{
		if (same(arr1, arr5, n))
		{
			cout<<"Yes\n";
			return 0;
		}
		rotate(arr1, n);
	}

	for (int i = 0; i < 6; i++)
	{
		if (same(arr2, arr5, n))
		{
			cout<<"Yes\n";
			return 0;
		}
		rotate(arr2, n);
	}

	for (int i = 0; i < 6; i++)
	{
		if (same(arr3, arr5, n))
		{
			cout<<"Yes\n";
			return 0;
		}
		rotate(arr3, n);
	}

	for (int i = 0; i < 6; i++)
	{
		if (same(arr4, arr5, n))
		{
			cout<<"Yes\n";
			return 0;
		}
		rotate(arr4, n);
	}


	cout<<"No\n";

	return 0;
}