#include<bits/stdc++.h>

const double eps = 1e-9;
inline int sig(double p){return (p > eps) - (p < -eps);}

struct frac{
	int x, y;
	
	frac (int x = 0, int y = 0):x(x), y(y){}
	
	bool operator < (const frac &f)const{
		return 1ll * x * f.y > 1ll * y * f.x;
	}
	
	bool operator == (const frac &f)const{
		return 1ll * x * f.y == 1ll * y * f.x;
	}
};

struct func{
	double k, b;
	
	func (double k = 0, double b = 0):k(k), b(b){}
	
	bool operator < (const func &f)const{
		return k < f.k || b < f.b;
	}
	
	double solve(const func &f)const{
		if (!sig(k - f.k)) return 10;
		double ret = (f.b - b) / (k - f.k);
		return sig(ret) > 0 ? ret : 10;
	}
};

const int N = 150010;
typedef long long ll;
typedef std::pair <func, func> pff;

int p[N], t[N];
frac pp[N];

int main(){
	int n;
	ll T = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &t[i]);
		T += t[i];
		pp[i] = frac (p[i], t[i]);
	}
	std::sort(pp, pp + n);
	std::map <int, pff> Hash;
	ll c1 = 0, c2 = 0;
	for (int i = 0, j = 0; i < n; c1 = c2){
		while (j < n && pp[j] == pp[i]){
			c2 += pp[j ++].y;
		}
		while (i < j){
			func maxfunc(-1.0 * (c1 + pp[i].y) * pp[i].x / T, pp[i].x);
			func minfunc(-1.0 * c2 * pp[i].x / T, pp[i].x);
			if (!Hash.count(pp[i].x)){
				Hash[pp[i].x] = {minfunc, maxfunc};
			}
			else{
				auto &u = Hash[pp[i].x];
				u.first = std::min(u.first, minfunc);
				u.second = std::max(u.second, maxfunc);
			}
			++ i;
		}
	}
	double ans = 1.0;
	for (auto u = Hash.begin(); u != Hash.end(); ){
		auto v = u ++;
		if (u == Hash.end()) break;
		ans = std::min(ans, (v -> second).second.solve((u -> second).first));
	}
	printf("%.10lf\n", ans);
	return 0;
}