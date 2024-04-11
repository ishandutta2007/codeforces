#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 5000;

int n;
char s[MaxN + 1];
int f[MaxN + 1];

int calc(int l, int r)
{
	int sg = 0;
	int last = 0;
	for (int i = l + 1; i <= r - 1; i++)
	{
		if (s[i - 1] == s[i + 1])
			last++;
		else
			sg ^= f[last], last = 0;
	}
	sg ^= f[last], last = 0;
	return sg;
}

int main()
{
	cin >> s;
	n = strlen(s);

	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		const int MaxB = 20;
		static bool book[MaxB];
		fill(book, book + MaxB, false);
		for (int k = 1; k <= i; k++)
			book[f[max(k - 2, 0)] ^ f[max(i - k - 1, 0)]] = true;
		f[i] = 0;
		while (book[f[i]])
			f[i]++;
	}

	if (calc(0, n - 1))
	{
		cout << "First" << endl;
		int k;
		for (k = 1; k < n - 1; k++)
			if (s[k - 1] == s[k + 1] && (calc(0, k - 1) ^ calc(k + 1, n - 1)) == 0)
				break;
		cout << k + 1 << endl;
	}
	else
		cout << "Second" << endl;

	return 0;
}