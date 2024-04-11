#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
bool f1(pair<long, long> a, pair<long, long> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
bool f2(pair<long, long> a, pair<long, long> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long n;
	cin >> n;
	long minr = INT_MAX;
	long maxl = 0;
	long minl = INT_MAX;
	long maxr = 0;
	for (long i = 0; i < n; i++) {
		long l, r;
		cin >> l >> r;
		maxl = max(maxl, l);
		minr = min(minr, r);
		maxr = max(maxr, r);
		minl = min(minl, l);
	}
	long m;
	cin >> m;
	long maxL = 0;
	long minR = INT_MAX;
	long maxR = 0;
	long minL = INT_MAX;
	for (long i = 0; i < m; i++) {
		long l, r;
		cin >> l >> r;
		maxL = max(l, maxL);
		minR = min(r, minR);
		maxR = max(r, maxR);
		minL = min(l, minL);
	}
	long ans = 0;
	ans = max(ans, maxl - minR);
	ans = max(ans, maxL - minr);
	cout << ans;
	return 0;
}