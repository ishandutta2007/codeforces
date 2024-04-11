#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int Cases, n, q, l[Maxn], r[Maxn], val[Maxn];
string S, T;
set <pair <pair <int, int>, bool> > Se;
set <pair <pair <int, int>, bool> > :: iterator spilt(int x)
{
	if (x > n) return Se.end();
	set <pair <pair <int, int>, bool> > :: iterator it = --Se.lower_bound(make_pair(make_pair(x, 0x3f3f3f3f), false));
	if (it -> first.first == x) return it;
	pair <pair <int, int>, bool> tmp = *it;
	Se.erase(it);
	Se.insert(make_pair(make_pair(tmp.first.first, x - 1), tmp.second));
	return Se.insert(make_pair(make_pair(x, tmp.first.second), tmp.second)).first;
}
bool assign(int lt, int rt)
{
	set <pair <pair <int, int>, bool> > :: iterator it_r = spilt(rt + 1), it_l = spilt(lt);
	int cnt[3];
	cnt[0] = cnt[1] = 0;
	for (auto now = it_l; now != it_r; now++)
		cnt[now -> second] += now -> first.second - now -> first.first + 1;
	if (cnt[0] == cnt[1])
	{
		puts("NO");
		return false;
	}
	Se.erase(it_l, it_r);
	Se.insert(make_pair(make_pair(lt, rt), cnt[1] > cnt[0]));
	return true;
}
int main()
{
	scanf("%d", &Cases);
	while (Cases--)
	{
		scanf("%d%d", &n, &q);
		cin >> S >> T;
		Se.clear();
		for (int i = 1; i <= n; i++)
			Se.insert(make_pair(make_pair(i, i), T[i - 1] == '1'));
		for (int i = 1; i <= q; i++)
			scanf("%d%d", &l[i], &r[i]);
		for (int i = q; i >= 1; i--)
			if (!assign(l[i], r[i])) goto END;
		memset(val, -1, sizeof(int[n + 1]));
		for (auto now : Se)
			for (int i = now.first.first; i <= now.first.second; i++)
				val[i] = now.second;
		for (int i = 1; i <= n; i++)
			if (S[i - 1] - '0' != val[i])
			{
				puts("NO");
				goto END;
			}
		puts("YES");
		END:;
	}
	return 0;
}