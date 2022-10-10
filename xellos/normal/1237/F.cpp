#include <iostream>
#include <vector>
using namespace std;

using cat = long long;
constexpr cat mod = 998244353;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int H, W, N;
	cin >> H >> W >> N;
	vector<char> free_h(H, 1), free_w(W, 1);
	for(int i = 0; i < N; i++) {
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		free_h[r1-1] = free_h[r2-1] = 0;
		free_w[c1-1] = free_w[c2-1] = 0;
	}
	vector<int> L_h, L_w;
	for(int i = 0; i < H; i++) if(free_h[i]) {
		int l = 0;
		while(i+l < H && free_h[i+l]) l++;
		L_h.push_back(l);
		i = i+l;
	}
	for(int i = 0; i < W; i++) if(free_w[i]) {
		int l = 0;
		while(i+l < W && free_w[i+l]) l++;
		L_w.push_back(l);
		i = i+l;
	}
	int N_h = L_h.size(), N_w = L_w.size();
	H = W = 0;
	for(int i = 0; i < N_h; i++) H += L_h[i];
	for(int i = 0; i < N_w; i++) W += L_w[i];
	vector< vector<cat> > C(4000, vector<cat>(4000, 0));
	for(int i = 0; i < 4000; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if(C[i][j] >= mod) C[i][j] -= mod;
		}
	}
	vector<cat> cnt_h(H/2+1, 0), cnt_w(W/2+1, 0);
	cnt_h[0] = 1;
	for(int i = 0; i < N_h; i++) {
		cat mod2 = 4 * mod * mod;
		for(int k = H/2; k >= 0; k--) if(cnt_h[k]) {
			cnt_h[k] %= mod;
			for(int j = 1; j <= L_h[i]/2; j++) {
				cnt_h[k+j] += cnt_h[k] * C[L_h[i]-j][j];
				if(cnt_h[k+j] >= mod2) cnt_h[k+j] -= mod2;
			}
		}
	}
	for(int i = 0; i <= H/2; i++) cnt_h[i] %= mod;
	cnt_w[0] = 1;
	for(int i = 0; i < N_w; i++) {
		cat mod2 = 4 * mod * mod;
		for(int k = W/2; k >= 0; k--) if(cnt_w[k]) {
			cnt_w[k] %= mod;
			for(int j = 1; j <= L_w[i]/2; j++) {
				cnt_w[k+j] += cnt_w[k] * C[L_w[i]-j][j];
				if(cnt_w[k+j] >= mod2) cnt_w[k+j] -= mod2;
			}
		}
	}
	for(int i = 0; i <= W/2; i++) cnt_w[i] %= mod;
	vector<cat> fac(10000, 1);
	for(int i = 1; i < 10000; i++) fac[i] = i * fac[i-1] % mod;
	for(int i = 0; i <= H/2; i++) cnt_h[i] = cnt_h[i] * fac[i] % mod;
	for(int i = 0; i <= W/2; i++) cnt_w[i] = cnt_w[i] * fac[i] % mod;
	cat ans = 0;
	for(int h = 0; h <= min(H, W/2); h++) {
		for(int w = 0; w <= min(W, H/2); w++)
			ans = (ans + cnt_h[w] * cnt_w[h] % mod * C[W-2*h][w] % mod * C[H-2*w][h]) % mod;
	}
	cout << ans << "\n";
}