#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e6;
int sum[N];
int t[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;
	for (int i = 0; i < (int)str.length() - 1; i++)
		if (str[i] == str[i + 1])
			t[i] = 1;

	sum[0] = t[0];
	for (int i = 1; i < (int)str.length(); i++)
		sum[i] = sum[i - 1] + t[i];

	int m;
	scanf("%d",  &m);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r - 2] - (l == 1 ? 0 : sum[l - 2]));
	}

	return 0;
}