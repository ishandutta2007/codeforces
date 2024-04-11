#include <cstdio>
int dv_l[5000002];
int ndv[5000002];


void pre_process() {
	int i, j;
	for(i = 2; i <= 5000000; i++) dv_l[i] = 1;
	for(i = 2; i <= 5000000; i++) {
		if(dv_l[i] != 1) continue;
		for(j = i + i; j <= 5000000; j += i) dv_l[j] = i;
	}
	ndv[1] = 0;
	for(i = 2; i <= 5000000; i++)
		if(dv_l[i] == 1) ndv[i] = 1;
		else ndv[i] = 1 + ndv[i / dv_l[i]];
	//for(i = 2; i < 26; i++) printf("%d - dv_l%d - ndv%d\n", i, dv_l[i], ndv[i]);	
	for(i = 3; i <= 5000000; i++)
		ndv[i] += ndv[i-1];
}


int main() {
	pre_process();
	int t, a, b;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);	
		if(a == b) puts("0");
		else printf("%d\n", ndv[a] - ndv[b]);
	}
}