/***
9 2 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, A, B;
	cin >> N >> A >> B;
	for (int k = 0; k <= N; k++)
	{
		int liko = N - k * A;
		if (liko < 0)
			break;
		if (liko % B != 0)
			continue;
		int l = liko / B;
		int jau = 0;
		while (k--)
		{
			vector<int>x;
			for (int i = jau + 1; i <= jau + A; i++)
			{
				x.push_back(i);
			}
			for (int i = 0; i < x.size(); i++)
			{
				cout << (x[(i + 1) % x.size()]) << " ";
			}
			jau += A;
		}
		while (l--)
		{
			vector<int>x;
			for (int i = jau + 1; i <= jau + B; i++)
			{
				x.push_back(i);
			}
			for (int i = 0; i < x.size(); i++)
			{
				cout << (x[(i + 1) % x.size()]) << " ";
			}
			jau += B;
		}
		return 0;
	}
	cout << -1;
	return 0;
}