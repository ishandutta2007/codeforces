#include<bits/stdc++.h>

const int N = 1000010;
const int M = 200;
typedef long long ll;

char s[N], t[N];
int cnts[M], cntt[M];
int lens, lent;

bool check(int mid){
	ll ans = 0;
	for (int i = 0; i < M; ++ i){
		ans += std::max((ll) cnts[i], (ll) cntt[i] * mid);
	}
	return ans <= lens;
}

int main(){
	scanf("%s%s", s, t);
	lens = strlen(s), lent = strlen(t);
	for (int i = 0; i < lens; ++ i){
		if (s[i] != '?'){
			++ cnts[s[i]];
		}
	}
	for (int i = 0; i < lent; ++ i){
		++ cntt[t[i]];
	}
	int left = 0, right = N;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (check(mid)){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	std::stack <char> stack;
	for (int i = 0; i < M; ++ i){
		for (int j = cnts[i]; j < left * cntt[i]; ++ j){
			stack.push(i);
		}
	}
	for (int i = 0; i < lens; ++ i){
		if (s[i] == '?'){
			if (stack.empty()){
				s[i] = 'z';
			}
			else{
				s[i] = stack.top();
				stack.pop();
			}
		}
	}
	return printf("%s\n", s), 0;
}