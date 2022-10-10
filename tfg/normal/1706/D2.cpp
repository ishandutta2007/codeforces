#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t, n, k, a[N], ma;
vector<int> q[N];

int main(){
	scanf("%d", &t);
	while(t--){
		ma = 0;
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			int p = k;
			q[a[i] / p].push_back(i);
			ma = max(ma, a[i] / p);
		}
		int ans = N;
		for(int i = 0; i < N; i++){
			ans = min(ans, ma - i);
			for(int b : q[i]){
				if(a[b] == i){
					ma = 2 * N;
					continue;
				}
				int p = a[b] / (i + 1);
				q[a[b] / p].push_back(b);
				ma = max(ma, a[b] / p);
			}
			vector<int>().swap(q[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}