#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxM = MaxN * 2;

int main()
{
	int n;
	int m = 0;
	static pair<int, int> seq[MaxM];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		seq[m++] = make_pair(a, i);
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		seq[m++] = make_pair(a, i);
	}

	sort(seq, seq + m);

	int mod;
	cin >> mod;

	s64 res = 1ll;

	for (int i = 0, j = 0; i < m; i = j)
	{
		while (j < m && seq[i].first == seq[j].first)
			j++;
		int l = j - i;
		int t = 0;
		for (int k = i + 1; k < j; k++)
			if (seq[k] == seq[k - 1])
				t++;

		for (int k = 1; k <= l; k++)
		{
			int tk = k;
			while (t > 0 && tk % 2 == 0)
				tk /= 2, t--;
			res = (res * tk) % mod;
		}
	}

	cout << res << endl;

	return 0;
}