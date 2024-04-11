#include <stdio.h>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = 300005;

vector <int> E;
int n, v[N], len[N];
long long dp[N], tot;
bool in[N];

void Mod (int u) {
	int w = min (v[u], v[u + 1]);
	if (w > 0) v[u] -= w, v[u + 1] -= w, E.push_back (u), tot += w;
}

int main () {
	scanf ("%d", &n); n += 1; 
	for (int i = 1; i < n; i ++) scanf ("%d", v + i);
	dp[1] = v[1]; len[1] = 1;
	dp[2] = v[2]; len[2] = 1;
	for (int i = 3; i <= n; i ++) {
		long long w1 = dp[i - 2] + v[i], w2 = dp[i - 3] + max (v[i - 1], v[i]);
		if (w1 < w2) dp[i] = w1, len[i] = 1; else dp[i] = w2, len[i] = 2;
	}
	for (int u = n; u > 0; u -= len[u] + 1) for (int v = 0; v < len[u]; v ++) in[u - v] = true;
	for (int u = 1; u < n; u ++) if (in[u] && in[u + 1]) Mod (u);
	for (int u = 1; u < n; u ++) Mod (u);
	assert (tot == dp[n]);
	printf ("%u\n", E.size());
	for (int u : E) printf ("%d\n", u);
	return 0;
}