#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int a[33], m;
int cnt;

bool dp[101][101][5001];
bool v[101][101][5001];

bool D(int idx, int chosen, int total)
{
	if (total < chosen * (chosen - 1) / 2) return false;
	if (total > cnt * (cnt - 1) / 2) return false;

	if (idx == m) return cnt == chosen && total == cnt * (cnt - 1) / 2;

	if (v[idx][chosen][total] == false)
	{
		v[idx][chosen][total] = true;
		dp[idx][chosen][total] = false;
		for (int i = 1; i + chosen <= cnt; i++)
		{
			if (D(idx + 1, chosen + i, total + a[idx] * i))
				return dp[idx][chosen][total] = true;
		}
	}

	return dp[idx][chosen][total];
}

vector<int> vt;
bool ans[101][101];

void recur(int idx, int chosen, int total)
{
	if (idx == m) return;

	for (int i = 1; i + chosen <= cnt; i++)
	{
		if (D(idx + 1, chosen + i, total + a[idx] * i))
		{
			for (int j = 0; j < i; j++) vt.push_back(a[idx]);
			recur(idx + 1, chosen + i, total + a[idx] * i);
			return;
		}
	}
}

void solve()
{
	memset(dp, 0, sizeof(dp));
	memset(v, 0, sizeof(v));

	if (D(0, 0, 0) == false) return;

	printf("%d\n", cnt);

	recur(0, 0, 0);

    reverse(vt.begin(), vt.end());

	for (int i = cnt - 1; i >= 1; i--)
	{
		int lose = i - vt[i];
        int win = vt[i];

        bool Z[101] = {};

        while (lose--)
        {
            int maxidx = -1;
            for (int j = 0; j < i; j++)
            {
                if (Z[j]) continue;
                if (maxidx == -1 || vt[maxidx] <= vt[j]) maxidx = j;
            }

            ans[maxidx][i] = true;
            vt[maxidx]--;
            Z[maxidx] = true;
        }

        for (int j = 0; j < i; j++)
        {
            if (Z[j] == false) ans[i][j] = true;
        }
	}

	for (int i = 0; i < cnt; i++)
	{
        int sum = 0;
		for (int j = 0; j < cnt; j++)
        {
            printf("%d", ans[i][j]);
        }
		printf("\n");
	}

	exit(0);
}

int main()
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	sort(a, a + m);

	for (cnt = m; cnt <= 100; cnt++)
	{
		solve();
	}

	printf("=(\n");
}