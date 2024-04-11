#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if ((i / 2) % 2 == 1)
			cout << 'a';
		else
			cout << 'b';
	}
	return 0;
}