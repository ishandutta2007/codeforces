#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<int> L(M);
	for(int i = 0; i < M; i++) cin >> L[i];
	vector<cat> min_L(M+1, 0), max_L(M+1, 0);
	for(int i = M-1; i >= 0; i--) {
		max_L[i] = max_L[i+1] + L[i];
		min_L[i] = 1 + max(L[i]-1LL, min_L[i+1]);
	}
	if(N < min_L[0] || N > max_L[0]) {
		cout << "-1\n";
		return 0;
	}
	for(int i = 0, a = 0; i < M; i++) {
		cout << a+1 << ((i == M-1) ? "\n" : " ");
		a++;
		while(N-a > max_L[i+1]) a++;
	}
}