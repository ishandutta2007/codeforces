#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt, las;
string str;
int main()
{
	scanf("%d", &n);
	cin >> str;
	las = -1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0 && las == -1) las = i;
		if (cnt == 0 && las != -1) ans += i - las + 1, las = -1;
	}
	if (cnt)
		puts("-1");
	else printf("%d", ans);
	return 0;
}