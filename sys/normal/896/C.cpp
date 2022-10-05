#include <bits/stdc++.h>
using namespace std;

int n, m, seed, vmax, ct;
const int Maxn = 100005;
struct node
{
	int lt, rt;
	long long val;
	bool operator < (const node &tmp) const
	{
		return lt < tmp.lt;
	}
};
set <node> Se;
set <node> :: iterator spilt(int x)
{
	if (x > n) return Se.end();
	set <node> :: iterator it = --Se.upper_bound((node){x, 0, 0});
	if (it -> lt == x) return it;
	int lt = it -> lt, rt = it -> rt;
	long long val = it -> val;
	Se.erase(it);
	Se.insert((node){lt, x - 1, val});
	return Se.insert((node){x, rt, val}).first;
}
void assign(int lt, int rt, int val)
{
	set <node> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt);
	Se.erase(it_l, it_r);
	Se.insert((node){lt, rt, val});
}
vector <node> Ve;
void work(int lt, int rt, int x)
{
	Ve.clear();
	set <node> :: iterator tmp, it_r = spilt(rt + 1), it_l = spilt(lt);
	tmp = it_l;
	for (; it_l != it_r; it_l++)
		Ve.push_back((node){it_l -> lt, it_l -> rt, it_l -> val + x});
	Se.erase(tmp, it_r);
	for (vector <node> :: iterator it = Ve.begin(); it != Ve.end(); it++)
		Se.insert(*it);
}
node Tmp[Maxn];
long long ask1(int lt, int rt, int x)
{
	ct = 0;
	set <node> :: iterator tmp, it_r = spilt(rt + 1), it_l = spilt(lt);
	for (; it_l != it_r; it_l++)
		Tmp[++ct] = *it_l;
	sort(Tmp + 1, Tmp + 1 + ct, [](node x, node y){return x.val < y.val;});
	for (int i = 1; i <= ct; i++)
		if (x > Tmp[i].rt - Tmp[i].lt + 1) x -= Tmp[i].rt - Tmp[i].lt + 1;
		else return Tmp[i].val;
}
long long fast_pow(long long x, long long y, int p)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
long long ask2(int lt, int rt, int x, int p)
{
	long long ans = 0;
	set <node> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt);
	for (; it_l != it_r; it_l++)
		ans = (ans + fast_pow(it_l -> val % p, x, p) * (it_l -> rt - it_l -> lt + 1) % p) % p;
	return ans;
}
int rnd(void)
{
	int las = seed;
	seed = (seed * 7LL + 13) % 1000000007;
	return las;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; i++)
	{
		int now = rnd() % vmax + 1;
		Se.insert((node){i, i, now});
	}
	for (int i = 1; i <= m; i++)
	{
		int opt, lt, rt, x, y;
		opt = rnd() % 4 + 1;
		lt = rnd() % n + 1;
		rt = rnd() % n + 1;
		if (lt > rt) swap(lt, rt);
		if (opt == 3) x = rnd() % (rt - lt + 1) + 1;
		else x = rnd() % vmax + 1;
		if (opt == 4)
			y = rnd() % vmax + 1;
		if (opt == 1)
			work(lt, rt, x);
		else if (opt == 2)
			assign(lt, rt, x);
		else if (opt == 3)
			printf("%lld\n", ask1(lt, rt, x));
		else printf("%lld\n", ask2(lt, rt, x, y));
	}
	return 0;
}