#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long ss, xx;
	scanf("%lld%lld",&ss,&xx);

	bitset<64> s(ss), x(xx);

	long long ans = 1;
	vector<int> poll;

	for (int i = 0; i < 64; i++)
	{
		if (s[i] == 1 && x[i] == 1)
		{
			// must be (1,0) or (0,1)
			ans *= 2;
			poll.push_back(i);
		}
	}

	poll.push_back(64);
	int last = 0;
	for (int p : poll)
	{
		int needolim = 0;
		for (int i = p - 1; i >= last; i--)
		{
			if (s[i] == 1 && x[i] == 0)
			{
				needolim = 1;
			}
			else if (s[i] == 0 && x[i] == 1)
			{
				if (needolim == 0) { printf("0"); return 0; }
				ans *= 2;
				needolim = 1;
			}
			else
			{
				needolim = 0;
			}
		}

		if (needolim) { printf("0"); return 0; }

		last = p + 1;
	}

	if (ss == xx) ans -= 2;

	printf("%lld", ans);
}