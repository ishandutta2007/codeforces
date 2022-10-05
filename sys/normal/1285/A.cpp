#include <bits/stdc++.h>
using namespace std;

int n, cnt1, cnt2;
string str;
int main()
{
	scanf("%d", &n);
	cin >> str;
	for (int i = 0; i < n; i++)
		if (str[i] == 'L') cnt1++;
		else cnt2++;
	printf("%d", cnt1 + cnt2 + 1);
	return 0;
}