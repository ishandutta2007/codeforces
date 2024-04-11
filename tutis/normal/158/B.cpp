/*input
8
2 3 4 4 2 1 3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int K[5];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		K[A[i]]++;
	}
	int ans = 0;
	while (K[4] > 0)
	{
		K[4]--;
		ans++;
	}
	while (K[3] > 0)
	{
		K[3]--;
		K[1] -= min(1, K[1]);
		ans++;
	}
	while (K[2] > 1)
	{
		K[2] -= min(2, K[2]);
		ans++;
	}
	while (K[2] > 0)
	{
		K[2]--;
		K[1] -= min(2, K[1]);
		ans++;
	}
	while (K[1] > 0)
	{
		K[1] -= min(4, K[1]);
		ans++;
	}
	cout << ans << "\n";
}