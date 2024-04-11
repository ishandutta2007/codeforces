#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 1010;
int n;
char s[N][10];
int ans = 6;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 6; k++)
				cnt += (int)(s[i][k] != s[j][k]);
			ans = min(ans, (cnt - 1) / 2);
		}
	printf("%d\n", ans);

	return 0;
}