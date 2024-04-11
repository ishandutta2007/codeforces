#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> pii;

const int N = 200000;

std::vector<int>ans; pii w[N + 5];
void solve() {
	int n; ll W; scanf("%d%lld", &n, &W);
	for(int i=1;i<=n;i++) scanf("%d", &w[i].first), w[i].second = i;
	std::sort(w + 1, w + n + 1);
	
	while( n && w[n].first > W ) n--;
	if( n == 0 ) {
		puts("-1");
	} else {
		ans.clear(), ans.push_back(w[n].second); ll sum = w[n].first;
		for(int i=1;i<=n;i++) {
			if( sum >= (W + 1) / 2 ) break;
			if( i == n ) {
				puts("-1");
				return ;
			}
			sum += w[i].first, ans.push_back(w[i].second);
		}
		printf("%d\n", (int)(ans.size()));
		std::sort(ans.begin(), ans.end());
		for(auto x : ans) printf("%d ", x); puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}