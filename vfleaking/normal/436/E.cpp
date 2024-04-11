#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

typedef long long s64;

const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 300000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

struct item
{
	int va, vb;
	item(){}
	item(const int &_va, const int &_vb)
		: va(_va), vb(_vb){}

	friend inline bool operator<(const item &lhs, const item &rhs)
	{
		return lhs.va + lhs.vb < rhs.va + rhs.vb;
	}
};

int main()
{
	int n, w;

	int a_n = 0;
	static pair<int, int> a[MaxN * 2];

	int b_n = 0;
	static pair<item, int> b[MaxN];

	cin >> n >> w;
	for (int i = 1; i <= n; i++)
	{
		int va, vb;
		scanf("%d %d", &va, &vb);
		vb -= va;

		if (vb > va)
		{
			a[a_n++] = make_pair(va, i);
			a[a_n++] = make_pair(vb, i);
		}
		else
			b[b_n++] = make_pair(item(va, vb), i);
	}

	sort(a, a + a_n);
	sort(b, b + b_n);

	static s64 costA[MaxN * 2 + 1];
	costA[0] = 0;
	for (int i = 0; i < a_n; i++)
		costA[i + 1] = costA[i] + a[i].first;

	static s64 sumB[MaxN + 1];
	sumB[0] = 0;
	for (int i = 0; i < b_n; i++)
		sumB[i + 1] = sumB[i] + b[i].first.va + b[i].first.vb;

	static int preMaxVB[MaxN + 1];
	preMaxVB[0] = INT_MIN;
	for (int i = 0; i < b_n; i++)
		preMaxVB[i + 1] = max(preMaxVB[i], b[i].first.vb);
	static int sufMinVA[MaxN + 1];
	sufMinVA[b_n] = INT_MAX;
	for (int i = b_n - 1; i >= 0; i--)
		sufMinVA[i] = min(sufMinVA[i + 1], b[i].first.va);

	static s64 costB[MaxN * 2 + 1];
	costB[0] = 0;
	for (int i = 0; i <= b_n * 2; i++)
	{
		if (i % 2 == 0)
			costB[i] = sumB[i / 2];
		else
			costB[i] = min(sumB[i / 2 + 1] - preMaxVB[i / 2 + 1], sumB[i / 2] + sufMinVA[i / 2]);
	}

	s64 res = S64_MAX;
	int resP = -1;
	for (int i = max(w - b_n * 2, 0); i <= w && i <= a_n; i++)
		if (tension(res, costA[i] + costB[w - i]))
			resP = i;
	int resQ = w - resP;

	static int sol[MaxN + 1];
	for (int i = 0; i < resP; i++)
		sol[a[i].second]++;
	if (resQ % 2 == 0)
	{
		for (int i = 0; i < resQ / 2; i++)
			sol[b[i].second] = 2;
	}
	else
	{
		if (sumB[resQ / 2 + 1] - preMaxVB[resQ / 2 + 1] == costB[resQ])
		{
			for (int i = 0; i < resQ / 2 + 1; i++)
				sol[b[i].second] = 2;
			for (int i = 0; i < resQ / 2 + 1; i++)
				if (b[i].first.vb == preMaxVB[resQ / 2 + 1])
				{
					sol[b[i].second] = 1;
					break;
				}
		}
		else
		{
			for (int i = 0; i < resQ / 2; i++)
				sol[b[i].second] = 2;
			for (int i = resQ / 2; i < b_n; i++)
				if (b[i].first.va == sufMinVA[resQ / 2])
				{
					sol[b[i].second] = 1;
					break;
				}
		}
	}

	cout << res << endl;
	for (int i = 1; i <= n; i++)
		printf("%d", sol[i]);
	printf("\n");

	return 0;
}