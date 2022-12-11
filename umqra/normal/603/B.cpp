#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
int used[N];

int mult(int a, int b, int m)
{
	return ((long long)a * b) % m;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 0)
	{
		int res = 1;
		for (int i = 1; i < n; i++)
			res = mult(res, n, mod);
		printf("%d\n", res);
		return 0;
	}
	int minPow = 1;
	int t = k;
	while (t != 1)
	{
		minPow++;
		t = mult(t, k, n);
	}
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (!used[i])
		{
			int len = 0;
			for (int x = i; !used[x]; x = mult(x, k, n))
			{
				used[x] = 1;
				len++;
			}
			if (len % minPow == 0)
				ans = mult(ans, n, mod);
		}		 	
	}
	if (k == 1)
		ans = mult(ans, n, mod);
	printf("%d\n", ans);
	

	return 0;
}