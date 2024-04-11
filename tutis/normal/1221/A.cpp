/*input
6
4
1024 512 64 512
1
2048
3
64 512 2
2
4096 4
7
2048 2 2048 2048 2048 2048 2048
2
2048 4096

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		map<int, int>M;
		while (n--)
		{
			int a;
			cin >> a;
			M[a]++;
		}
		for (int i = 1; i < 2048; i++)
		{
			M[2 * i] += M[i] / 2;
		}
		if (M[2048] > 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


}