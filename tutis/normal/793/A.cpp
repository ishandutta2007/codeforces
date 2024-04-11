#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


	long long N, K;
	cin >> N >> K;
	long long A[N];
	for (long long i = 0; i < N; i++)
		cin >> A[i];
	long long x = *min_element(A, A + N);
	long long ans = 0;
	for (long long i = 0; i < N; i++)
	{
		long long sk = A[i] - x;
		if (sk % K != 0)
		{
			cout << -1;
			return 0;
		}
		ans += sk / K;
	}
	cout << ans << "\n";


	return 0;
}