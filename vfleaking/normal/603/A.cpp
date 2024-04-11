#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	static char s[MaxN + 1];

	cin >> n >> s;

	int tot = 0;
	static int cnt[4];
	for (int i = 0, j; i < n; i = j)
	{
		j = i;
		while (j < n && s[i] == s[j])
			j++;
		tot++;
		cnt[min(j - i, 3)]++;
	}
	if (cnt[3] >= 1)
		tot += 2;
	else if (cnt[2] >= 2)
		tot += 2;
	else if (cnt[2] >= 1)
		tot++;
	cout << tot << endl;

	return 0;
}