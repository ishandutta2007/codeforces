#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> G[N];
int n, m, x, y, du[N], dp[N];

double s;

int main() {
	cin >> n >> s;
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		++ du[x], ++ du[y];
	}
	for(int i = 1; i <= n; ++ i) if(du[i] == 1) ++ dp[1];
	printf("%.12lf\n", 2 * s / dp[1]);
}