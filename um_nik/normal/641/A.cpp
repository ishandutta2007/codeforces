#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N];
int d[N];
bool used[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	int x = 0;
	while(x >= 0 && x < n && !used[x])
	{
		used[x] = 1;
		if (s[x] == '<')
			x -= d[x];
		else
			x += d[x];
	}
	if (x >= 0 && x < n)
		printf("INFINITE\n");
	else
		printf("FINITE\n");

	return 0;
}