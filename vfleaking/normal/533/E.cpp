#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int NLet = 26;
const int M1 = 1000000007;
const int M2 = 1000000009;

const int MaxN = 100000;

struct shash
{
	int h1, h2;

	shash(){}
	shash(const int &_h1, const int &_h2)
		: h1(_h1 % M1), h2(_h2 % M2){}

	friend inline bool operator<(const shash &lhs, const shash &rhs)
	{
		if (lhs.h1 != rhs.h1)
			return lhs.h1 < rhs.h1;
		return lhs.h2 < rhs.h2;
	}
	friend inline bool operator==(const shash &lhs, const shash &rhs)
	{
		return lhs.h1 == rhs.h1 && lhs.h2 == rhs.h2;
	}
};

shash prep[MaxN + 1];
char s[MaxN + 2];
shash pres[MaxN + 1];
char t[MaxN + 2];
shash pret[MaxN + 1];

shash query_h(int len, shash l, shash r)
{
	return shash(r.h1 + M1 - (s64)l.h1 * prep[len].h1 % M1, r.h2 + M2 - (s64)l.h2 * prep[len].h2 % M2);
}
shash merge_h(int rlen, shash l, shash r)
{
	return shash((s64)l.h1 * prep[rlen].h1 % M1 + r.h1, (s64)l.h2 * prep[rlen].h2 % M2 + r.h2);
}
shash add_h(shash h, int c)
{
	return shash((s64)h.h1 * 131 % M1 + c, (s64)h.h2 * 131 % M2 + c);
}

int main()
{
	int n;
	cin >> n;

	prep[0] = shash(1, 1);
	for (int i = 1; i <= n; i++)
		prep[i] = shash((s64)prep[i - 1].h1 * 131 % M1, (s64)prep[i - 1].h2 * 131 % M2);

	scanf("%s", s + 1);
	scanf("%s", t + 1);

	pres[0] = shash(0, 0);
	for (int i = 1; i <= n; i++)
		pres[i] = add_h(pres[i - 1], s[i]);
	pret[0] = shash(0, 0);
	for (int i = 1; i <= n; i++)
		pret[i] = add_h(pret[i - 1], t[i]);

	int sarr_n = 0;
	static shash sarr[(MaxN + 1) * NLet];
	int tarr_n = 0;
	static shash tarr[(MaxN + 1) * NLet];

	for (int p = 1; p <= n + 1; p++)
		for (char c = 'a'; c <= 'z'; c++)
			sarr[sarr_n++] = merge_h(n - p + 1, add_h(query_h(p - 1, pres[0], pres[p - 1]), c), query_h(n - p + 1, pres[p - 1], pres[n]));
	for (int p = 1; p <= n + 1; p++)
		for (char c = 'a'; c <= 'z'; c++)
			tarr[tarr_n++] = merge_h(n - p + 1, add_h(query_h(p - 1, pret[0], pret[p - 1]), c), query_h(n - p + 1, pret[p - 1], pret[n]));

	sort(sarr, sarr + sarr_n), sarr_n = unique(sarr, sarr + sarr_n) - sarr;
	sort(tarr, tarr + tarr_n), tarr_n = unique(tarr, tarr + tarr_n) - tarr;

	int res = 0;
	for (int i = 0, j = 0; i < sarr_n && j < tarr_n; )
	{
		if (sarr[i] < tarr[j])
			i++;
		else if (tarr[j] < sarr[i])
			j++;
		else
			res++, i++, j++;
	}
	cout << res << endl;

	return 0;
}