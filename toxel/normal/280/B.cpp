#include<bits/stdc++.h>

const int N = 100010;

int a[N];
std::stack <int> stack;

int main(){
	int n;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		while (!stack.empty() && stack.top() < a[i]){
			stack.pop();
		}
		if (!stack.empty()){
			max = std::max(max, a[i] ^ stack.top());
		}
		stack.push(a[i]);
	}
	while (!stack.empty()){
		stack.pop();
	}
	for (int i = n - 1; i >= 0; -- i){
		while (!stack.empty() && stack.top() < a[i]){
			stack.pop();
		}
		if (!stack.empty()){
			max = std::max(max, a[i] ^ stack.top());
		}
		stack.push(a[i]);
	}
	return printf("%d\n", max), 0;
}