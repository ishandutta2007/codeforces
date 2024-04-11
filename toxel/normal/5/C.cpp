#include<bits/stdc++.h>

const int N = 1000010;

char s[N];
int pre[N], right[N], dp[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 1; i <= n; ++ i){
		pre[i] = pre[i - 1] + (s[i - 1] == '(' ? 1 : -1);
	}
	pre[n + 1] = INT_MIN;
	std::stack <int> stack;
	for (int i = 0; i <= n + 1; ++ i){
		while (!stack.empty() && pre[stack.top()] >= pre[i]){
			right[stack.top()] = i;
			stack.pop();
		}
		stack.push(i);
	}
	int max = 0, cnt = 0;
	for (int i = n - 1; i >= 0; -- i){
		if (pre[right[i]] == pre[i]){
			dp[i] = dp[right[i]] + right[i] - i;
		}
		if (dp[i] > max){
			max = dp[i];
			cnt = 1;
		}
		else if (dp[i] == max){
			++ cnt;
		}
	}
	if (!max){
		cnt = 1;
	}
	printf("%d %d\n", max, cnt);
	return 0;
}