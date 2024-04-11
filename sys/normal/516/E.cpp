#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, d, b, g, x[Maxn], y[Maxn];
long long ans = -1;
vector <int> B[Maxn], G[Maxn];
set <int> Se1, Se2;
map <int, long long> mini;
pair <int, int> exgcd(pair <int, int> x)
{
	if (!x.second) return make_pair(1, 0);
	pair <int, int> tmp = exgcd(make_pair(x.second, x.first % x.second));
	return make_pair(tmp.second, tmp.first - tmp.second * (x.first / x.second));
}
int get_inv(long long x, long long p)
{
	pair <int, int> result = exgcd(make_pair(x, p));
	return (result.first % p + p) % p;
}
int main()
{
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 1; i <= b; i++)
		scanf("%d", &x[i]);
	scanf("%d", &g);
	for (int i = 1; i <= g; i++)
		scanf("%d", &y[i]);
	d = __gcd(n, m);
	if (d > b + g)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= b; i++)
		B[x[i] % d].push_back(x[i] / d);
	for (int i = 1; i <= g; i++)
		G[y[i] % d].push_back(y[i] / d);
	n /= d, m /= d;
	long long invm = get_inv(m % n, n), invn = get_inv(n % m, m);
	for (int i = 0; i < d; i++)
	{
		Se1.clear(), Se2.clear(); 
		vector <int> tmpB = B[i], tmpG = G[i];
		for (vector <int> :: iterator it = B[i].begin(); it != B[i].end(); it++)
			tmpB.push_back((*it - m % n + n) % n), Se1.insert(*it);
		for (vector <int> :: iterator it = G[i].begin(); it != G[i].end(); it++)
			tmpG.push_back((*it - n % m + m) % m), Se2.insert(*it);
		for (vector <int> :: iterator it = B[i].begin(); it != B[i].end(); it++)
			tmpG.push_back(*it % m), tmpG.push_back((*it % m - n % m + m) % m);
		for (vector <int> :: iterator it = G[i].begin(); it != G[i].end(); it++)
			tmpB.push_back(*it % n), tmpB.push_back((*it % n - m % n + n) % n);
		sort(tmpB.begin(), tmpB.end(), [&](int tmpx, int tmpy){return tmpx * invm % n < tmpy * invm % n;});
		sort(tmpG.begin(), tmpG.end(), [&](int tmpx, int tmpy){return tmpx * invn % m < tmpy * invn % m;});
		for (vector <int> :: iterator it = B[i].begin(); it != B[i].end(); it++)
			mini[*it % m] = *it;
		for (vector <int> :: iterator it = G[i].begin(); it != G[i].end(); it++)
			mini[*it] = *it;
		long long Mini = 0x3f3f3f3f3f3f3f3fLL;
		for (vector <int> :: iterator it = tmpG.begin(); it != tmpG.end(); it++)
		{
			if (mini.find(*it) == mini.end()) mini[*it] = 0x3f3f3f3f3f3f3f3fLL;
			mini[*it] = min(mini[*it], Mini + *it * invn % m * n);
			Mini = min(Mini, mini[*it] - *it * invn % m * n);
		}
		for (vector <int> :: iterator it = tmpG.begin(); it != tmpG.end(); it++)
		{
			if (mini.find(*it) == mini.end()) mini[*it] = 0x3f3f3f3f3f3f3f3fLL;
			mini[*it] = min(mini[*it], Mini + (*it * invn % m + m) * n);
			Mini = min(Mini, mini[*it] - (*it * invn % m + m) * n);
			if (Se2.find(*it) == Se2.end()) ans = max(ans, mini[*it] * d + i);
		}
		mini.clear();
		for (vector <int> :: iterator it = G[i].begin(); it != G[i].end(); it++)
			mini[*it % n] = *it;
		for (vector <int> :: iterator it = B[i].begin(); it != B[i].end(); it++)
			mini[*it] = *it;
		Mini = 0x3f3f3f3f3f3f3f3fLL;
		for (vector <int> :: iterator it = tmpB.begin(); it != tmpB.end(); it++)
		{
			if (mini.find(*it) == mini.end()) mini[*it] = 0x3f3f3f3f3f3f3f3fLL;
			mini[*it] = min(mini[*it], Mini + *it * invm % n * m);
			Mini = min(Mini, mini[*it] - *it * invm % n * m);
		}
		for (vector <int> :: iterator it = tmpB.begin(); it != tmpB.end(); it++)
		{
			if (mini.find(*it) == mini.end()) mini[*it] = 0x3f3f3f3f3f3f3f3fLL;
			mini[*it] = min(mini[*it], Mini + (*it * invm % n + n) * m);
			Mini = min(Mini, mini[*it] - (*it * invm % n + n) * m);
			if (Se1.find(*it) == Se1.end()) ans = max(ans, mini[*it] * d + i);
		}
		mini.clear();
		if (!B[i].size() && !G[i].size())
		{
			puts("-1");
			return 0;
		}
	}
	if (ans == 0x3f3f3f3f3f3f3f3fLL)
		puts("-1");
	else printf("%lld", ans);
	return 0;
}