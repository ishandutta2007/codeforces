#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int A, B;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	A = 0;
	B = (1 << 10) - 1;

	int n;
	scanf("%d", &n);
	while(n--) {
		char t;
		int x;
		scanf(" %c %d", &t, &x);
		if (t == '|') {
			A |= x;
			B |= x;
		} else if (t == '^') {
			A ^= x;
			B ^= x;
		} else {
			A &= x;
			B &= x;
		}
	}
	printf("3\n");
	int Z = (1 << 10) - 1;
	for (int i = 0; i < 10; i++) {
		if ((((A >> i) & 1) == 0) && (((B >> i) & 1) == 0))
			Z ^= 1 << i;
	}
	printf("& %d\n", Z);
	Z = 0;
	for (int i = 0; i < 10; i++) {
		if (((A >> i) & 1) && ((B >> i) & 1))
			Z ^= 1 << i;
	}
	printf("| %d\n", Z);
	Z = 0;
	for (int i = 0; i < 10; i++) {
		if (((A >> i) & 1) && (((B >> i) & 1) == 0))
			Z ^= 1 << i;
	}
	printf("^ %d\n", Z);

	return 0;
}