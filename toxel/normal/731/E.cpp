#include<bits/stdc++.h>

const int N = 200010;

int pre[N];
std::priority_queue <int> pq;
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		pre[i] = pre[i - 1] + x;
	}
	for (int i = n; i > 1; -- i){
		int x = pq.size() ? pq.top() : 0;
		pq.push(pre[i] - x);
	}
	return printf("%d\n", pq.top()), 0;
}