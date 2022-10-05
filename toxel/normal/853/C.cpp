#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;
typedef std::pair <int, int> pii;
inline int lowbit(int n){return n & (-n);}

int n, q;
int c[N], p[N];
std::pair <std::pair <pii, pii>, int> query[N];
ll ans[N];

void add(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] += value;
	}
}

int qquery(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[sit];
	}
	return ret;
}

ll calc(int n){
	return 1ll * n * (n - 1) >> 1;
}

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &p[i]);
	}
	for (int i = 0, l, d, r, u; i < q; ++ i){
		scanf("%d%d%d%d", &l, &d, &r, &u);
		query[i] = {{{l, r}, {d, u}}, i};
	}
	std::sort(query, query + q);
	for (int i = 0, j = 0; i <= n; ++ i){
		if (i){
			add(p[i], 1);
		}
		while (j < q && query[j].first.first.first == i + 1){
			ans[query[j].second] += calc(qquery(query[j].first.second.first - 1)) + calc(qquery(n) - qquery(query[j].first.second.second));
			++ j;
		}
	}
	for (int i = 0; i < q; ++ i){
		std::swap(query[i].first.first.first, query[i].first.first.second);
	}
	std::sort(query, query + q, std::greater <std::pair <std::pair <pii, pii>, int>>());
	memset(c, 0, sizeof(c));
	for (int i = n + 1, j = 0; i; -- i){
		if (i <= n){
			add(p[i], 1);
		}
		while (j < q && query[j].first.first.first + 1 == i){
			ans[query[j].second] += calc(qquery(query[j].first.second.first - 1)) + calc(qquery(n) - qquery(query[j].first.second.second));
			++ j;
		}
	}
	for (int i = 0; i < q; ++ i){
		ans[i] += calc(n);
		ans[query[i].second] -= calc(n - query[i].first.first.first) + calc(query[i].first.first.second - 1) + calc(query[i].first.second.first - 1) + calc(n - query[i].first.second.second);
	}
	for (int i = 0; i < q; ++ i){
		printf("%I64d\n", ans[i]);
	}
	return 0;
}