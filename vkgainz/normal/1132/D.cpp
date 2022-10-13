#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const long long INF64 = 1e18;

int n, k;
long long a[N];
int b[N];
long long cur[N];

vector<int> qr[N];

bool check(long long x){
	forn(i, k) qr[i].clear();
	forn(i, n) cur[i] = a[i];
	forn(i, n){
		long long t = cur[i] / b[i] + 1;
		cur[i] %= b[i];
		if (t < k) qr[t].push_back(i);
	}
	
	int lst = 0;
	forn(t, k){
		while (lst < k && qr[lst].empty())
			++lst;
		if (lst <= t)
			return false;
		if (lst == k)
			return true;
		int i = qr[lst].back();
		if (cur[i] + x < b[i]){
			cur[i] += x;
			continue;
		}
		qr[lst].pop_back();
		long long nt = (cur[i] + x) / b[i];
		cur[i] = (cur[i] + x) % b[i];
		if (lst + nt < k)
			qr[lst + nt].push_back(i);
	}
	
	return true;
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%lld", &a[i]);
	forn(i, n) scanf("%d", &b[i]);
	long long l = 0, r = INF64;
	while (l < r - 1){
		long long m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	if (!check(r))
		puts("-1");
	else
		printf("%lld\n", check(l) ? l : r);
	return 0;
}