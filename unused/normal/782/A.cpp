#include <bits/stdc++.h>
using namespace std;

set<int>st;

int main()
{
	int n;
	scanf("%d", &n);
	size_t ans = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int t; scanf("%d", &t);
		if (st.insert(t).second == false) st.erase(t);
		ans = max(ans, st.size());
	}
	printf("%zu\n", ans);
}