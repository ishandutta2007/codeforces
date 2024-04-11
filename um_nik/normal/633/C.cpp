#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;

ll MOD, P;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2) return mult(x, x);
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

typedef pair<ll, int> pli;

const int L = 10100;
const int N = 100100;
int n, m;
string s;
string a[N];
map<pli, int> mapchik;
bool dp[L];
int par[L];
ll p[L];
ll h[L];

bool isPrime(ll x)
{
	for (ll y = 2; y * y <= x; y++)
		if (x % y == 0)
			return false;
	return true;
}

void init()
{
	P = 50 + rand() % 100;
	while(!isPrime(P)) P++;
	MOD = (ll)1e9 + rand() % (ll)1e8;
	while(!isPrime(MOD)) MOD++;
	p[0] = 1;
	for (int i = 1; i < L; i++)
	{
		p[i] = mult(p[i - 1], P);
	}
	return;
}

void read()
{
	cin >> n;
	cin >> s;
	reverse(s.begin(), s.end());
	h[0] = 0;
	for (int i = 0; i < n; i++)
		h[i + 1] = add(mult(h[i], P), (ll)(s[i] - 'a'));
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		s = a[i];
		for (int j = 0; j < s.length(); j++)
			if ('A' <= s[j] && s[j] <= 'Z')
				s[j] += 'a' - 'A';
		ll H = 0;
		for (int j = 0; j < s.length(); j++)
			H = add(mult(H, P), (ll)(s[j] - 'a'));
		if (s.length() <= n)
			mapchik[make_pair(H, s.length())] = i;
	}
	return;
}

void solve()
{
	dp[0] = 1;
	for (int l = 0; l < n; l++)
	{
		if (!dp[l]) continue;
		for (int r = l + 1; r <= n && r - l <= 1010; r++)
		{
			ll H = sub(h[r], mult(h[l], p[r - l]));
			pli tmp = make_pair(H, r - l);
			if (mapchik.count(tmp))
			{
				dp[r] = 1;
				par[r] = mapchik[tmp];
			}
		}
	}
	if (!dp[n]) throw;
	int v = n;
	while(v > 0)
	{
		cerr << v << endl;
		int id = par[v];
		cout << a[id];
		v -= a[id].length();
		if (v > 0)
			cout << " ";
		else
			cout << "\n";
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	read();
	solve();

	return 0;
}