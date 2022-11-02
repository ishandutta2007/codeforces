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

int main()
{
	char a[5][5];
	bool ok = true;
	for (int i = 0; i < 3; i++)
		gets(a[i]);
	for (int i = 0; i < 3 && ok; i++)
		for (int j = 0; j < 3 && ok; j++)
			if (a[i][j] != a[3-i-1][3-j-1])
				ok = false;
	ok ? puts("YES") : puts("NO");
	return 0;
}