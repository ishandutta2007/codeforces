// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

double get_Vy(const double Vx, const double alpha) {
	double x1_le = 0, x1_ge = cos(alpha/2);
	double Vy_ret;
	for(int i = 0; i < 60; i++) {
		double x1 = (x1_le + x1_ge) / 2;
		double x2 = -x1 * cos(alpha) + sqrt(1-pow(2*x1*sin(alpha/2),2)) * cos(alpha/2);
		double Vx_cur = ((1+cos(alpha))/2 + x1*x2*(1-cos(alpha))) * (x1-x2) / pow(cos(alpha/2),2);
		if(Vx_cur < Vx) x1_le = x1;
		else x1_ge = x1;
		Vy_ret = (2*x1*x2 + (x1-x2) * Vx_cur) / (x1+x2); // * tg(alpha/2)
	}
	return Vy_ret * tan(alpha/2);
}

double area_under(const double alpha, const double cutoff_l, const double cutoff_r) {
	constexpr int S = 100;
	double ca2 = cos(alpha/2), sa2 = sin(alpha/2);
	double ta2_sq = pow(sa2 / ca2, 2);
	double ca = cos(alpha);
	static vector<double> x1(S+1), x2(S+1);
	for(int i = 0; i <= S; i++) {
		x1[i] = ca2 * i / S;
		x2[i] = -x1[i] * ca + sqrt(1-pow(2*x1[i]*sa2,2)) * ca2;
	}
	static vector<double> Vx(S+1), Vy(S+1);
	for(int i = 0; i <= S; i++) {
		Vx[i] = (1 + 2 * x1[i] * x2[i] * ta2_sq) * (x1[i]-x2[i]);
		Vy[i] = (2 * x1[i] * x2[i] + (x1[i]-x2[i]) * Vx[i]) / (x1[i]+x2[i]); // * tg(alpha/2)
	}
	double Vy_l = get_Vy(-cutoff_l * ca2, alpha) / tan(alpha/2);
	double Vy_r = get_Vy(cutoff_r * ca2, alpha) / tan(alpha/2);
	double A = 0;
	for(int i = 1; i <= S; i++) {
		double Ux_l = Vx[i-1], Uy_l = Vy[i-1], Ux_r = Vx[i], Uy_r = Vy[i];
		if(Ux_l < -cutoff_l * ca2) {
			Ux_l = -cutoff_l * ca2;
			Uy_l = Vy_l;
		}
		if(Ux_r > cutoff_r * ca2) {
			Ux_r = cutoff_r * ca2;
			Uy_r = Vy_r;
		}
		if(Ux_l > Ux_r+soclose) continue;
		double x1h = ca2 * (i-.5) / S;
		double x2h = -x1h * ca + sqrt(1-pow(2*x1h*sa2,2)) * ca2;
		double x0h = (1 + 2 * x1h * x2h * ta2_sq) * (x1h-x2h);
		double y0h = (2 * x1h * x2h + (x1h-x2h) * x0h) / (x1h+x2h); // * tg(alpha/2)
		double C0 = y0h;
		double C1 = ((Uy_l-y0h) * (Ux_r-x0h) / (Ux_l-x0h) - (Uy_r-y0h) * (Ux_l-x0h) / (Ux_r-x0h)) / (Ux_r-Ux_l);
		double C2 = ((Uy_r-y0h) * (Ux_l-x0h) - (Uy_l-y0h) * (Ux_r-x0h)) / (Ux_l-x0h) / (Ux_r-x0h) / (Ux_r-Ux_l);
		A += C0 * (Ux_r-Ux_l) + C1 * (pow(Ux_r-x0h,2)-pow(Ux_l-x0h,2)) / 2 + C2 * (pow(Ux_r-x0h,3)-pow(Ux_l-x0h,3)) / 3;
	}
	A *= tan(alpha/2);
	A -= ca2 * (pow(cutoff_l,2) + pow(cutoff_r,2)) * sa2 / 2;
	return A;
}

int main() {
	cout << setprecision(10);
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	vector<double> alpha(N);
	for(int i = 0; i < N; i++) {
		double da = sqrt(pow(X[i]-X[(i+1)%N],2) + pow(Y[i]-Y[(i+1)%N],2));
		double db = sqrt(pow(X[(i+2)%N]-X[(i+1)%N],2) + pow(Y[(i+2)%N]-Y[(i+1)%N],2));
		double dc = sqrt(pow(X[i]-X[(i+2)%N],2) + pow(Y[i]-Y[(i+2)%N],2));
		alpha[(i+1)%N] = pi - acos((da*da+db*db-dc*dc)/2/da/db);
	}
	double ans = 0;
	vector<double> cutoff_l(N, 1), cutoff_r(N, 1);
	for(int i = 0; i < N; i++) {
		double d = sqrt(pow(X[i]-X[(i+1)%N],2) + pow(Y[i]-Y[(i+1)%N],2));
		if(abs(alpha[i]-alpha[(i+1)%N]) < soclose && abs(alpha[i]-pi/2) < soclose && abs(d-1) < soclose) {
			double Xdif = 0, Ydif = 0;
			for(int j = 0; j < N; j++) Xdif = max(Xdif, 1.*abs(X[j]-X[(j+1)%N]));
			for(int j = 0; j < N; j++) Ydif = max(Ydif, 1.*abs(Y[j]-Y[(j+1)%N]));
			cout << Xdif * Ydif << "\n";
			return 0;
		}
		if(d < 1.99) {
			// find x, y of intersection
			double cutoff_r_le = 0, cutoff_r_ge = 1;
			double x_i, y_i; // intersection
			for(int j = 0; j < 40; j++) {
				double cutoff_r_mid = (cutoff_r_le + cutoff_r_ge) / 2;
				double Vx0 = cutoff_r_mid * cos(alpha[i]/2);
				double Vy0 = get_Vy(Vx0, alpha[i]);
				x_i = Vx0 * cos(alpha[i]/2) + Vy0 * sin(alpha[i]/2);
				y_i = - Vx0 * sin(alpha[i]/2) + Vy0 * cos(alpha[i]/2);
				double Vy1 = cos(alpha[(i+1)%N]/2) * y_i + sin(alpha[(i+1)%N]/2) * (d - x_i);
				double Vx1 = cos(alpha[(i+1)%N]/2) * (d - x_i) - sin(alpha[(i+1)%N]/2) * y_i;
				cutoff_l[(i+1)%N] = Vx1 / cos(alpha[(i+1)%N]/2);
				if(Vy1 > get_Vy(Vx1, alpha[(i+1)%N])) cutoff_r_le = cutoff_r_mid;
				else cutoff_r_ge = cutoff_r_mid;
			}
			cutoff_r[i] = cutoff_r_ge;
			ans += pow(y_i,2) * (tan(alpha[i]/2) + tan(alpha[(i+1)%N]/2)) / 2;
		}
	}
	for(int i = 0; i < N; i++) ans += area_under(alpha[i], cutoff_l[i], cutoff_r[i]);
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing