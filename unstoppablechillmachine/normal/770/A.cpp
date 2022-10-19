#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = (sizeof(ll) == 8) ? 1e18 : 1e9;

int main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
#ifdef _F1A4X_
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
#endif
	ll n, k;
	cin >> n >> k;
	char c = k + 'a', r = 'a';
	for (int i = 0; i < n; i++)
	{
		cout << r;
		r++;
		if (r == c)
		{
			r = 'a';
		}
	}
	cout << endl;
	return 0;
}