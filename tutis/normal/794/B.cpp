#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int64_t N, H;
	cin >> N >> H;
	for (int64_t a = 1; a < N; a++)
	{
		long double ats = H;
		ats *= sqrtl((long double)a / N);
		cout << fixed << setprecision(9) << ats << " ";
	}
}