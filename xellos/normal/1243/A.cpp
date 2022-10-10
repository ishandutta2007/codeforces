#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		sort(begin(A), end(A));
		int ans = 0;
		for(int i = 0; i < N; i++) ans = max(ans, min(A[i], N-i));
		cout << ans << "\n";
	}
}