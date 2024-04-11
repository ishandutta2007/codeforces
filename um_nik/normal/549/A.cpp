#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

const int N = 60;
int n, m;
string s[N];
set<char> a;
set<char> b;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	a.insert('f');
	a.insert('a');
	a.insert('c');
	a.insert('e');

	int ans = 0;

	for (int x = 0; x < n - 1; x++)
		for (int y = 0; y < m - 1; y++)
		{
			b.clear();
			for (int i = x; i < x + 2; i++)
				for (int j = y; j < y + 2; j++)
					b.insert(s[i][j]);
			if (a == b)
				ans++;
		}
	printf("%d\n", ans);

	return 0;
}