#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(2*N);
		for(int i = 0; i < 2*N; i++) cin >> A[i];
		sort(begin(A), end(A));
		cout << A[N]-A[N-1] << "\n";
	}
}