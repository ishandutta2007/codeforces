#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	printf("1996\n");
	for (int i = 2; i < 1000; i++)
		printf("%d 1 %d 2\n", i, i);
	for (int i = 999; i > 1; i--)
		printf("%d 1 %d 2\n", i, i);

	return 0;
}