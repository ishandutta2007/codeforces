#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	vector<pii> A(N);
	for(int i = 0 ; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());

	for(int i = 0; i < (N >> 1); i++) {
		cout << A[i].second + 1 << " " << A[N - i - 1].second + 1 << '\n';
	}
}