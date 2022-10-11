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
#define soclose ((dbl)1e-4)
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct Bigint {
public:
	constexpr static int SZ = 6;
	long long v[SZ];

	void norm() {
		for(int i = 0; i < SZ-1; i++) {
			long long c = v[i] / (1LL<<30);
			v[i] -= c * (1LL<<30);
			while(v[i] < 0) v[i] += (1LL<<30), c--;
			v[i+1] += c;
		}
		if(v[SZ-1] < 0) for(int i = SZ-1; i > 0; i--) {
			long long r = v[i] * (1LL<<30);
			if(v[i-1]+r > -(1LL<<30)) {
				v[i] = 0;
				v[i-1] += r;
			}
			else break;
		}
	}

public:
	Bigint(long long v_) {
		for(int k = 3; k < SZ; k++) v[k] = 0;
		for(int k = 0; k <= 2; k++) {
			v[k] = v_ % (1LL<<30);
			v_ -= v[k];
			v_ /= 1LL<<30;
		}
	}

	long long operator()() const {
		long long ret = 0;
		for(int i = SZ-1; i >= 0; i--) ret = ret * (1LL<<30) + v[i];
		return ret;
	}

	Bigint operator+(long long a) const { return *this + Bigint(a); }
	Bigint operator-(long long a) const { return *this - Bigint(a); }
	Bigint operator*(long long a) const { return *this * Bigint(a); }
	Bigint & operator+=(long long a) { return *this += Bigint(a); }
	Bigint & operator-=(long long a) { return *this -= Bigint(a); }
	Bigint & operator*=(long long a) { return *this *= Bigint(a); }

	Bigint operator+(Bigint a) const {
		Bigint ret(0);
		for(int i = 0; i < SZ; i++) ret.v[i] = this->v[i] + a.v[i];
		ret.norm();
		return ret;
	}

	Bigint operator-(Bigint a) const {
		Bigint ret(0);
		for(int i = 0; i < SZ; i++) ret.v[i] = this->v[i] - a.v[i];
		ret.norm();
		return ret;
	}

	Bigint operator*(Bigint a) const {
		Bigint ret(0);
		for(int i = 0; i < SZ; i++)
			for(int j = 0; j < SZ-i; j++) ret.v[i+j] += this->v[i] * a.v[j];
		ret.norm();
		return ret;
	}

	Bigint & operator+=(Bigint a) {
		for(int i = 0; i < SZ; i++) this->v[i] += a.v[i];
		this->norm();
		return *this;
	}

	Bigint & operator-=(Bigint a) {
		for(int i = 0; i < SZ; i++) this->v[i] -= a.v[i];
		this->norm();
		return *this;
	}

	Bigint & operator*=(Bigint a) {
		long long v0[SZ];
		for(int i = 0; i < SZ; i++) {
			v0[i] = this->v[i];
			this->v[i] = 0;
		}
		for(int i = 0; i < SZ; i++)
			for(int j = 0; j < SZ-i; j++) this->v[i+j] += a.v[i] * v0[j];
		this->norm();
		return *this;
	}

	bool is_negative() const {
		for(int i = 0; i < SZ; i++) if(this->v[i] < 0) return true;
		return false;
	}

	bool is_zero() const {
		for(int i = 0; i < SZ; i++) if(this->v[i] != 0) return false;
		return true;
	}

	bool operator<(const Bigint & a) const {
		Bigint dif = *this - a;
		return dif.is_negative();
	}

	bool operator>(const Bigint & a) const {
		Bigint dif = a - *this;
		return dif.is_negative();
	}

	dbl sqrt() {
		long long l = 0, r = 1LL<<62;
		while(r-l > 1) {
			long long c = l/2+r/2+(l%2+r%2)/2;
			if(Bigint(c)*Bigint(c) > *this) r = c;
			else l = c;
		}
		if(l < (1LL<<31)) return std::sqrt((dbl)(*this)()); // non-negative
		// (l+f)**2 == *this, f ~= (*this-l**2)/2l
		Bigint d = *this - l*l;
		return l + d() / (dbl)2. / l;
	}

	dbl to_double() {
		if(this->is_negative()) {
			Bigint m = (*this) * -1;
			return m.to_double() * -1;
		}
		dbl ret = 0;
		for(int i = SZ-1; i >= 0; i--) ret = ret * (1<<30) + this->v[i];
		return ret;
	}
};

