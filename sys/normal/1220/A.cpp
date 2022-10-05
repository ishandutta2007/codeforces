#include <bits/stdc++.h>
using namespace std;
int cnt, n;
string str;
int main()
{
	scanf("%d", &n);
	cin >> str;
	for (int i = 0; i < n; i++)
		if (str[i] == 'n') cnt++;
	for (int i = 1; i <= cnt; i++)
		printf("1 ");
	for (int i = 1; i <= (n - 3 * cnt) / 4; i++)
		printf("0 ");
	return 0;
}