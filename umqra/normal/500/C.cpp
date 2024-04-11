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

const int N = (int)1e3 + 10;
int a[N];
int w[N];
int used[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);

	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		memset(used, 0, sizeof(used));
		for (int s = i - 1; s >= 0; s--)
		{
			if (a[s] == a[i])
				break;
			if (!used[a[s]])
			{
				sum += w[a[s]];
			}
			used[a[s]] = 1;
		}
	}
	cout << sum;

	return 0;
}