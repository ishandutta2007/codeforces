/*input
3
bab
ba
ab
b
a
b
b
b
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long uint;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int A[26][101];
struct kiekiai
{
	int kiek[26];
	kiekiai() {
		fill_n(kiek, 26, 0);
	}
	kiekiai(string &s)
	{
		fill_n(kiek, 26, 0);
		for (char c : s)
		{
			kiek[c - 'a']++;
		}
	}
	int h()
	{
		int x = 0;
		for (int i = 0; i < 26; i++)
			x ^= A[i][kiek[i]];
		return x;
	}
};
int X[1 << 22];
int Y[1 << 22];
string s;
int n;
char s1;
int i1;
int n1;
void ieskok(int i)
{
	if (i > n)
	{
		string t = s;
		reverse(t.begin(), t.end());
		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				cout << "? " << i + 1 << " " << i + 1 << endl;
				char c;
				cin >> c;
				if (t[i] == c)
					s = t;
				break;
			}
		}
		cout << "! " << s << endl;
		exit(0);
	}
	if (i <= n1)
	{
		s.push_back('a');
		int h0 = 0;
		for (int i = 0; i < 26; i++)
			h0 ^= A[i][0];
		for (char c = 'a'; c <= 'z'; c++)
		{
			bool ok = true;
			s.back() = c;
			vector<int>f;
			int h = h0;
			int kiek[26];
			fill_n(kiek, 26, 0);
			for (int t = 1; t <= (int)s.size(); t++)
			{
				int c = s[(int)s.size() - t] - 'a';
				h ^= A[c][kiek[c]];
				kiek[c]++;
				h ^= A[c][kiek[c]];
				if (Y[h] >= 1)
				{
					X[h]--;
					Y[h]--;
					f.push_back(h);
				}
				else
				{
					ok = false;
					break;
				}
			}
			if (ok)
				ieskok(i + 1);
			for (int i : f)
			{
				Y[i]++;
				X[i]++;
			}
		}
		s.pop_back();
	} else
	{
		s.push_back('a');
		int h0 = 0;
		for (int i = 0; i < 26; i++)
			h0 ^= A[i][0];
		for (char c = 'a'; c <= 'z'; c++)
		{
			bool ok = true;
			s.back() = c;
			vector<int>f;
			int h = h0;
			int kiek[26];
			fill_n(kiek, 26, 0);
			for (int t = 1; t <= (int)s.size(); t++)
			{
				int c = s[(int)s.size() - t] - 'a';
				h ^= A[c][kiek[c]];
				kiek[c]++;
				h ^= A[c][kiek[c]];
				if (X[h] >= 1)
				{
					X[h]--;
					f.push_back(h);
				}
				else
				{
					ok = false;
					break;
				}
			}
			if (ok)
				ieskok(i + 1);
			for (int i : f)
				X[i]++;
		}
		s.pop_back();
	}
}
int32_t main()
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j <= 100; j++)
			A[i][j] = rng() & ((1 << 22) - 1);
	ios_base::sync_with_stdio(false);
	cin >> n;
	n1 = (n + 2) / 3;
	cout << "? 1 " << n1 << endl;
	for (int l = 1; l <= n1; l++)
	{
		for (int r = l; r <= n1; r++)
		{
			string s;
			cin >> s;
			Y[kiekiai(s).h()]++;
		}
	}
	cout << "? 1 " << n << endl;
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			string s;
			cin >> s;
			X[kiekiai(s).h()]++;
		}
	}
	ieskok(1);
}