#include <iostream>
#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAX = 200009;
int n, w;
int pot[MAX];
typedef unsigned long long ull;

void end() {
	printf("%d\n", w);
	exit(0);
}

int main() {
	int i, j;
	scanf("%d %d", &n, &w);
	for(i = 0; i < 2 * n; i++)
		scanf("%d", &pot[i]);
	sort(pot, pot + 2 * n);
	int minG = pot[0];
	int minB = pot[n];
	// long double x = static_cast<long double>(w) / (3 * n);
	// x = min(x, static_cast<long double>(minG));
	// x = min(x, static_cast<long double>(minB) / 2);
	// cout << (3 * n * x) << endl;
	ull x = min(minG, minB / 2);
	x = 3ull * n * x;
	if(x > w) {
		end();
	} else {
		if((minB & 1) && ((minB + 1) / 2) <= minG) {
			x += n + (n / 2);
			if(x > w) end();
			if((n & 1) && (x + 1) > w) end();
			printf("%d", int(x));
			if(n & 1) puts(".5");
			else puts("");
		} else printf("%d\n", int(x));
	}
	return 0;
}