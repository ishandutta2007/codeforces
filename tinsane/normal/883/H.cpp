#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = 400500;

int n;
char s[N];
int cnt[128];

void print_ans(const vector<string>& halves, const vector<char>& mids)
{
	printf("%d\n", (int)halves.size());
	for (int i = 0; i < (int)halves.size(); i++)
	{
		printf("%s", halves[i].c_str());
		if (mids[i] != -1)
			printf("%c", mids[i]);
		string t = halves[i];
		reverse(t.begin(), t.end());
		printf("%s ", t.c_str());
	}
	printf("\n");
}

void solve()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)
		cnt[(int)s[i]]++;

	int cnt1 = 0;
	for (int i = 0; i < 128; i++)
		if (cnt[i] % 2 == 1)
			cnt1++;

	if (cnt1 == 0)
	{
		string half;
		for (int i = 0; i < 128; i++)
			for (int j = 0; j < cnt[i] / 2; j++)
				half += (char)i;
		print_ans({ half }, { (char)-1 });
		return;
	}

	for (int cpal = 1; cpal <= n; cpal++)
		if (n % cpal == 0)
		{
			int len = n / cpal;
			if (len % 2 == 0)
				continue;
			if (cpal < cnt1)
				continue;
			if (cpal % 2 != cnt1 % 2)
				continue;

			vector<char> mids(cpal);
			int ptr = 0;
			for (int i = 0; i < 128; i++)
				if (cnt[i] % 2 == 1)
				{
					mids[ptr++] = (char)i;
					cnt[i]--;
				}
			for (int i = 0; i < 128; i++)
				while (cnt[i] > 0 && ptr < cpal)
				{
					mids[ptr++] = (char)i;
					mids[ptr++] = (char)i;
					cnt[i] -= 2;
				}
			vector<string> halves(cpal);
			ptr = 0;
			for (int i = 0; i < 128; i++)
				for (int j = 0; j < cnt[i] / 2; j++)
				{
					if ((int)halves[ptr].length() == (len - 1) / 2)
						ptr++;
					halves[ptr] += (char)i;
				}

			print_ans(halves, mids);
			return;
		}

	throw;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}