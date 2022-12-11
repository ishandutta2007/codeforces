#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == 0 && b == 0) printf("NO\n");
	else if (abs(a - b) <= 1) printf("YES\n");
	else printf("NO\n");
}