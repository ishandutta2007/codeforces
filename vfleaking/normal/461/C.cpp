#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MaxN = 100000;

int n;
int bit[MaxN + 1];

inline void bit_add(int p, int x)
{
	for (int i = p; i <= n; i += i & -i)
		bit[i] += x;
}
inline int bit_query(int p)
{
	int res = 0;
	for (int i = p; i >= 1; i -= i & -i)
		res += bit[i];
	return res;
}

int main()
{
	int nQ;
	static int a[MaxN + 1];

	cin >> n >> nQ;
	for (int i = 1; i <= n; i++)
		a[i] = 1, bit_add(i, 1);

	int le = 1, ri = n, d = 1;
	while (nQ--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int len;
			scanf("%d", &len);

			if (len * 2 <= abs(le - ri) + 1)
			{
				for (int i = 0; i < len; i++)
				{
					bit_add(le + (len + i) * d, a[le + (len - i - 1) * d]);
					a[le + (len + i) * d] += a[le + (len - i - 1) * d];
				}
				le += len * d;
			}
			else
			{
				len = abs(le - ri) + 1 - len;
				for (int i = 0; i < len; i++)
				{
					bit_add(ri - (len + i) * d, a[ri - (len - i - 1) * d]);
					a[ri - (len + i) * d] += a[ri - (len - i - 1) * d];
				}
				ri -= len * d;

				d *= -1;
				swap(le, ri);
			}
		}
		else if (type == 2)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			r--;

			l = le + l * d;
			r = le + r * d;
			if (l > r)
				swap(l, r);

			int res = bit_query(r) - bit_query(l - 1);
			printf("%d\n", res);
		}
	}

	return 0;
}