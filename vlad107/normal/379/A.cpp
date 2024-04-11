#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define INF 1000000000

using namespace std;

int ans, a, b, c, x, y;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ans = 0;
	scanf("%d%d", &a, &b);
	c = 0;
	for (int i = 0; i < 500500; i++) {
		ans += a;
		x = (a + c) / b;
		y = (a + c) % b;
		a = x;
		c = y;
	}
	printf("%d\n", ans);
}

//(x, y) -> (x + 1, y + 1)