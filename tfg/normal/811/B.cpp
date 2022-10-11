#include <iostream>
#include <algorithm>

const int ms = 10100;
const int bs = 105;

int bit[ms];

void upd(int x, int v)
{
	for(; x < ms; x += x & -x)
		bit[x] += v;
}

int qry(int x)
{
	int ans = 0;
	for(; x > 0; x -= x & -x)
		ans += bit[x];
	return ans;
}

int p[ms];

struct query
{
	int l, r, k, cnt;
	void read(int c)
	{
		cnt = c;
		std::cin >> l >> r >> k;
		l--;r--;k--;
	}
};

bool cmp(query a, query b)
{
	if(a.l / bs < b.l / bs)
		return true;
	else if(a.l / bs == b.l / bs)
		return a.r < b.r;
	else
		return false;
}

query qries[ms];
bool anss[ms];

int main()
{
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < n; i++)
		std::cin >> p[i];
	int l = 0, r = -1;
	for(int i = 0; i < q; i++)
		qries[i].read(i);
	std::sort(qries, qries + q, cmp);
	for(int i = 0; i < q; i++)
	{
		query cur = qries[i];
		while(l < cur.l)
			upd(p[l++], -1);
		while(l > cur.l)
			upd(p[--l], 1);
		while(r < cur.r)
			upd(p[++r], 1);
		while(r > cur.r)
			upd(p[r--], -1);
		anss[cur.cnt] = qry(p[cur.k]) == cur.k - cur.l + 1;
	}
	for(int i = 0; i < q; i++)
	{
		if(anss[i])
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
}