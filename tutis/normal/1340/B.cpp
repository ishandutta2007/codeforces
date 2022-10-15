/*input
2 5
0010010
0010010

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
}
namespace {
const ll mod = 1000000007;
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
const ll maxsz = 10;
ll I[maxsz];
bool calc = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxsz)
	{
		if (!calc)
		{
			calc = true;
			I[1] = 1;
			I[0] = 0;
			for (ll i = 2; i < maxsz; ++i)
				I[i] = (mod - (mod / i) * I[mod % i] % mod) % mod;
		}
		return I[x];
	}
	return power(x, mod - 2);
}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string S[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	int n, k;
	cin >> n >> k;
	string A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	bitset<2001>X[n + 1];
	X[n][0] = 1;
	int cnt[n][10];
	for (int i = n - 1; i >= 0; i--)
	{
		for (int s = 0; s < 10; s++)
		{
			cnt[i][s] = 0;
			for (int k = 0; k < 7; k++)
			{
				if (A[i][k] == '1')
				{
					if (S[s][k] == '0')
						cnt[i][s] -= 100;
				}
				else
				{
					if (S[s][k] == '1')
						cnt[i][s]++;
				}
			}
			if (cnt[i][s] >= 0)
				X[i] |= (X[i + 1] << cnt[i][s]);
		}
	}
	if (X[0][k] == 0)
		cout << "-1";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int x = 9; x >= 0; x--)
			{
				if (k - cnt[i][x] >= 0 && cnt[i][x] >= 0 && X[i + 1][k - cnt[i][x]] == 1)
				{
					cout << x;
					k -= cnt[i][x];
					break;
				}
			}
		}
	}
	return 0;
}