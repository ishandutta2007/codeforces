#include<bits/stdc++.h>

const int N = 200010;
const int M = 30;
typedef long long ll;

int n;
int a[N], left[N], right[N], leftbit[N][M], rightbit[N][M];
std::stack <int> stack;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	a[0] = a[n + 1] = INT_MAX;
	for (int i = 0; i <= n + 1; ++ i){
		while (!stack.empty() && a[i] > a[stack.top()]){
			right[stack.top()] = i;
			stack.pop();
		}
		if (!stack.empty()){
			left[i] = stack.top();
		}
		stack.push(i);
	}
	for (int i = 0; i < M; ++ i){
		int now = 0;
		for (int j = 1; j <= n; ++ j){
			leftbit[j][i] = now;
			if (a[j] >> i & 1){
				now = j;
			}
		}
		now = n + 1;
		for (int j = n; j >= 1; -- j){
			rightbit[j][i] = now;
			if (a[j] >> i & 1){
				now = j;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++ i){
		ll sum = 1ll * (i - left[i]) * (right[i] - i);
		int max = left[i];
		for (int j = 0; j < M; ++ j){
			if (!(a[i] >> j & 1)){
				max = std::max(max, leftbit[i][j]);
			}
		}
		int min = right[i];
		for (int j = 0; j < M; ++ j){
			if (!(a[i] >> j & 1)){
				min = std::min(min, rightbit[i][j]);
			}
		}
		sum -= 1ll * (i - max) * (min - i);
		ans += sum;
	}
	return printf("%I64d\n", ans), 0;
}