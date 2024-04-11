#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d(int a, int b, int c) {
	if(b > a) b = a;
	if(c < a) c = a;
	return c-b+min(c-a, a-b);
}

int main() {
	int N, A;
	cin >> N >> A;
	if(N == 1) {
		cout << "0\n";
		return 0;
	}
	vector<int> X(N);
	for(int i = 0; i < N; i++) cin >> X[i];
	sort(begin(X), end(X));
	cout << min(d(A, X[0], X[N-2]), d(A, X[1], X[N-1])) << "\n";
}