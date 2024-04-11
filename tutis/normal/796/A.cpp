#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int A[N];
	int ans = INT_MAX;
	M--;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] != 0 and A[i] <= K)
		{
			ans = min(ans, 10 * abs(M - i));
		}
	}
	cout << ans;
	return 0;
}