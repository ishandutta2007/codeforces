#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200, B = 450;
int n, m, ans[MAXN], s[MAXN], las[MAXN];
int a[MAXN], b[MAXN], cur[B + 5][B + 5];

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = min(m, read()), b[i] = min(m, read());
	for (i = 1; i <= m; i++) {
		int op = read(), k = read();
		if (op == 1) {
			if (a[k] + b[k] <= B) {
				for (j = a[k]; j < a[k] + b[k]; j++) ++cur[a[k] + b[k]][(j + i) % (a[k] + b[k])];
			}
			las[k] = i;
		}
		else {
			if (a[k] + b[k] <= B) {
				for (j = a[k]; j < a[k] + b[k]; j++) --cur[a[k] + b[k]][(j + las[k]) % (a[k] + b[k])];
			}
			else {
				for (j = las[k] + a[k]; j < i; j += a[k] + b[k]) ++s[j], --s[min(i, j + b[k])];
			}
			las[k] = 0;
		}
		for (j = 2; j <= B; j++) ans[i] += cur[j][i % j];
	}
	for (i = 1; i <= n; i++) if (a[i] + b[i] > B && las[i]) {
		for (j = las[i] + a[i]; j <= m; j += a[i] + b[i]) ++s[j], --s[min(m + 1, j + b[i])];
	}
	for (i = 1; i <= m; i++) s[i] += s[i - 1], printf("%d\n", ans[i] + s[i]);
	return 0;
}