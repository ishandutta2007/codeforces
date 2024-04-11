#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;
int a[N];

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);

	int cell = 1;
	while (cell < t)
	{
		cell = cell + a[cell];
	}
	if (cell == t)
		puts("YES");
	else
		puts("NO");
	return 0;
}