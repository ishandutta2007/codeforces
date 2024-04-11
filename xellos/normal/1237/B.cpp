#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N), B(N), B_id(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		B[i]--;
		B_id[B[i]] = i;
	}
	int ans = 0;
	for(int i = 1, x = B_id[A[0]]; i < N; i++) {
		if(B_id[A[i]] < x) ans++;
		x = max(x, B_id[A[i]]);
	}
	cout << ans << "\n";
}