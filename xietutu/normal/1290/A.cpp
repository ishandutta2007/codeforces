#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5005;

int a[MaxN], b[MaxN];
int q[MaxN], qid[MaxN], ql, qr;

int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		k = min(k, m - 1);
		for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		int gap = n - k - (m - 1 - k) - 1;
		for (int i = 1; i + gap <= n; ++ i) {
			a[i] = max(a[i], a[i + gap]);
		}
		
		int lim = (m - k - 1) + 1;
		ql = 1; qr = 0;
		for (int i = 1; i <= n; ++ i) {
			while (qr >= ql && a[i] < q[qr]) -- qr;
			++ qr;
			q[qr] = a[i];
			qid[qr] = i;
			while (qid[ql] < i - lim + 1) ++ ql;
			b[i] = q[ql];
		}
	
		int len = n - k;
		int Ans = -1;
		for (int i = 1; i + len - 1 <= n; ++ i) {
			Ans = max(Ans, b[i + lim - 1]);
		}
		printf("%d\n", Ans);
	}
	return 0;
}