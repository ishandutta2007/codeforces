#include <bits/stdc++.h>
using namespace std;
char str[200005];
int main()
{
	int a, b, c;
	scanf("%d%d%d%s", &a, &b, &c, str);
	printf("%d", str[b - 1] != str[c - 1]);
}