#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout << "[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]\n"
#define rd() abs((int)rng())
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 1e5 + 100;
const int mod = 998244353;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
vector<string>v[11];
string let;
bool have[256];
ll ways[256][256];
int id[63];
inline void add_self(ll &a, ll b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
ll table[63][63][63];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		string t = s;
		reverse(all(t));
		if (s < t)
			v[sz(s)].pb(s);
		else
			v[sz(t)].pb(t);
	}
	ll ans = 0;
	for (int len = 3; len <= 10; len++)
	{
		sort(all(v[len]));
		memset(have, 0, sizeof have);
		memset(ways, 0, sizeof ways);
		for (int i = 0; i < sz(v[len]); i++)
		{
			int fi = v[len][i][0], la = v[len][i].back();
			have[fi] = 1, have[la] = 1;
			if (i == 0 || v[len][i] != v[len][i - 1])
			{
				if (fi != la)
				{
					ways[fi][la]++;
					ways[la][fi]++;
				}
				else
				{
					bool chk = true;
					for (int j = 0; j < len; j++)
						if (v[len][i][j] != v[len][i][len - j - 1])
							chk = false;
					if (chk)
						ways[fi][fi]++;
					else
						ways[fi][fi] += 2;
				}
			}
		}
		let = "";
		for (int c = 0; c < 256; c++)
			if (have[c]) let += (char)c;
		for (int i = 0; i < sz(let); i++)
			id[let[i]] = i;
		for (int i = 0; i < sz(let); i++)
		{
			for (int j = 0; j < sz(let); j++)
			{
				for (int k = 0; k < sz(let); k++)
				{
					ll sum = 0;
					for (int c = 0; c < sz(let); c++)
					{
						sum += ((ways[let[i]][let[c]] * ways[let[j]][let[c]]) % mod) * ways[let[k]][let[c]];
					}
					sum %= mod;
					table[i][j][k] = sum;
				}
			}
		}
		for (int i = 0; i < sz(let); i++)
		{
			for (int j = i; j < sz(let); j++)
			{
				for (int k = 0; k < sz(let); k++)
				{
					ll sum = 0;
					for (int l = k; l < sz(let); l++)
					{
						ll add = table[i][j][l];
						add *= table[j][k][l];
						if (add >= mod)
							add %= mod;
						add *= table[i][k][l];
						if (i != j)
							add *= 2;
						if (k != l)
							add *= 2;
						sum += add;
					}
					sum %= mod;
					ans += table[i][j][k] * sum;
					ans %= mod;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}