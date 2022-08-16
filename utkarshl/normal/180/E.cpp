#include"stdio.h"
#include"cassert"
#define M 100000
#define N 200000
int count[M] = {0};
int next[N] = {-1};
int last[M] = {-1};
int first[M] = {-1};
int max(int a, int b) { return a<b ? b:a; }
int main() {
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	int best = 0;
	for(int i=0; i<n; i++){
		int c;
		scanf("%d", &c);
		c--;
		if(count[c]==0) last[c] = i, first[c]=i;
		else next[last[c]] = i, last[c] = i;
		count[c]++;
		while(last[c] - first[c] + 1 - count[c] > k) {
			count[c]--;
			assert(count[c]);
			first[c] = next[first[c]];
		}
		best=max(best, count[c]);
	}
	printf("%d", best);
}