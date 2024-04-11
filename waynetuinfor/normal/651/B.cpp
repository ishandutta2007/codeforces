#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int N, a;
vector<int> A, ans;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a, A.push_back(a);
	sort(A.begin(), A.end());
	while (A.size()) {
		vector<int> B; B.clear();
		ans.push_back(A[0]);
		int p = 0;
		for (int i = 1; i < A.size(); ++i) {
			if (A[i] > A[p]) ans.push_back(A[i]), p = i;
			else B.push_back(A[i]);
		}
		A = B;
	}
	int cnt = 0;
	for (int i = 1; i < ans.size(); ++i) {
		if (ans[i] > ans[i - 1]) ++cnt;
	}
	cout << cnt << '\n';
	return 0;
}