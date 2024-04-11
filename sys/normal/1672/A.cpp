#include <bits/stdc++.h>
using namespace std;

int T;
string str;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag = false;
		int n;
		scanf("%d", &n);
		for (int i = 1, x; i <= n; i++)
			scanf("%d", &x), flag ^= (x & 1) ^ 1;
		puts(flag ? "errorgorn" : "maomao90");
	}
	return 0;
}