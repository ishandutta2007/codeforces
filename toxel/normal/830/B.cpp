#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;
inline int lowbit(int n){return n & (-n);}

int a[N], c[N];
std::vector <int> vec[N];
int n;

void add(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] += value;
	}
}

int query(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[sit];
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		vec[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++ i){
		add(i, 1);
	}
	ll ans = 0, pre = 1;
	for (int i = 1; i < N; ++ i){
		if (!vec[i].size()){
			continue;
		}
		int sit = std::lower_bound(vec[i].begin(), vec[i].end(), pre) - vec[i].begin() - 1;
		if (sit == -1){
			sit = vec[i].size() - 1;
		}
		if (pre <= vec[i][sit]){
			ans += query(vec[i][sit]) - query(pre - 1);
		}
		else{
			ans += query(N - 1) - (query(pre - 1) - query(vec[i][sit]));
		}
		for (auto u : vec[i]){
			add(u, -1);
		}
		pre = vec[i][sit];
	}
	return printf("%I64d\n", ans), 0;
}