#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll E = (ll)1e9 + 7;
const int N = 200100;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (s >= a)
			s = max(s, b);
	}
	if (s >= m)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}