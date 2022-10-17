#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
char a[101010], b[101010];
int cnt[2][2];
int n;
int main()
{
	scanf("%d", &n);
	scanf("%s%s", a + 1, b + 1);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[a[i] - '0'][b[i] - '0']++;
	long long ans = (long long)cnt[0][0] * cnt[1][0] + (long long)cnt[0][0] * cnt[1][1] + (long long)cnt[0][1] * cnt[1][0];
	cout << ans;
	return 0;
}