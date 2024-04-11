#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long MOD = 1e9 + 7;
const long long base = 65534;
int n, q;
string s[N], w;
char t[N];
long long pw[N], _pw[N], qzh[26][N];
struct HASH
{
	long long hash[N * 20], pw[N * 20];
	void ins(string &s)
	{
		int n = s.size();
		pw[0] = 1;
		for (int i = 1; i <= n; ++ i) hash[i] = (hash[i - 1] * base + s[i - 1] - 'a') % MOD, pw[i] = pw[i - 1] * base % MOD;
	}
	int que(int l, int r){return (hash[r] - hash[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;}
}S, T;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	cin >> s[0] >> (t + 1);
	for (int i = 1; s[i - 1].size() <= 1000000; ++ i)
	{
		s[i] = s[i - 1];
		s[i].push_back(t[i]);
		s[i] += s[i - 1];
	}
	pw[0] = _pw[0] = 1;
	for (int i = 1; i <= n; ++ i)pw[i] = pw[i - 1] * 2 % MOD, _pw[i] = _pw[i - 1] * ((MOD + 1) / 2) % MOD;
	
	for (int i = 1; i <= n; ++ i)
	for (int j = 0; j < 26; ++ j)
	qzh[j][i] = (qzh[j][i - 1] + pw[n - i] * (t[i] - 'a' == j)) % MOD;
	
	while(q --)
	{
		int k, m;
		long long ans = 0;
		cin >> k >> w;
		m = w.size();
		int now = 0;
		while(s[now].size() < m)++ now;
		if(now > k){cout << "0\n"; continue;}
		S.ins(s[now]), T.ins(w);
		for (int i = 1; i + m - 1 <= s[now].size(); ++ i) (ans += pw[k - now] * (S.que(i, i + m - 1) == T.que(1, m))) %= MOD;
		for (int i = 0; i < m; ++ i)
		(ans += (qzh[w[i] - 'a'][k] - qzh[w[i] - 'a'][now] + MOD) * _pw[n - k] % MOD * (S.que(s[now].size() - i + 1, s[now].size()) == T.que(1, i) && S.que(1, m - i - 1) == T.que(i + 2, m))) %= MOD;
		cout << ans << "\n";
	}
}