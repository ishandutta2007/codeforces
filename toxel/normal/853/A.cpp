#include<bits/stdc++.h>

const int N = 300010;
typedef long long ll;
typedef std::pair <int, int> pii;

int c[N], ret[N];
int n, k;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &c[i]);
	}
	std::priority_queue <pii> pq;
	std::vector <int> vec;
	ll ans = 0;
	for (int i = k + 1, j = 1; i <= k + n; ++ i){
		while (j <= i && j <= n){
			pq.push({c[j], j});
			++ j;
		}
		pii p = pq.top();
		pq.pop();
		ans += 1ll * (i - p.second) * p.first;
		ret[p.second] = i;
	}
	printf("%I64d\n", ans);
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", ret[i], " \n"[i == n]);
	}
	return 0;
}