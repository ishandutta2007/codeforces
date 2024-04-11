#include <bits/stdc++.h>

using namespace std;

int N, Cnt[7];
int main() {
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0, x; j<7; j++) scanf("%1d", &x), Cnt[j] += x;
	int ans = 0;
	for(int j=0; j<7; j++) ans = max(ans, Cnt[j]);
	printf("%d\n", ans);
	return 0;
}