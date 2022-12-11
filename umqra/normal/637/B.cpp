#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, string> pis;
#define mp make_pair

const int N = 200200;
map<string, int> a;
pis b[N];
int m, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		a[s] = i;
	}
	for (auto it : a)
		b[m++] = mp(it.second, it.first);
	sort(b, b + m);
	for (int i = m - 1; i >= 0; i--)
		cout << b[i].second << '\n';

	return 0;
}