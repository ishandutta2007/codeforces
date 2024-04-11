#include <bits/stdc++.h>
using namespace std;

int ans, n, q;
struct node
{
	int lt, rt, val;
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
	int lt = it -> lt, rt = it -> rt, val = it -> val;
	Se.erase(it);
	Se.insert((node){lt, x - 1, val});
	return Se.insert((node){x, rt, val}).first;
}
void assign(int lt, int rt, int val)
{
	set <node> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt), tmp;
	tmp = it_l;
	for (; it_l != it_r; it_l++)
		ans -= it_l -> val * (it_l -> rt - it_l -> lt + 1);
	Se.erase(tmp, it_r);
	Se.insert((node){lt, rt, val});
	ans += val * (rt - lt + 1);
}
int main()
{
	scanf("%d%d", &n, &q);
	Se.insert((node){1, n, 1});
	ans = n;
	for (int i = 1; i <= q; i++)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		assign(x, y, k - 1);
		printf("%d\n", ans);
	}
	return 0;
}