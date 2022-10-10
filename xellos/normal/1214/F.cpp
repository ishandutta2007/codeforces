#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
using cat = long long;

void add_to_interval(int l, int r, cat val, vector<cat> & A) {
	int N = A.size()-1;
	// add to i%N for l <= i <= r
	if(l > r) return;
	int start = l;
	while(start < 0) start += N;
	while(start >= N) start -= N;
	A[start] += val;
	if(start+r-l < N) A[start+r-l+1] -= val;
	else {
		A[N] -= val;
		A[0] += val;
		A[start+r-l+1-N] -= val;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cat M;
	cin >> M >> N;
	if(M == 1) {
		cout << "0\n";
		for(int i = 0; i < N; i++) cout << i+1 << ((i == N-1) ? "\n" : " ");
		return 0;
	}
	vector< pair<cat, int> > A(N), B(N);
	for(int i = 0; i < N; i++) cin >> A[i].first;
	for(int i = 0; i < N; i++) cin >> B[i].first;
	for(int i = 0; i < N; i++) {
		A[i].first--, B[i].first--;
		A[i].second = B[i].second = i+1;
	}
	sort(begin(A), end(A));
	sort(begin(B), end(B));
 
	vector<cat> ans(N+1, 0);
	for(int i = 0; i < N; i++) {
		cat l = B[i].first-M/2, r = B[i].first+M/2, c = B[i].first;
		pair<cat, int> p_l = {l, -1}, p_r = {r+1, -1}, p_cl = {c, -1}, p_cr = {c+1, -1};
		auto it_l  = lower_bound(begin(A), end(A), p_l);
		auto it_r  = lower_bound(begin(A), end(A), p_r);
		auto it_cl = lower_bound(begin(A), end(A), p_cl);
		auto it_cr = lower_bound(begin(A), end(A), p_cr);
		add_to_interval(i-(it_l-begin(A))+1, i, -B[i].first+M, ans);
		add_to_interval(i-(it_cl-begin(A))+1, i-(it_l-begin(A)), B[i].first, ans);
		add_to_interval(i-(it_r-begin(A))+1, i-(it_cr-begin(A)), -B[i].first, ans);
		add_to_interval(i-(N-1), i-(it_r-begin(A)), B[i].first+M, ans);
	}
	for(int i = 0; i < N; i++) {
		cat l = A[i].first-M/2, r = A[i].first+M/2, c = A[i].first;
		pair<cat, int> p_l = {l, -1}, p_r = {r+1, -1}, p_cl = {c, -1}, p_cr = {c+1, -1};
		auto it_l  = lower_bound(begin(B), end(B), p_l);
		auto it_r  = lower_bound(begin(B), end(B), p_r);
		auto it_cl = lower_bound(begin(B), end(B), p_cl);
		auto it_cr = lower_bound(begin(B), end(B), p_cr);
		add_to_interval(-i, (it_l-begin(B))-i-1, -A[i].first, ans);
		add_to_interval((it_l-begin(B))-i, (it_cl-begin(B))-i-1, A[i].first, ans);
		add_to_interval((it_cr-begin(B))-i, (it_r-begin(B))-i-1, -A[i].first, ans);
		add_to_interval((it_r-begin(B))-i, N-1-i, A[i].first, ans);
	}
	for(int i = 0; i < N; i++) ans[i+1] += ans[i];
 
	int opt_dif = 0;
	for(int i = 0; i < N; i++) if(ans[opt_dif] > ans[i]) opt_dif = i;
	cout << ans[opt_dif] << "\n";
	vector<int> ans_seq(N+1);
	for(int i = 0; i < N; i++)
		ans_seq[A[i].second] = B[(i+opt_dif)%N].second;
	for(int i = 0; i < N; i++)
		cout << ans_seq[i+1] << ((i == N-1) ? "\n" : " ");
}