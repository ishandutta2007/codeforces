#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int tens[713];
int sums[713];
int totsum[13][713]; // total for digit i if j slots unassigned
int totbefore[13][713]; // total including possible digits before i with j slots

void precalc() {
	tens[0] = 1;
	for (int i=1;i<713;i++) {
		tens[i] = mult(10, tens[i-1]);
		sums[i] = add(sums[i-1], tens[i-1]);
	}

	for (int i=0;i<=9;i++) {
		totbefore[i][0] = 1;
		for (int j=1;j<713;j++) {
			totbefore[i][j] = add(mult(9-i, mult(10, totbefore[i][j-1])), mult(i+1, totbefore[i][j-1])); // >i, <i
		}
	}
	for (int i=0;i<=9;i++) {
		for (int j=1;j<713;j++) {
			totsum[i][j] = add(mult(i, totbefore[i][j-1]), mult(10, totsum[i][j-1])); // i
			totsum[i][j] = add(totsum[i][j], mult(9-i, mult(10, totsum[i][j-1]))); // >i
			totsum[i][j] = add(totsum[i][j], mult(i, totsum[i][j-1])); // <i
		}
	}
}

int n;
char buff[713];
int x[713];
int has[10];

int main() {
	precalc();
	scanf("%s", buff);
	n = strlen(buff);
	for (int i=1;i<=n;i++) x[i] = buff[i-1]-'0';
	int ans = 0;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<x[i];j++) {
			has[j]+=1;
			int prev = 0;
			for (int k=9;k>=0;k--) {
				ans = add(ans, mult(tens[prev], mult(mult(k, sums[has[k]]), totbefore[k][n-i])));
				prev+=has[k];
				ans = add(ans, mult(tens[prev], totsum[k][n-i]));
			}
			has[j]-=1;
		}
		has[x[i]]+=1;
	}
	int prev = 0;
	for (int i=9;i>=0;i--) {
		ans = add(ans, mult(tens[prev], mult(i, sums[has[i]])));
		prev+=has[i];
	}
	printf("%d\n", ans);
}