struct pt {
	cat x, y;

	bool operator<(const pt & P) const {
		if(x != P.x) return x < P.x;
		return y < P.y;
	}

	bool operator==(const pt & P) const {
		return x == P.x && y == P.y;
	}

	bool operator!=(const pt & P) const {
		return x != P.x || y != P.y;
	}
};

vector<pt> get_points(dbl cos0, dbl sin0, dbl cos1, dbl sin1, dbl R, dbl cx, dbl cy, cat ax, cat ay, cat aR) {
	vector<pt> ret;
	for(int k = -1; k <= 1; k++) {
		dbl x = cx + R * (cos0*cos1-k*sin0*sin1), y = cy + R * (cos1*sin0+k*sin1*cos0);
		cat xl = floor(x), xr = ceil(x);
		cat yl = floor(y), yr = ceil(y);
		for(cat xi = xl-5; xi <= xr+5; xi++) {
			cat d = aR-(xi-ax)*(xi-ax);
			if(d < 0) continue;
			cat yi = (cat)sqrt((dbl)d);
			if(yi*yi < d) {
				while(yi*yi < d) yi++;
			}
			else {
				while(yi*yi > d) yi--;
			}
			if(yi*yi == d) {
				ret.push_back({xi, ay+yi});
				ret.push_back({xi, ay-yi});
			}
		}
		for(cat yi = yl-5; yi <= yr+5; yi++) {
			cat d = aR-(yi-ay)*(yi-ay);
			if(d < 0) continue;
			cat xi = (cat)sqrt((dbl)d);
			if(xi*xi < d) {
				while(xi*xi < d) xi++;
			}
			else {
				while(xi*xi > d) xi--;
			}
			if(xi*xi == d) {
				ret.push_back({ax-xi, yi});
				ret.push_back({ax+xi, yi});
			}
		}
	}
	for(int i = (int)ret.size()-1; i >= 0; i--)
		for(int j = i-1; j >= 0; j--)
			if(ret[j] == ret[i]) {
				ret.erase(begin(ret)+i);
				break;
			}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N;
	vector<pt> P(N);
	Bigint sum_x(0), sum_y(0), sum_sq(0);
	uint64_t Lsum_x = 0, Lsum_y = 0, Lsum_sq = 0;
	cat Msum_x = 0, Msum_y = 0, Msum_sq = 0;
	cat mod = 1000000009;
	uint64_t Lsum_xy = 0, Lsum_x2 = 0, Lsum_y2 = 0;
	uint64_t Lsum_x4 = 0, Lsum_y4 = 0, Lsum_x2y2 = 0;
	uint64_t Lsum_x3 = 0, Lsum_y3 = 0, Lsum_xy2 = 0, Lsum_x2y = 0;
	cat Msum_xy = 0, Msum_x2 = 0, Msum_y2 = 0;
	cat Msum_x4 = 0, Msum_y4 = 0, Msum_x2y2 = 0;
	cat Msum_x3 = 0, Msum_y3 = 0, Msum_xy2 = 0, Msum_x2y = 0;
	for(int i = 0; i < N; i++) {
		cin >> P[i].x >> P[i].y;
		sum_x += P[i].x, Lsum_x += P[i].x, Msum_x += P[i].x;
		sum_y += P[i].y, Lsum_y += P[i].y, Msum_y += P[i].y;
		sum_sq += P[i].x * P[i].x + P[i].y * P[i].y;
		Lsum_sq += (uint64_t)(P[i].x) * (uint64_t)(P[i].x) + (uint64_t)(P[i].y) * (uint64_t)(P[i].y);
		Msum_sq = (Msum_sq + P[i].x*P[i].x + P[i].y*P[i].y) % mod;
		Lsum_xy += (uint64_t)P[i].x * (uint64_t)P[i].y;
		Lsum_x2 += (uint64_t)P[i].x * (uint64_t)P[i].x;
		Lsum_y2 += (uint64_t)P[i].y * (uint64_t)P[i].y;
		Lsum_x4 += (uint64_t)P[i].x * (uint64_t)P[i].x * (uint64_t)P[i].x * (uint64_t)P[i].x;
		Lsum_y4 += (uint64_t)P[i].y * (uint64_t)P[i].y * (uint64_t)P[i].y * (uint64_t)P[i].y;
		Lsum_x2y2 += (uint64_t)P[i].x * (uint64_t)P[i].x * (uint64_t)P[i].y * (uint64_t)P[i].y;
		Lsum_x3 += (uint64_t)P[i].x * (uint64_t)P[i].x * (uint64_t)P[i].x;
		Lsum_y3 += (uint64_t)P[i].y * (uint64_t)P[i].y * (uint64_t)P[i].y;
		Lsum_xy2 += (uint64_t)P[i].x * (uint64_t)P[i].y * (uint64_t)P[i].y;
		Lsum_x2y += (uint64_t)P[i].x * (uint64_t)P[i].x * (uint64_t)P[i].y;
		Msum_xy = (Msum_xy + P[i].x * P[i].y) % mod;
		Msum_x2 = (Msum_x2 + P[i].x * P[i].x) % mod;
		Msum_y2 = (Msum_y2 + P[i].y * P[i].y) % mod;
		Msum_x4 = (Msum_x4 + P[i].x * P[i].x % mod * P[i].x % mod * P[i].x) % mod;
		Msum_y4 = (Msum_y4 + P[i].y * P[i].y % mod * P[i].y % mod * P[i].y) % mod;
		Msum_x2y2 = (Msum_x2y2 + P[i].x * P[i].x % mod * P[i].y % mod * P[i].y) % mod;
		Msum_x3 = (Msum_x3 + P[i].x * P[i].x % mod * P[i].x) % mod;
		Msum_y3 = (Msum_y3 + P[i].y * P[i].y % mod * P[i].y) % mod;
		Msum_xy2 = (Msum_xy2 + P[i].x * P[i].y % mod * P[i].y) % mod;
		Msum_x2y = (Msum_x2y + P[i].x * P[i].x % mod * P[i].y) % mod;
	}
	Msum_x %= mod, Msum_y %= mod;
	dbl cx = sum_x() / (dbl)1. / N, cy = sum_y() / (dbl)1. / N;
	pt P0 = P[0];
	if(P0.x*N == sum_x() && P0.y*N == sum_y()) P0 = P[1];
	dbl dx = P0.x-cx, dy = P0.y-cy;
	dbl dl = sqrt(dx*dx+dy*dy);
	Bigint dL = (Bigint(N*P0.x)-sum_x)*(Bigint(N*P0.x)-sum_x)+(Bigint(N*P0.y)-sum_y)*(Bigint(N*P0.y)-sum_y);
	dbl a0 = atan2(dy, dx);
	cin >> M;
	for(int q = 0; q < M; q++) {
		vector<cat> D(N);
		Bigint sum_D = 0;
		uint64_t Lsum_D = 0, L2sum_D = 0;
		cat Msum_D = 0, M2sum_D = 0;
		for(int i = 0; i < N; i++) {
			cin >> D[i];
			sum_D += D[i];
			Lsum_D += (uint64_t)D[i];
			Msum_D = (Msum_D + D[i]) % mod;
			cat M2D = (D[i]%mod) * (D[i]%mod);
			uint64_t L2D = (uint64_t)D[i] * (uint64_t)D[i];
			M2sum_D = (M2sum_D + M2D) % mod;
			L2sum_D += L2D;
		}
		Bigint sum = (sum_D - sum_sq) * N + sum_x*sum_x + sum_y*sum_y; // (Nx-sum_x)^2 + (Ny-sum_y)^2
		uint64_t Lsum = (Lsum_D - Lsum_sq) * (uint64_t)N + Lsum_x*Lsum_x + Lsum_y*Lsum_y;
		cat Msum = ((Msum_D - Msum_sq) * N + Msum_x*Msum_x + Msum_y*Msum_y) % mod;
		dbl C = sum.sqrt()/N;
		vector<pt> cand_real;
		for(int i = 0; i < N; i++) {
			Bigint cos_sum = sum + dL - Bigint(1LL*N*N) * D[i];
			dbl cos_val = cos_sum.to_double()/(2*C*dl*N*N);
			if(cos_val < -1.01 || cos_val > 1.01) continue;
			cos_val = min(max((dbl)-1., cos_val), (dbl)1.);
			vector<pt> cand = get_points(dx/dl, dy/dl, cos_val, sqrt(1-cos_val*cos_val), C, cx, cy, P0.x, P0.y, D[i]);
			for(auto & p : cand) {
				if(N == 2) {
					cand_real.push_back(p);
					continue;
				}
				cat X = N * p.x - sum_x(), Y = N * p.y - sum_y();
				if((uint64_t)X * (uint64_t)X + (uint64_t)Y * (uint64_t)Y != Lsum) continue;
				cat MX = X%mod, MY = Y%mod;
				if((MX*MX + MY*MY - Msum) % mod != 0) continue;
				uint64_t LX = (uint64_t)p.x, LY = (uint64_t)p.y;
				if(L2sum_D != (uint64_t)N * (LX*LX*LX*LX+LY*LY*LY*LY+LX*LX*LY*LY*2)
					+ Lsum_x4 + Lsum_y4 + 2*Lsum_x2y2
					+ LX*LX*(6*Lsum_x2+2*Lsum_y2) + LY*LY*(6*Lsum_y2+2*Lsum_x2)
					+ LX*(-4*Lsum_x3-4*Lsum_xy2) + LY*(-4*Lsum_y3-4*Lsum_x2y)
					+ LX*LX*LX*(-4*Lsum_x) + LY*LY*LY*(-4*Lsum_y) + LX*LY*(8*Lsum_xy)
					+ LX*LY*LY*(-4*Lsum_x) + LX*LX*LY*(-4*Lsum_y)) continue;
				// sum (x-X[i])^4 + (y-Y[i])^4 + 2(x-X[i])^2(y-Y[i])^2
				cat M_val = - M2sum_D;
				cat px2 = p.x * p.x % mod, py2 = p.y * p.y % mod;
				M_val += (px2*px2 + py2*py2 + px2*py2*2) % mod * N;
				M_val = (M_val + Msum_x4 + Msum_y4 + 2*Msum_x2y2) % mod;
				M_val = (M_val + (6*Msum_x2+2*Msum_y2)%mod*px2 + (6*Msum_y2+2*Msum_x2)%mod*py2) % mod;
				M_val = (M_val + (-4*Msum_x3-4*Msum_xy2) % mod * p.x + (-4*Msum_y3-4*Msum_x2y) % mod * p.y) % mod;
				M_val = (M_val + (-4*Msum_x)%mod*p.x%mod*px2 + (-4*Msum_y)%mod*p.y%mod*py2 + (8*Msum_xy)%mod*p.x%mod*p.y) % mod;
				M_val = (M_val + (-4*Msum_x)%mod*py2%mod*p.x + (-4*Msum_y)%mod*px2%mod*p.y) % mod;
				if(M_val != 0) continue;
				cand_real.push_back(p);
			}
		}
		vector<pt> ans;
		for(auto p : cand_real) {
			bool dup = false;
			for(int i = 0; i < (int)ans.size(); i++) if(p == ans[i]) dup = true;
			if(dup) continue;
			vector<cat> dists(N);
			for(int i = 0; i < N; i++) dists[i] = (P[i].x-p.x) * (P[i].x-p.x) + (P[i].y-p.y) * (P[i].y-p.y);
			sort(begin(dists), end(dists));
			bool ok = true;
			for(int i = 0; i < N; i++) if(dists[i] != D[i]) ok = false;
			if(ok) ans.push_back(p);
		}
		sort(begin(ans), end(ans));
		cout << ans.size();
		for(int i = 0; i < (int)ans.size(); i++) cout << " " << ans[i].x << " " << ans[i].y;
		cout << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing