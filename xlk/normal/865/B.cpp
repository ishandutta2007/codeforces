#include <bits/stdc++.h>
using namespace std;
int n, S;
long long ans, best, sum, cur, part;
vector<pair<int, int> >T;
int main() {
	scanf("%d%d", &n, &S);
	for (int i = 0; i < n; i++) {
		int s, a, b;
		scanf("%d%d%d", &s, &a, &b);
		ans += (long long)s * a;
		sum += s;
		T.push_back(make_pair(b - a, s));
	}
	if (sum % S) {
		T.push_back(make_pair(0, S - sum % S));
	}
	sort(T.begin(), T.end());
	reverse(T.begin(), T.end());
	for (int i = 0; i < T.size(); i++) {
		if (part + T[i].second >= S) {
			best = max(best, cur + (long long)T[i].first * (S - part));
			best = max(best, cur + (long long)T[i].first * ((part + T[i].second) / S * S - part));
		}
		cur += (long long)T[i].first * T[i].second;
		part = (part + T[i].second) % S;
	}
	printf("%lld\n", ans + best);
	return 0;
}