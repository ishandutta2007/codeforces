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

int a[500500], n;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (1) {
		bool found = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				putchar('P');
				--a[i];
				found = 1;
			}
			if (i < n - 1) 
				putchar('R');
		}
		for (int i = n - 1; i > 0; i--)
			putchar('L');
		if (!found)
			break;
	}
}