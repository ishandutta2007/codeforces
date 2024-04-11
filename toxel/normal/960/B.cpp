#include<bits/stdc++.h>

const int N = 1010;
typedef long long ll;

int a[N], b[N];

int main(){
	int n, k1, k2;
	scanf("%d%d%d", &n, &k1, &k2);
	k1 += k2;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::priority_queue <int> queue;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		queue.push(std::abs(a[i] - b[i]));
	}
	while (k1 > 0){
		int x = queue.top();
		queue.pop();
		queue.push(x > 0 ? x - 1 : 1);
		-- k1;
	}
	ll ans = 0;
	while (!queue.empty()){
		int x = queue.top();
		ans += 1ll * x * x;
		queue.pop();
	}
	printf("%I64d\n", ans);
	return 0;
}