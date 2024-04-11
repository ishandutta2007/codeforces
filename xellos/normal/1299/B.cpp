#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	if(N%2 != 0) {
		cout << "NO\n";
		return 0;
	}
	vector<cat> X(N), Y(N);
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	cat sumX = X[0]+X[N/2];
	cat sumY = Y[0]+Y[N/2];
	for(int i = 0; i < N/2; i++) if(sumX != X[i]+X[N/2+i] || sumY != Y[i]+Y[N/2+i]) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}