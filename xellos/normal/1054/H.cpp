#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

constexpr int P[2] = {491, 499};
constexpr cat mod = 490019;
 
struct comp {
	dbl x, y;
	
	inline comp(const dbl & _x = 0, const dbl & _y = 0) : x(_x), y(_y) {}
 
	inline __attribute__((always_inline)) comp operator+(const comp & b) const {
		return comp(x + b.x, y + b.y);
	}
 
	inline __attribute__((always_inline)) comp operator-(const comp & b) const {
		return comp(x - b.x, y - b.y);
	}
 
	inline __attribute__((always_inline)) comp operator*(const comp & b) const {
		return comp(x*b.x - y*b.y, x*b.y + y*b.x);
	}
};

void dft(comp * __restrict a, int n, bool rev = 0) {
	for(int i = 0, j = 0; i < n; ++i) {
		if(i < j) swap(a[i], a[j]);
		for(int k = n>>1; (j^=k) < k; k >>= 1) {}
	}
	for(int i = 2; i <= n; i <<= 1) {
		int len = i>>1;
		dbl ang = 2*pi/i;
		comp w = {cos(ang), sin(ang)};
		for(int j = 0; j < n; j += i) {
			comp cur(1, 0);
			for(int k = j; k < j+len; ++k) {
				comp u = a[k], v = a[k+len] * cur;
				a[k] = u + v, a[k+len] = u - v;
				cur = cur * w;
			}
		}
	}
	if(rev) {
		reverse(a+1, a+n);
		for(int i = 0; i < n; ++i) a[i].x /= n, a[i].y /= n;
	}
}

