/*input
10 12
sin im gye gap eul byeong jeong mu gi gyeong
yu sul hae ja chuk in myo jin sa o mi sin
14
1
2
3
4
10
11
12
13
73
2016
2017
2018
2019
2020

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s[n], t[m];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];
	int q;
	cin >> q;
	while (q--)
	{
		int i;
		cin >> i;
		i--;
		cout << s[i % n] << t[i % m] << "\n";
	}
}