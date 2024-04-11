#include "bits/stdc++.h"
using namespace std;

int f(char ch)
{
	if (ch == 'f') return 1;
	if (ch == 'e') return 2;
	if (ch == 'd') return 3;
	if (ch == 'a') return 4;
	if (ch == 'b') return 5;
	if (ch == 'c') return 6;
	return 0;
}

int main()
{
	long long n; char ch;
	scanf("%lld%c", &n, &ch);
	printf("%lld", (n - 1) / 4 * 16 + !(n & 1) * 7 + f(ch));
}