#include <bits/stdc++.h>

int n,m;
int cnt[1010];
char str[1010];
char op[10];

int main() {
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	double prob = 0.5;
	for (int i = 1; i <= m; i++) {
		scanf("%s", str + 1);
		int b = 100000000;
		for (int j = 1; j <= n; j++) b = std::min(b,cnt[j]);
		long double error[2] ={0};
		for (int j = 1; j <= n; j++) error[ str[j] -'0' ] += pow(prob,cnt[j] - b);
		double now = 1. * std::rand() / RAND_MAX;
		if (now > error[0] / (error[0] + error[1])) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
		fflush(stdout);
		scanf("%s",op);
		for (int j = 1; j <= n; j++) 
			if (op[0] != str[j]) cnt[j]++;
	}
	return 0;
}