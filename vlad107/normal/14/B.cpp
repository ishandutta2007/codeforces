#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define MAXN 1111
              
int main()
{
	int n, m = 0, x0, res = MAXN, x[MAXN], y[MAXN];
	scanf("%d%d", &n, &x0);	
	for (int i = 0; i < n; i++)
		{
		 	scanf("%d%d", &x[i], &y[i]);
			if (x[i] > y[i]) std::swap(x[i], y[i]);
			m = std::max(m, y[i]);
		}
	for (int i = 0; i <= m; i++)
		{
			bool ok = true;
			for (int j = 0; j < n && ok; j++)
				if (i < x[j] || i > y[j])
					ok = false;	
			if (ok) res = std::min(res, std::abs(i-x0));
		}
	if (res == MAXN)
		puts("-1");
	else printf("%d\n", res);
}