#include <bits/stdc++.h>
using namespace std;

const char ch[] = {" codeforces"};
int cnt[14];
long long k, now = 1;
int main()
{
	scanf("%lld", &k);
	for (int i = 1; i <= 10; i++) cnt[i] = 1;
	int pnt = 1;
	while (now < k)
	{
		now /= cnt[pnt];
		cnt[pnt]++;
		now *= cnt[pnt];
		pnt = pnt + 1;
		if (pnt == 11) pnt = 1;
	}
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= cnt[i]; j++)
			putchar(ch[i]);
	return 0;
}