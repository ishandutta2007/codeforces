#include<bits/stdc++.h>
#define ll long long

const int N = 2010;

template <typename T>
struct frac{
private:
	T x, y;

public:	
	frac() : x(0), y(0){}
	frac(T x) : x(x), y(1){}
	
	frac(T x, T y){
		T gcd = std::__gcd(x, y);
		x /= gcd;
		y /= gcd;
		if (y < 0){
			x = -x;
			y = -y;
		}
		this -> x = x;
		this -> y = y;
	}
	
	void setfrac(T x){this -> x = x; y = 1;};
	
	void setfrac(T x, T y){
		T gcd = std::__gcd(x, y);
		x /= gcd;
		y /= gcd;
		if (y < 0){
			x = -x;
			y = -y;
		}
		this -> x = x;
		this -> y = y;
	}
	
	friend std::ostream & operator << (std::ostream &os, const frac &f){
		os << f.x << '/' << f.y;
		return os;
	}
	
	frac operator + (const frac &f) const &{return frac(x * f.y + y * f.x, y * f.y);}
	frac operator - (const frac &f) const &{return frac(x * f.y - y * f.x, y * f.y);}
	frac operator * (const frac &f) const &{return frac(x * f.x, y * f.y);}
	frac operator / (const frac &f) const &{if (!f.x) assert(("Division by zero!", 0)); return frac(x * f.y, y * f.x);}
	bool operator > (const frac &f) const &{return x * f.y > y * f.x;}
	bool operator >= (const frac &f) const &{return x * f.y >= y * f.x;}
	bool operator < (const frac &f) const &{return x * f.y < y * f.x;}
	bool operator <= (const frac &f) const &{return x * f.y <= y * f.x;}
	bool operator == (const frac &f) const &{return x * f.y == y * f.x;}
	bool operator != (const frac &f) const &{return x * f.y != y * f.x;}
	template <typename K>
	K real(){return (K) x / y;}	
};
int n;
int x[N], y[N];
std::vector <frac <int>> vec;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &y[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++ i){
		vec.clear();
		for (int j = 0; j < n; ++ j){
			if (i == j){
				continue;
			}
			if (x[i] == x[j]){
				vec.push_back(frac <int>(1001, 1002));
			}
			else{
				vec.push_back(frac <int>(y[j] - y[i], x[j] - x[i]));
			}
		}
		ll sz = vec.size(), sum2 = 0;
		std::sort(vec.begin(), vec.end());
		for (int i = 0, now = 1; i < sz; ++ i, ++ now){
			if (i == sz - 1 || vec[i] != vec[i + 1]){
				sum2 += now * now;
				now = 0;
			}
		}
		ans += sz * sz - sum2 >> 1;
	}
	return printf("%I64d\n", ans / 3), 0;
}