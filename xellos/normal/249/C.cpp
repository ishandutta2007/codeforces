#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int MX = 1000;
	vector<double> fac(MX+1, 1);
	for(int i = 1; i <= MX; i++) fac[i] = i * fac[i-1];
	int N, Q;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector< vector<double> > P(N);
	vector<int> total(N);
	for(int i = 0; i < N; i++) {
		P[i].resize(A[i]+1, 0);
		P[i][A[i]] = 1;
		total[i] = A[i];
	}
	double ans = 0;
	for(int i = 0; i < N; i++) if(A[i] == 0) ans++;
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		u--, v--;
		ans -= P[u][0];
		vector<double> P_nw(A[u]+1, 0);
		int t = total[u];
		double r = fac[d];
		for(int j = 0; j < d; j++) r /= t-j;
		for(int k = 0; k <= A[u]; k++) {
			if(t == k) {
				P_nw[t-d] += P[u][t];
				break;
			}
			double p = r * fac[k];
			for(int j = t-k; j > t-min(k+d, t); j--) p *= j;
			for(int j = max(0, d+k-t); j <= min(k, d); j++) {
				P_nw[k-j] += P[u][k] * p/(fac[j]*fac[k-j]*fac[d-j]);
				p /= t-k-d+j+1;
			}
		}
		P[u] = P_nw;
		ans += P[u][0];
		total[u] -= d;
		total[v] += d;
		cout << ans << "\n";
	}
}