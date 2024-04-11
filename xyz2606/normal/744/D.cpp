#include<bits/stdc++.h>
using namespace std;
const int N(1011);
typedef double D;
D eps(1e-14);
inline int sign(const D & x) {
	return (x > eps) - (x + eps < 0);
}
struct P {
	D x, y;
	P() {
	}
	P(const D & x, const D & y) : x(x), y(y) {
	}
	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x; y = _y;
	}
	P operator + (const P & b) const {
		return P(x + b.x, y + b.y);
	}
	P operator - (const P & b) const {
		return P(x - b.x, y - b.y);
	}
	D sqrlen() const {
		return x * x + y * y;
	}
	D len() const {
		return sqrt(max((D)0., sqrlen()));
	}
	D operator * (const P & b) const {
		return x * b.y - y * b.x;
	}
	P zoom(const D & l) const {
		D lambda(l / len());
		return P(lambda * x, lambda * y);
	}
	bool operator < (const P & b) const {
		if(sign(x - b.x))
			return x < b.x;
		if(sign(y - b.y))
			return y < b.y;
		return false;
	}
	void print() const {
		printf("(%.20f, %.20f)\n", (double)x, (double)y);
	}
} a[N], b[N];
inline P operator * (const D & x, const P & a) {
	return P(x * a.x, x * a.y);
}
vector<P> convexHull(vector<P> vec) {
	vector<P> res;
	sort(vec.begin(), vec.end());
	int n(vec.size());
	for(int i(0); i < n; i++) {
		while(res.size() >= 2 && sign((res.back() - res[(int)res.size() - 2]) * (vec[i] - res.back())) <= 0)
			res.pop_back();
		res.push_back(vec[i]);
	}
	int cl(res.size());
	for(int i(n - 1); i >= 0; i--) {
		while(res.size() >= cl + 1 && sign((res.back() - res[(int)res.size() - 2]) * (vec[i] - res.back())) <= 0)
			res.pop_back();
		res.push_back(vec[i]);
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(0); i < n; i++) 
		a[i].scan();
	for(int i(0); i < m; i++)
		b[i].scan();
	D ans(0);
	for(int i(0); i < m + n; i++) {
		vector<P> vec;
		P o(i < m ? b[i] : a[i - m]);
		vec.push_back(P(0, 0));
		for(int j(0); j < m; j++) 
			if(j != i)
				vec.push_back(100 / (b[j] - o).sqrlen() * (b[j] - o));
		vector<P> cv(convexHull(vec));
		for(int j(0); j < (int)cv.size() - 1; j++) {
			bool flag(i >= m);
			for(int k(0); k < n && !flag; k++) {
				P na((100 / (a[k] - o).sqrlen()) * (a[k] - o));
				if(sign((cv[j + 1] - cv[j]) * (na - cv[j])) <= 0)
					flag = true;
			}
			if(flag) {
				D dis(fabs((cv[j] - P(0, 0)) * (cv[j + 1] - cv[j]).zoom(1)));
				if(sign(dis) == 0) {
					printf("-1\n");
					return 0;
				}else
					ans = max(ans, 50 / dis);
			}
		}
	}
	printf("%.12f\n", (double)ans);
}