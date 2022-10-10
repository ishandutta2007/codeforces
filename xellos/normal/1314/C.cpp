#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define ff first
#define ss second
using namespace std;

using cat = long long;

struct sub {
	int st, l;
	string * s;

	bool operator<(const sub & A) const {
		int cur = 0;
		while(cur < l && cur < A.l && (*s)[st+cur] == (*s)[A.st+cur]) cur++;
		if(cur == l || cur == A.l) return l < A.l;
		return (*s)[st+cur] < (*s)[A.st+cur];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cat K;
	string S;
	cin >> N >> M >> K >> S;
	vector<sub> subs;
	for(int i = 0; i < N; i++) for(int j = i+1; j <= N; j++) subs.push_back({i, j-i, &S});
	sort(begin(subs), end(subs));
	int ans_l = 0, ans_r = subs.size();
	while(ans_r-ans_l > 1) {
		int ans_c = (ans_l+ans_r)/2;
		vector<int> min_l(N, 0);
		int id = subs[ans_c].st, l = subs[ans_c].l;
		for(int i = 0; i < N; i++) {
			while(min_l[i]+i < N && min_l[i] < l && S[min_l[i]+i] == S[min_l[i]+id]) min_l[i]++;
			if(min_l[i] == l) continue;
			if(min_l[i]+i == N) min_l[i] = 0;
			else if(S[min_l[i]+i] < S[min_l[i]+id]) min_l[i] = 0;
			else min_l[i]++;
		}
		if(!min_l[0]) {
			ans_r = ans_c;
			continue;
		}
		static cat dp[1001][1001];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int m = 0; m < M; m++) {
			static cat add[1001];
			memset(add, 0, sizeof(add));
			cat sum = 0;
			for(int i = 0; i <= N; i++) {
				sum = min(K, sum+add[i]);
				if(i == N || min_l[i]) dp[m+1][i] = sum;
				if(i < N) add[min_l[i]+i] = min(K, add[min_l[i]+i]+dp[m][i]);
			}
		}
		if(dp[M][N] < K) ans_r = ans_c;
		else ans_l = ans_c;
	}
	cout << S.substr(subs[ans_l].st, subs[ans_l].l) << "\n";
}