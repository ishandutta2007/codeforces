/**
5 5 10 5 4
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int sk[1001];
	sk[0] = v0;
	for (int i = 1; i <= 1000; i++)
	{
		sk[i] = min(v0 + a * i, v1) - l;
	}
	for (int i = 1; i <= 1000; i++)
	{
		sk[i] = sk[i] + sk[i - 1];
	}
	for (int i = 0; i <= 1000; i++)
	{
		if (sk[i] >= c)
		{
			cout << i + 1;
			return 0;
		}
	}
}