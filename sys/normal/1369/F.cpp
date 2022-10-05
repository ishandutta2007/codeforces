#include <bits/stdc++.h>
using namespace std;

bool W, L = true;
bool win(long long s, long long e)
{
	if (e & 1) return !(s & 1);
	if (s > e / 2) return s & 1;
	if (s > e / 4) return true;
	return win(s, e / 4);
}
bool lose(long long s, long long e)
{
	if (s > e / 2) return true;
	return win(s, e / 2);
}
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long s, e;
		scanf("%lld%lld", &s, &e);
		bool s1 = win(s, e), s2 = lose(s, e), tmpL = L, tmpW = W;
		W = (tmpL && s1) | (tmpW && !s1);
		L = (tmpL && s2) | (tmpW && !s2);
	}
	printf("%d %d", (int) W, (int) L);
	return 0;
}