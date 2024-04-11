#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

void Danny() {
	puts("Daenerys");
	exit(0);
}

void Stannis() {
	puts("Stannis");
	exit(0);
}

int main() {
	int n, k, impar, par, x;
	scanf("%d %d", &n, &k); k = n - k;
	impar = par = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		((x % 2)? impar : par)++;
	}
	if(k == 0) ((impar % 2)? Stannis : Danny)();
	debug("par %d impar %d k %d\n", par, impar, k);
	if(impar <= k / 2) Danny();
	debug("AA\n");
	if(par > k / 2) ((k % 2)? Stannis : Danny)();
	debug("BB\n");
	if((impar - (k - par)) % 2) Stannis();
	Danny();
}