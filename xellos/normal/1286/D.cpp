#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

using cat = long long;
constexpr cat mod = 998244353;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

struct frac {
	cat u, d;

	bool operator<(const frac & F) const {
		return u*F.d < F.u*d;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<cat> X(N), V(N);
	int P[2][100010];
	for(int i = 0; i < N; i++) {
		cin >> X[i] >> V[i] >> P[1][i];
		P[0][i] = 100-P[1][i];
	}
	vector< pair<frac, int> > col;
	for(int i = 1; i < N; i++) {
		col.push_back({{X[i]-X[i-1], V[i]+V[i-1]}, i});
		if(V[i] > V[i-1])
			col.push_back({{X[i]-X[i-1], V[i]-V[i-1]}, i});
		if(V[i] < V[i-1])
			col.push_back({{X[i]-X[i-1], V[i-1]-V[i]}, i});
	}
	sort(begin(col), end(col));
	int M[20][100010][4];
	for(int i = 0; i < N-1; i++) {
		for(int k = 0; k < 4; k++) M[0][i][k] = P[k&1][i+1];
		for(int k = 1; k < 20; k++) {
			int l = i;
			l -= l & ((1<<k)-1);
			if(l+(1<<k) != i+1) continue;
			M[k][l][0] = (1LL*M[k-1][l][0] * M[k-1][l+(1<<(k-1))][0] + 1LL*M[k-1][l][1] * M[k-1][l+(1<<(k-1))][2]) % mod;
			M[k][l][1] = (1LL*M[k-1][l][0] * M[k-1][l+(1<<(k-1))][1] + 1LL*M[k-1][l][1] * M[k-1][l+(1<<(k-1))][3]) % mod;
			M[k][l][2] = (1LL*M[k-1][l][2] * M[k-1][l+(1<<(k-1))][0] + 1LL*M[k-1][l][3] * M[k-1][l+(1<<(k-1))][2]) % mod;
			M[k][l][3] = (1LL*M[k-1][l][2] * M[k-1][l+(1<<(k-1))][1] + 1LL*M[k-1][l][3] * M[k-1][l+(1<<(k-1))][3]) % mod;
		}
	}
	cat ans = 0;
	for(auto [f, id] : col) {
		int dir[2] = {1, 0};
		if(V[id]-V[id-1] == f.d) dir[0] = dir[1] = 0;
		if(V[id-1]-V[id] == f.d) dir[0] = dir[1] = 1;
		cat val0 = 1, val1 = 1;
		for(int l = id, r = N-1; r != l;) {
			int k = 0;
			while(r-(2<<k) >= l && !((r>>k)&1)) k++;
			cat val_nw = (val0 * M[k][r-(1<<k)][0] + val1 * M[k][r-(1<<k)][1]) % mod;
			val1 = (val0 * M[k][r-(1<<k)][2] + val1 * M[k][r-(1<<k)][3]) % mod;
			val0 = val_nw;
			r -= 1<<k;
		}
		{
			cat val_nw = (dir[1] ? val1 : val0) * P[dir[1]][id] % mod;
			if(dir[0]) val1 = val_nw, val0 = 0;
			else val0 = val_nw, val1 = 0;
		}
		for(int l = 0, r = id-1; r != l;) {
			int k = 0;
			while(r-(2<<k) >= l && !((r>>k)&1)) k++;
			cat val_nw = (val0 * M[k][r-(1<<k)][0] + val1 * M[k][r-(1<<k)][1]) % mod;
			val1 = (val0 * M[k][r-(1<<k)][2] + val1 * M[k][r-(1<<k)][3]) % mod;
			val0 = val_nw;
			r -= 1<<k;
		}
		cat E = (P[0][0]*val0 + P[1][0]*val1) % mod * f.u % mod * pw(f.d, mod-2) % mod;
		ans += E;
		M[0][id-1][dir[0]*2+dir[1]] = 0;
		for(int k = 1; k < 20; k++) {
			int l = id-1;
			l -= l & ((1<<k)-1);
			if(l+(1<<k) > N-1) break;
			M[k][l][0] = (1LL*M[k-1][l][0] * M[k-1][l+(1<<(k-1))][0] + 1LL*M[k-1][l][1] * M[k-1][l+(1<<(k-1))][2]) % mod;
			M[k][l][1] = (1LL*M[k-1][l][0] * M[k-1][l+(1<<(k-1))][1] + 1LL*M[k-1][l][1] * M[k-1][l+(1<<(k-1))][3]) % mod;
			M[k][l][2] = (1LL*M[k-1][l][2] * M[k-1][l+(1<<(k-1))][0] + 1LL*M[k-1][l][3] * M[k-1][l+(1<<(k-1))][2]) % mod;
			M[k][l][3] = (1LL*M[k-1][l][2] * M[k-1][l+(1<<(k-1))][1] + 1LL*M[k-1][l][3] * M[k-1][l+(1<<(k-1))][3]) % mod;
		}
	}
	ans = ans % mod * pw(pw(100, mod-2), N) % mod;
	cout << ans << "\n";
}