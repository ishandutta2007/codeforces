#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
int n, k, lowest = 1, cur, cnt, A[200006];
std::vector<int> N;

int main(){
	std::scanf("%d%d", &n, &k);
	FOR(i, k) std::scanf("%d", &A[i]);
	N.push_back(n+1);
	FOR(i, k){
		if(A[i] < N.back()) N.push_back(A[i]);
		else if(A[i] > N.back()) std::printf("-1"), std::exit(0);
		while(!N.empty() && N.back() == lowest) N.pop_back(), lowest++;
	}
	FOR(i, k) std::printf("%d ", A[i]);
	if(k == n) return 0;
	cur = N.back() - 1;
	while(cnt < n - k){
		std::printf("%d ", cur);
		while(cur <= lowest){
			lowest = N.back() + 1;
			N.pop_back();
			if(N.empty()) break;
			cur = N.back();
		}
		cur--; cnt++;
	}
	return 0;
}