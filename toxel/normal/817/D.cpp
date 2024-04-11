#include<bits/stdc++.h>
#define ll long long

const int N = 1000010;

int n;
int a[N], leftmin[N], rightmin[N], leftmax[N], rightmax[N];
std::stack <int> stack;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	a[0] = a[n + 1] = INT_MAX;
	for (int i = 0; i <= n + 1; ++ i){
		while (!stack.empty() && a[stack.top()] < a[i]){
			rightmax[stack.top()] = i;
			stack.pop();
		}
		if (!stack.empty()) leftmax[i] = stack.top();
		stack.push(i);
	}
	while (!stack.empty()){
		stack.pop();
	}
	a[0] = a[n + 1] = INT_MIN;
	for (int i = 0; i <= n + 1; ++ i){
		while (!stack.empty() && a[stack.top()] > a[i]){
			rightmin[stack.top()] = i;
			stack.pop();
		}
		if (!stack.empty()) leftmin[i] = stack.top();
		stack.push(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++ i){
		ans += 1ll * a[i] * (1ll * (rightmax[i] - i) * (i - leftmax[i]) - 1ll * (rightmin[i] - i) * (i - leftmin[i]));
	}
	return printf("%I64d\n", ans), 0;
}