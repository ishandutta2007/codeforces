#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int A[N], n;

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%d", A + i);
	vector<tuple<int, int, int>> ans;
	for(int i = 0;i < n;i++){
		int ind = i;
		for(int j = i;j < n;j++){
			if(A[j] < A[ind]) ind = j;
		}
		if(i == ind) continue;
		rotate(A + i, A + ind, A + n);
		ans.push_back({i + 1, n, ind - i});
	}
	printf("%d\n", ans.size());
	for(auto x : ans){
		printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}