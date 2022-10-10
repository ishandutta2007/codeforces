#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[100000];
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(A, A+N);
	int sum[2] = {0, 0};
	for(int i = 0; i < N/2; i++) sum[0] += A[i];
	for(int i = N/2; i < N; i++) sum[1] += A[i];
	cout << 1LL*sum[0]*sum[0] + 1LL*sum[1]*sum[1] << "\n";
}