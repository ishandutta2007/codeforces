#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
char s[1010];

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(s[i] == '8')
			ans++;
	ans = min(ans, n / 11);
	printf("%d\n", ans);
	return 0;
}