vector< vector<cat> > conv2D(auto & A, auto & B) {
	comp Ax[1<<10][1<<10];
	memset(Ax, 0, sizeof(Ax));
	for(int i = 0; i < P[0]-1; i++) {
		for(int j = 0; j < P[1]-1; j++) Ax[i][j] = {(dbl)A[i][j], 0};
		dft(Ax[i], 1<<10);
	}
	comp Ay[1<<10][1<<10];
	for(int i = 0; i < (1<<10); i++) {
		for(int j = 0; j < (1<<10); j++) Ay[i][j] = Ax[j][i];
		dft(Ay[i], 1<<10);
	}

	comp Bx[1<<10][1<<10];
	memset(Bx, 0, sizeof(Bx));
	for(int i = 0; i < P[0]-1; i++) {
		for(int j = 0; j < P[1]-1; j++) Bx[i][j] = {(dbl)B[i][j], 0};
		dft(Bx[i], 1<<10);
	}
	comp By[1<<10][1<<10];
	for(int i = 0; i < (1<<10); i++) {
		for(int j = 0; j < (1<<10); j++) By[i][j] = Bx[j][i];
		dft(By[i], 1<<10);
	}

	comp Cy[1<<10][1<<10];
	for(int i = 0; i < (1<<10); i++) {
		for(int j = 0; j < (1<<10); j++) Cy[i][j] = Ay[i][j] * By[i][j];
		dft(Cy[i], 1<<10, 1);
	}
	comp Cx[1<<10][1<<10];
	for(int i = 0; i < (1<<10); i++) {
		for(int j = 0; j < (1<<10); j++) Cx[i][j] = Cy[j][i];
		dft(Cx[i], 1<<10, 1);
	}

	vector< vector<cat> > ret(2*P[0]-1, vector<cat>(2*P[1]-1, 0));
	for(int i = 0; i <= 2*P[0]-2; i++) for(int j = 0; j <= 2*P[1]-2; j++)
		ret[i][j] = cat(Cx[i][j].x+.1);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, C;
	cin >> N >> M >> C;
	vector<int> A(N), B(M);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];

	vector<cat> pw(mod, 1);
	for(int i = 0; i < mod; i++) pw[i+1] = pw[i] * C % mod;

	cat ans = 0;
	for(int i = 0; i < N; i++) if(i%P[0] == 0 || i%P[1] == 0) {
		cat sum = 0, mod2 = 4*mod*mod;
		for(int j = 0; j < M; j++) {
			sum += B[j] * pw[1LL*i*i*j%(mod-1)*j*j%(mod-1)];
			if(sum >= mod2) sum -= mod2;
		}
		ans = (ans + sum % mod * A[i]) % mod;
	}
	for(int i = 0; i < M; i++) if(i%P[0] == 0 || i%P[1] == 0) {
		cat sum = 0, mod2 = 4*mod*mod;
		for(int j = 0; j < N; j++) if(j%P[0] != 0 && j%P[1] != 0) {
			sum += A[j] * pw[1LL*i*i*i%(mod-1)*j*j%(mod-1)];
			if(sum >= mod2) sum -= mod2;
		}
		ans = (ans + sum % mod * B[i]) % mod;
	}

	vector<int> dlog[2];
	vector<int> dexp[2];
	for(int k = 0; k < 2; k++) {
		dlog[k].resize(P[k]);
		dexp[k].resize(P[k]-1);
		for(int g = 2; g < P[k]; g++) {
			for(int i = 1; i < P[k]; i++) dlog[k][i] = -1;
			for(int i = 0, p = 1; i < P[k]-1; i++, p = p * g % P[k])
				dlog[k][p] = i, dexp[k][i] = p;
			bool ok = true;
			for(int i = 1; i < P[k]; i++) if(dlog[k][i] == -1) ok = false;
			if(ok) break;
		}
	}
	cat coef[3] = {-1, -1, P[0]*P[1]};
	for(int i = 0; i < mod-1; i += 2*P[0]) if(i%P[1] == 1) coef[1] = i;
	for(int i = 0; i < mod-1; i += 2*P[1]) if(i%P[0] == 1) coef[0] = i;
	if(coef[0] == -1 || coef[1] == -1) return 1;

	vector< vector<cat> > A_even(P[0]-1, vector<cat>(P[1]-1, 0));
	vector< vector<cat> > B_even(P[0]-1, vector<cat>(P[1]-1, 0));
	for(int i = 0; i < N; i++) if(i%P[0] != 0 && i%P[1] != 0)
		A_even[dlog[0][(1LL*i*i)%P[0]]][dlog[1][(1LL*i*i)%P[1]]] += A[i];
	for(int i = 0; i < M; i++) if(i%P[0] != 0 && i%P[1] != 0)
		B_even[dlog[0][(1LL*i*i*i)%P[0]]][dlog[1][(1LL*i*i*i)%P[1]]] += B[i];
	for(int i = 0; i < P[0]-1; i++) for(int j = 0; j < P[1]-1; j++)
		A_even[i][j] %= mod, B_even[i][j] %= mod;

	vector< vector<cat> > A_odd(P[0]-1, vector<cat>(P[1]-1, 0));
	vector< vector<cat> > B_odd(P[0]-1, vector<cat>(P[1]-1, 0));
	for(int i = 1; i < N; i += 2) if(i%P[0] != 0 && i%P[1] != 0)
		A_odd[dlog[0][(1LL*i*i)%P[0]]][dlog[1][(1LL*i*i)%P[1]]] += A[i];
	for(int i = 1; i < M; i += 2) if(i%P[0] != 0 && i%P[1] != 0)
		B_odd[dlog[0][(1LL*i*i*i)%P[0]]][dlog[1][(1LL*i*i*i)%P[1]]] += B[i];
	for(int i = 0; i < P[0]-1; i++) for(int j = 0; j < P[1]-1; j++)
		A_odd[i][j] %= mod, B_odd[i][j] %= mod;

	vector< vector<cat> > conv_even = conv2D(A_even, B_even);
	vector< vector<cat> > conv_odd = conv2D(A_odd, B_odd);

	for(int i = 0; i <= 2*(P[0]-2); i++) for(int j = 0; j <= 2*(P[1]-2); j++) {
		cat mul = pw[(dexp[0][i%(P[0]-1)]*coef[0]+dexp[1][j%(P[1]-1)]*coef[1])%(mod-1)] * (pw[coef[2]]-1) % mod;
		ans = (ans + conv_odd[i][j] * mul) % mod;
	}
	for(int i = 0; i <= 2*(P[0]-2); i++) for(int j = 0; j <= 2*(P[1]-2); j++) {
		cat mul = pw[(dexp[0][i%(P[0]-1)]*coef[0]+dexp[1][j%(P[1]-1)]*coef[1])%(mod-1)] % mod;
		ans = (ans + conv_even[i][j] * mul) % mod;
	}

	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing