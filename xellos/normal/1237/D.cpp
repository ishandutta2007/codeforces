#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(4*N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i+N] = A[i+2*N] = A[i+3*N] = A[i];
	}
	vector<int> next_gt(4*N, 4*N);
	stack<int> st;
	for(int i = 4*N-1; i >= 0; i--) {
		while(!st.empty() && A[st.top()] < A[i]) st.pop();
		if(!st.empty()) next_gt[i] = st.top();
		st.push(i);
	}
	vector<int> A_min[20];
	A_min[0] = A;
	for(int i = 1; i < 20; i++) {
		A_min[i] = A_min[i-1];
		for(int j = 0; j <= 4*N-(1<<i); j++) A_min[i][j] = min(A_min[i][j], A_min[i-1][j+(1<<(i-1))]);
	}
	vector<int> ans(4*N, -1);
	for(int i = 3*N-1; i >= 0; i--) {
		int n = next_gt[i]; // < 4N
		int x = A[i]/2; if(2*x == A[i]) x--;
		int cur = i;
		for(int k = 19; k >= 0; k--) while(cur+(1<<k) <= n && A_min[k][cur] > x) cur += 1<<k;
		if(cur != n) ans[i] = cur-i;
		else ans[i] = (ans[n] == -1) ? -1 : (ans[n] + n-i);
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
}