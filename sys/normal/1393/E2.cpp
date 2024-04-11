#include <bits/stdc++.h>
using namespace std;
 
typedef pair <long long, long long> pll;
const int Maxn = 1000011, p = 1e9 + 7;
const int p1 = 1e9 + 7, p2 = 1e9 + 9, seed1 = 29, seed2 = 31;
int n, ct, las, cnt, dfn_cnt, dep[Maxn], head[Maxn], f[Maxn], sum[Maxn];
string S, str[Maxn / 10];
long long P1[Maxn], P2[Maxn];
vector <int> ord[Maxn / 10];
vector <pll> Hash[Maxn / 10];
pll get_hash(int x, int lt, int rt)
{
	lt++, rt++;
	return make_pair((Hash[x][rt].first - Hash[x][lt - 1].first * P1[rt - lt + 1] % p1 + p1) % p1, (Hash[x][rt].second - Hash[x][lt - 1].second * P2[rt - lt + 1] % p2 + p2) % p2);
}
int lcp(int x, int p1, int y, int p2)
{
	int l = 0, r = min(str[x].size() - p1, str[y].size() - p2);
	while (l + 1 <= r)
	{
		int mid = (l + r + 1) >> 1;
		if (get_hash(x, p1, p1 + mid - 1) == get_hash(y, p2, p2 + mid - 1)) l = mid;
		else r = mid - 1;
	}
	return l;
}
void work(string s, vector <int> & V)
{
	int tmp_ct = 0;
	vector <int> equ, front, back;
	for (int i = 0; i < (int) s.size() - 1; i++)
	{
		if (s[i] == s[i + 1]) equ.push_back(i);
		else if (s[i] < s[i + 1])
		{
			for (auto now : equ) back.push_back(now);
			equ.clear();
			back.push_back(i);
		}
		else
		{
			for (auto now : equ) front.push_back(now);
			equ.clear();
			front.push_back(i);
		}
	}
	for (auto now : front) V[++tmp_ct] = now;
	V[++tmp_ct] = s.size() - 1;
	reverse(back.begin(), back.end());
	for (auto now : back) V[++tmp_ct] = now;
}
bool leq(pair <int, int> x, pair <int, int> y)
{
	int p1 = min(x.second, y.second), p2 = max(x.second, y.second);
	int l = lcp(x.first, 0, y.first, 0);
	if (l < p1) return str[x.first][l] < str[y.first][l];
	if (p1 != p2)
	{
		int sx = p1 + (x.second == p1), sy = p1 + (y.second == p1);
		if (sx == (int) str[x.first].size()) return true;
		if (sy == (int) str[y.first].size()) return false;
		l = lcp(x.first, sx, y.first, sy);
		if (l < p2 - p1)
		{
			if (sx + l == (int) str[x.first].size()) return true;
			if (sy + l == (int) str[y.first].size()) return false;
			return str[x.first][sx + l] < str[y.first][sy + l];
		}
	}
	if (p2 + 1 == (int) min(str[x.first].size(), str[y.first].size()))
		return p2 + 1 == (int) str[x.first].size() || str[x.first][p2 + 1] == '`';
	l = lcp(x.first, p2 + 1, y.first, p2 + 1);
	if (p2 + 1 + l == (int) min(str[x.first].size(), str[y.first].size()))
		return p2 + 1 + l == (int) str[x.first].size();
	return str[x.first][p2 + 1 + l] < str[y.first][p2 + 1 + l];
}
int main()
{
	dep[0] = 0x3f3f3f3f;
	ct = las = 1;
	scanf("%d", &n);
	P1[0] = P2[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		P1[i] = P1[i - 1] * seed1 % p1, P2[i] = P2[i - 1] * seed2 % p2;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		str[i] += 'a' - 1;
		ord[i].resize(str[i].size() + 1);
		Hash[i].resize(str[i].size() + 1);
		work(str[i], ord[i]);
		for (int j = 1; j <= (int) str[i].size(); j++)
		{
			Hash[i][j].first = (Hash[i][j - 1].first * seed1 + str[i][j - 1] - 'a' + 2) % p1;
			Hash[i][j].second = (Hash[i][j - 1].second * seed2 + str[i][j - 1] - 'a' + 2) % p2;
		}
	}
	for (int i = 1; i <= (int) str[1].size(); i++)
		sum[i] = i;
	for (int i = 2; i <= n; i++)
	{
		int pnt = 0;
		for (int j = 1; j <= (int) str[i].size(); j++)
		{
			while (pnt != (int) str[i - 1].size() && leq(make_pair(i - 1, ord[i - 1][pnt + 1]), make_pair(i, ord[i][j])))
				pnt++;
			f[j] = pnt >= 0 ? sum[pnt] : 0;
		}
		for (int j = 1; j <= (int) str[i].size(); j++)
			sum[j] = (sum[j - 1] + f[j]) % p;
	}
	printf("%d", sum[str[n].size()]);
	return 0;
}