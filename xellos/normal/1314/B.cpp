#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#define ff first
#define ss second
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	if(K == 0) {
		cout << "0\n";
		return 0;
	}
	vector<char> A(1<<N, 0);
	for(int i = 0; i < K; i++) {
		int a;
		cin >> a;
		A[a-1] = 1;
	}
	vector<char> dp(1<<(N-1), 0);
	vector<int> max_g[4];
	for(int k = 0; k < 4; k++) max_g[k].resize(1<<(N-1), 0);
	for(int i = 0; i < (1<<(N-1)); i++) {
		if(A[i*2]+A[i*2+1] == 0) dp[i] = 1;
		if(A[i*2]+A[i*2+1] == 1) dp[i] = 2+4, max_g[1][i] = max_g[2][i] = 1;
		if(A[i*2]+A[i*2+1] == 2) dp[i] = 8, max_g[3][i] = 1;
	}
	while(dp.size() > 1) {
		N = dp.size();
		vector<char> dp_nw(N/2, 0);
		vector<int> max_g_nw[4];
		for(int i = 0; i < 4; i++) max_g_nw[i].resize(N/2, 0);
		for(int i = 0; i < N/2; i++)
			for(int j = 0; j < 4; j++) if((dp[2*i]>>j)&1)
				for(int k = 0; k < 4; k++) if((dp[2*i+1]>>k)&1) {
					int cnt = max_g[j][2*i] + max_g[k][2*i+1];
					cnt += (j|k)&1;
					cnt += ((j|k)&2)/2;
					if((j|k)&2 || (j&k)&1) cnt++;
					int nxt = 0;
					if((j|k)&2) nxt |= 2;
					if((j&k)&1) nxt |= 3;
					else if((j|k)&1) nxt |= 1;
					max_g_nw[nxt][i] = max(max_g_nw[nxt][i], cnt);
					dp_nw[i] |= 1<<nxt;
				}
		dp = dp_nw;
		for(int i = 0; i < 4; i++) max_g[i] = max_g_nw[i];
	}
	int ans = 0;
	for(int i = 0; i < 4; i++) if((dp[0]>>i)&1) ans = max(ans, max_g[i][0]);
	cout << ans+1 << "\n";
}