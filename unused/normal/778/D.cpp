#include <bits/stdc++.h>
using namespace std;

char d1[55][55], d2[55][55];
vector<pair<int, int>> o1, o2;
int n, m;

template <typename T1>
void process(T1 &&dat, vector<pair<int, int>> &vt)
{
	for (int T = 1;; T++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (T % 2)
				{
					if (dat[i][j] == 'U' && dat[i][j + 1] == 'U')
					{
						vt.emplace_back(i, j);
						dat[i][j] = dat[i + 1][j] = 'L';
						dat[i][j + 1] = dat[i + 1][j + 1] = 'R';
					}
				}
				else
				{
					if (dat[i][j] == 'L' && dat[i + 1][j] == 'L')
					{
						vt.emplace_back(i, j);
						dat[i][j] = dat[i][j + 1] = 'U';
						dat[i + 1][j] = dat[i + 1][j + 1] = 'D';
					}
				}
			}
		}
		bool ended = true;

		if (n % 2 == 0)
		{
			for (int i = 1; i <= n; i += 2) for (int j = 1; j <= m; j++)
			{
				if (dat[i][j] != 'U')
				{
					ended = false; break;
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j+=2)
			{
				if (dat[i][j] != 'L')
				{
					ended = false; break;
				}
			}
		}

		if (ended) break;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", d1[i] + 1);
	for (int i = 1; i <= n; i++) scanf("%s", d2[i] + 1);

	process(d1, o1);
	process(d2, o2);
	reverse(o2.begin(), o2.end());

	printf("%zd\n", o1.size() + o2.size());
	for (auto &&e : o1) printf("%d %d\n", e.first, e.second);
	for (auto &&e : o2) printf("%d %d\n", e.first, e.second);
}