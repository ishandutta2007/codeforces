#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> st;

int main()
{
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		char ch; int t;
		scanf(" %c%d", &ch, &t);
		if (ch == '+') {
			st[t]++; continue;
		}
		else if (ch == '-')
		{
			if (--st[t] == 0)st.erase(t);
			continue;
		}

		if (st.empty())
		{
			printf("%d\n", t);
			continue;
		}

		int num = 0;
		auto it1 = st.begin(), it2 = prev(st.end());
		for (int flag = 29; flag >= 0 && it1 != it2; flag--)
		{
			int bit = 1 << flag;
			if ((it1->first&bit) == (it2->first&bit)) continue;

			if ((it1->first&bit) == (t&bit))
			{
				it1 = st.lower_bound((it2->first >> flag) << flag);
			}
			else
			{
				it2 = prev(st.lower_bound((it2->first >> flag) << flag));
			}
		}

		printf("%d\n", max(it1->first ^ t, t));
	}
}