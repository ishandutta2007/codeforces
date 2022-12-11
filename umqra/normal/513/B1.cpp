#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair
int p[100];

int print(int n, int t)
{
	int cnt = 0;
	int best = n + 1;
	do
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int m = n + 1;
			for (int s = i; s < n; s++)
			{
				m = min(m, p[s] + 1);
				ans += m;
			}
		}
		if (ans > best)
			best = ans;
		if (t == ans)
		{
			cnt++;
			for (int i = 0; i < n; i++)
				cout << p[i] + 1 << ' ';
			cout << endl;
		}
	} while (next_permutation(p, p + n));
	cout << best << ":" << cnt << endl;
	return best;
}

void gen(long long n, long long c, int start)
{
	if (n == 1)
	{
		printf("%d ", start);
		return;
	}
	long long cnt = (1 << (n - 1));
	cnt /= 2;
	if (c <= cnt)
	{
		printf("%d ", start);
		gen(n - 1, c, start + 1);
		return;
	}
	else
	{
		gen(n - 1, c - cnt, start + 1);
		printf("%d ", start);
		return;
	}
}

int main()
{
	long long n, c;
	cin >> n >> c;
	gen(n, c, 1);
	return 0;
}