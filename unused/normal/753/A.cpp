#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);

	vector<int> ans;

	for (int i = 1; i <= n; i++)
	{
		ans.push_back(i);
		n -= i;
	}
	ans.back() += n;
	printf("%d\n", (int)ans.size());
	for (int t : ans) printf("%d ", t);
}