#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1e6 + 5;

using namespace std;

int P[N] ,n , m , x , y;
long long ans;

void build(int &n) {
	int high = 0;
	for(high = 21;high >= 0;-- high) if((1 << high) & n) break;
	int mask = (1 << high);
	int y = mask - 1;
	while(mask <= n) {
		P[mask] = y; P[y] = mask;
		-- y; ++ mask;
	}
	n = y;
}

int main(void) {
	scanf("%d" , &n);
	printf("%lld\n" , n *  1ll * (n + 1));
	int tot = n;
	while(n) {
		build(n); n = max(n , 0);
	}
	for(int i = 0;i <= tot;++ i) printf("%d " , P[i]); 
}