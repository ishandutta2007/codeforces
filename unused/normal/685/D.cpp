#include <bits/stdc++.h>
using namespace std;

int x[100005], y[100005];
map<int, int> now;
map<int, vector<int>> pts;
vector<int> xcrd;
long long ans[100005];

void addp(int y)
{
	now[y]++;
}

void subp(int y)
{
	if (--now[y] == 0) now.erase(y);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		pts[x[i]].push_back(y[i]);
	}
	xcrd = { x, x + n };
	sort(xcrd.begin(), xcrd.end());
	xcrd.erase(unique(xcrd.begin(), xcrd.end()), xcrd.end());

	auto head = pts.begin(), tail = pts.begin();

	for (int l = 0, r = 0; l < xcrd.size(); l++)
	{
		for (r = max(r, l); r < xcrd.size() && xcrd[r] < xcrd[l] + k; r++)
		{
			// [xcrd[l], xcrd[r]]
			long long lx = xcrd[r] - k + 1;
			if (l > 0) lx = max(lx, xcrd[l - 1] + 1ll);

			long long rx = xcrd[l];
			if (r + 1 < xcrd.size()) rx = min(rx, xcrd[r + 1] - (long long)k);

			while (head != pts.end() && head->first < xcrd[l])
			{
				for (int t : head->second) subp(t);
				++head;
			}

			while (tail != pts.end() && tail->first <= xcrd[r])
			{
				for (int t : tail->second) addp(t);
				++tail;
			}

			if (rx < lx) continue;

			int cnt = 0;
			for (auto nit1 = now.begin(), nit2 = now.begin(); nit1 != now.end(); cnt -= nit1->second, nit1++)
			{
				while (nit2 != now.end() && nit2->first < nit1->first)
				{
					cnt += nit2->second;
					++nit2;
				}

				for (; nit2 != now.end() && nit2->first < nit1->first + k;)
				{
					cnt += nit2->second;
					long long ly = nit2->first - k + 1;
					if (nit1 != now.begin()) ly = max(ly, prev(nit1)->first + 1ll);
					long long ry = nit1->first;

					++nit2;
					if (nit2 != now.end()) ry = min(ry, nit2->first - (long long)k);
					if (ry < ly) continue;

					ans[cnt] += (rx - lx + 1) * (ry - ly + 1);
				}

				--nit2;
				cnt -= nit2->second;
			}
		}

		--r;
	}

	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	printf("\n");
}