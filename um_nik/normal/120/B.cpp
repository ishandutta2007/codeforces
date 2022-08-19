#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, k;
const int N = 1010;
int a[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k--;
	while(a[k] == 0)
		k = (k + 1) % n;
	printf("%d\n", k + 1);

	return 0;
}