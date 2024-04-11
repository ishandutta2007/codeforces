#include "bits/stdc++.h"
using namespace std;

pair<int,int> dat[3005];
list<int> lsts[3001];

int main()
{
	int r, c, n, k;
	scanf("%d%d%d%d",&r,&c,&n,&k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
	}

	sort(dat, dat + n);

	int ptr = 0;
	long long ans = 0;

	for (int s = 1; s <= r; s++)
	{
		while (dat[ptr].first < s) ptr++;
		if (n - ptr < k) break;

		vector<list<int>::iterator> vt;

		for (int i = ptr; i < n; i++)
		{
			lsts[dat[i].second].push_front(dat[i].second);
			vt.push_back(lsts[dat[i].second].begin());
		}

		list<int> lst;
		for (int i = 1; i <= c; i++) lst.splice(lst.end(), lsts[i]);

		long long now = 0;
		int right = n - 1;

		int last = 0;
		for (auto itr1 = lst.begin(), itr2 = next(itr1, k - 1);
				itr2 != lst.end();
				++itr1, ++itr2)
		{
			now += (*itr1 - last) * (c - *itr2 + 1);
			last = *itr1;
		}

		for (int e = r; e >= s; e--)
		{
			while (lst.size() >= k)
			{
				if (dat[right].first > e)
				{
					auto itr1 = vt[right-ptr];
					int cnt = 0;
					while (itr1 != lst.begin() && cnt < k - 1)
						--itr1, ++cnt;
					auto itr2 = next(itr1, k - 1);
					int last2 = (itr1 == lst.begin() ? 0 : *prev(itr1));
					for (;;)
					{
						// itr1~itr2  itr1~next(itr2) 
						now -= (*itr1 - last2) * (c - *itr2 + 1);
						++itr2;
						if (itr2 == lst.end()) break;
						now += (*itr1 - last2) * (c - *itr2 + 1);
						if (itr1 == vt[right-ptr]) break;
						last2 = *itr1;
						itr1++;
					}
				}
				else break;

				lst.erase(vt[right-ptr]);
				right--;
			}

			if (lst.size() < k) break;
			ans += now;
		}
	}

	printf("%lld", ans);
}