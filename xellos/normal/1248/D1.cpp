#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	string S;
	cin >> N >> S;
	int mi = 0, mi_pos = 0;
	for(int i = 0, cur = 0; i < N; i++) {
		if(S[i] == '(') cur++;
		else cur--;
		if(cur < mi) {
			mi = cur;
			mi_pos = i+1;
		}
		if(i == N-1 && cur != 0) {
			cout << "0\n1 1\n";
			return 0;
		}
	}
	S = S.substr(mi_pos, N-mi_pos) + S.substr(0, mi_pos);
	int ans = 0;
	pair<int, int> ans_p = {0, 0};
	vector<int> sum(N+1, 0);
	for(int i = 0, cur = 0; i < N; i++) {
		if(S[i] == '(') cur++;
		else cur--;
		sum[i+1] = cur;
		if(cur == 0) ans++;
	}
	int ans0 = ans;
	string S2 = S;
	swap(S2[0], S2[N-1]);
	int sum_mi = 0, cnt_mi = 0;
	for(int i = 0, cur = 0; i < N; i++) {
		if(S2[i] == '(') cur++;
		else cur--;
		if(cur < sum_mi) {
			sum_mi = cur;
			cnt_mi = 0;
		}
		if(cur == sum_mi) cnt_mi++;
	}
	if(cnt_mi > ans) {
		ans = cnt_mi;
		ans_p = {0, N-1};
	}
	vector<int> cnt_2(N+1, 0);
	for(int i = 0; i <= N; i++) if(sum[i] == 2) cnt_2[i]++;
	for(int i = 0; i < N; i++) cnt_2[i+1] += cnt_2[i];
	int nxt_1 = 0;
	for(int i = 0; i < N; i++) if(S[i] == '(' && sum[i+1] == 2) {
		nxt_1 = max(nxt_1, i+1);
		while(sum[nxt_1] != 1) nxt_1++;
		if(ans < ans0+cnt_2[nxt_1]-cnt_2[i]) {
			ans = ans0+cnt_2[nxt_1]-cnt_2[i];
			ans_p = {i, nxt_1-1};
		}
	}
	vector<int> cnt_1(N+1, 0);
	for(int i = 0; i <= N; i++) if(sum[i] == 1) cnt_1[i]++;
	for(int i = 0; i < N; i++) cnt_1[i+1] += cnt_1[i];
	int nxt_0 = 0;
	for(int i = 0; i < N; i++) if(S[i] == '(' && sum[i+1] == 1) {
		nxt_0 = max(nxt_0, i+1);
		while(sum[nxt_0] != 0) nxt_0++;
		if(ans < cnt_1[nxt_0]-cnt_1[i]) {
			ans = cnt_1[nxt_0]-cnt_1[i];
			ans_p = {i, nxt_0-1};
		}
	}
	ans_p.ff = (ans_p.ff+mi_pos) % N + 1;
	ans_p.ss = (ans_p.ss+mi_pos) % N + 1;
	cout << ans << "\n";
	cout << ans_p.ff << " " << ans_p.ss << "\n";
	return 0;
}

// look at my code
// my code is amazing