#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e5 + 100;
int n, m;
int a[N];
bool u[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);
	u[1] = true;
	for (int i = 1; i < n; i++)
		if (u[i])
			u[i + a[i]] = true;
	if (u[m])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}