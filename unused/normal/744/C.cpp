#include <bits/stdc++.h>
using namespace std;

struct card
{
	char type;
	int r, b;
};

card cards[16];
int n;

// set, red, blue
int dp1[65536][300], dp2[65536][300];
bool d1[65536][300], d2[65536][300];
pair<int, int> cnt[65536];
int E(int st, int b);

int D(int st, int r)
{
	if (st == 0) return r;
    if (r > n * n) return r - n * n + D(st, n * n);
    auto &ans = dp1[st][r];
    if (d1[st][r] == false)
    {
        d1[st][r] = true;
		ans = 2e9;

		int rc = cnt[st].first, bc = cnt[st].second;

		for (int stt = st; stt; stt -= stt & -stt)
		{
			int i = __builtin_ctz(stt & -stt);
			int p1 = max(0, cards[i].r - rc);
			int p2 = max(0, cards[i].b - bc);
			if (r + p1 >= p2)
			{
				int z = D(st - (1 << i), r + p1 - p2) + p2;
				if (ans > z) ans = z;
			}
			else
			{
				int z = E(st - (1 << i), p2 - r - p1) + r + p1;
				if (ans > z) ans = z;
			}
		}
	}

	return ans;
}

int E(int st, int b)
{
	if (st == 0) return b;
    if (b > n * n) return b - n * n + E(st, n * n);
	auto &ans = dp2[st][b];
    if (d2[st][b] == false)
    {
        d2[st][b] = true;
		ans = 2e9;

		int rc = cnt[st].first, bc = cnt[st].second;

		for (int stt = st; stt; stt -= stt & -stt)
		{
			int i = __builtin_ctz(stt & -stt);
			int p1 = max(0, cards[i].r - rc);
			int p2 = max(0, cards[i].b - bc);
			if (p1 >= b + p2)
			{
				int z = D(st - (1 << i), p1 - b - p2) + b + p2;
				if (ans > z) ans = z;
			}
			else
			{
				int z = E(st - (1 << i), b + p2 - p1) + p1;
				if (ans > z) ans = z;
			}
		}
	}

	return ans;
}

int main()
{
	scanf("%d", &n);
	int rr = 0, bb = 0;
	for (int i = 0; i < n; i++)
	{
		scanf(" %c%d%d", &cards[i].type, &cards[i].r, &cards[i].b);
		if (cards[i].r > n)
		{
			rr += cards[i].r - n;
			cards[i].r = n;
		}
		if (cards[i].b > n)
		{
			bb += cards[i].b - n;
			cards[i].b = n;
		}
	}

	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!(i & (1 << j)))
			{
				if (cards[j].type == 'R') cnt[i].first++;
				else cnt[i].second++;
			}
		}
	}

	if (rr >= bb) printf("%d", D((1 << n) - 1, rr - bb) + n + bb);
	else printf("%d", E((1 << n) - 1, bb - rr) + n + rr);
	fflush(stdout);
	_Exit(0);
}