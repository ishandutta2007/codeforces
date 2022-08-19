#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair
#define X first
#define Y second

ll MOD;
ll P;
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
map<string, vector<string>> a;
map<pil, vector<string>> b;
map<vector<string>, vector<string>> c;

bool isPrime(ll x)
{
	for (ll y = 2; y * y <= x; y++)
		if (x % y == 0)
			return false;
	return true;
}

void read()
{
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		int x = 7;
		while(x < (int)s.length() && s[x] != '/') x++;
		string name = s.substr(0, x);
		s = s.substr(x, s.length() - x) + '-';
		a[name].push_back(s);
	}
	return;
}

void solve()
{
	for (auto item : a)
	{
		string name = item.first;
		vector<string> s = item.second;
		sort(s.begin(), s.end());
		s.resize(unique(s.begin(), s.end()) - s.begin());
		/*
		int len = 0;
		ll H = 0;
		for (string p : s)
		{
			for (int i = 0; i < (int)p.length(); i++)
			{
				H = add(mult(H, P), p[i]);
				len++;
			}
		}
		b[mp(len, H)].push_back(name);
		*/
		c[s].push_back(name);
	}
	return;
}

vector<vector<string>> ans;

void printAns()
{
	for (auto item : c)
	{
		vector<string> s = item.second;
		if ((int)s.size() > 1)
			ans.push_back(s);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++)
	{
		for (string s : ans[i])
			cout << s << " ";
		cout << '\n';
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	MOD = (ll)1e9 + rand();
	while(!isPrime(MOD)) MOD++;
	P = 300 + rand() % 400;
	while(!isPrime(P)) P++;

	read();
//	cerr << "read" << endl;
	solve();
//	cerr << "solve" << endl;
	printAns();

	return 0;
}