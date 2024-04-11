#include "bits/stdc++.h"
using namespace std;

int main()
{
	int now = 'a';
	int ans = 0;
	for (char ch; scanf(" %c",&ch) == 1; now = ch)
	{
		ans = ans + min(abs(now - ch), 26 - abs(now - ch));
	}
	printf("%d", ans);
}