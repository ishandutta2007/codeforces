#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t N, K;
	cin >> N >> K;
	if (N == 1)
	{
		cout << -1;
		return 0;
	}
	vector<int64_t>ans;
	for (int64_t i = 2; i <= N and K > 0; i++)
	{
		if (N % i == 0)
		{
			N /= i;
			ans.push_back(i);
			K--;
			i = 1;
		}
	}
	ans[0] *= N;
	if (K == 0)
	{
		for (int64_t a : ans)
			cout << a << " ";
		return 0;
	}
	cout << -1;
	return 0;
}