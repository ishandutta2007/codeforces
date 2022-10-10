#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

cat gcd(cat x, cat y) {
	if(x > y) swap(x, y);
	return (x == 0) ? y : gcd(y%x, x);
}

void solve_lup(int hi, int low, vector< vector<char> > & E, auto & dp_lup, auto & dp_rup) {
	for(int c = hi+1; c < low; c++)
		if(E[c][low] && dp_rup[c][low] && dp_lup[hi][c]) {
			dp_lup[hi][low] = true;
			return;
		}
}

void solve_rup(int low, int hi, vector< vector<char> > & E, auto & dp_lup, auto & dp_rup) {
	for(int c = low+1; c < hi; c++)
		if(E[c][low] && dp_lup[low][c] && dp_rup[c][hi]) {
			dp_rup[low][hi] = true;
			return;
		}
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N+2);
	for(int i = 1; i <= N; i++) cin >> A[i];
	vector< vector<char> > E(N+2, vector<char>(N+2));
	for(int i = 0; i < N+2; i++) E[0][i] = E[i][N+1] = true;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) E[i][j] = (gcd(A[i], A[j]) > 1);
	vector< vector<char> > dp_lup(N+2, vector<char>(N+2, false));
	vector< vector<char> > dp_rup(N+2, vector<char>(N+2, false));
	for(int i = 0; i <= N; i++) dp_lup[i][i+1] = dp_rup[i][i+1] = true;
	for(int d = 2; d <= N+1; d++) for(int i = 0; i <= N+1-d; i++) {
		solve_lup(i, i+d, E, dp_lup, dp_rup);
		solve_rup(i, i+d, E, dp_lup, dp_rup);
	}
	if(!dp_lup[0][N+1]) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}