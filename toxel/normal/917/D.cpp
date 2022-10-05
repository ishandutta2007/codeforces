#include <bits/stdc++.h>

#define MAXN (110)
#define mod (1000000007)


const int moder = 1e9 + 7;
const int N = 110;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int det(int (*a)[N], int n){
	int ret = 1;
	for (int i = 0; i < n; ++ i){
		int sit = -1;
		for (int j = i; j < n; ++ j){
			if (a[j][i]){
				sit = j;
				break;
			}
		}
		if (!~sit) return 0;
		if (sit != i){
			for (int j = i; j < n; ++ j){
				std::swap(a[i][j], a[sit][j]);
			}
			ret = ret ? moder - ret : 0;
		}
		for (int j = i + 1; j < n; ++ j){
			int coe = 1ll * a[j][i] * powermod(a[i][i], moder - 2) % moder;
			for (int k = i; k < n; ++ k){
				a[j][k] = (a[j][k] - 1ll * coe * a[i][k]) % moder;
				a[j][k] += a[j][k] < 0 ? moder : 0;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		ret = 1ll * ret * a[i][i] % moder;
	}
	return ret;
}

int x[N];

typedef long long ll;
typedef std::pair <int, int> pii;

int powermod(int a, int exp, int moder){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

struct poly{
	static const int N = 1000;
	
	int a[N];
	int length, moder;
	
	poly():length(-1), moder(0){memset(a, 0, sizeof(a));}
	poly(int moder):length(-1), moder(moder){memset(a, 0, sizeof(a));}
	
	int &operator [](int sit){return a[sit];}
	
	poly operator + (const poly &p)const{
		poly ret(moder);
		ret.length = std::max(length, p.length);
		for (int i = 0; i <= ret.length; ++ i){
			ret.a[i] = a[i] + p.a[i];
			ret.a[i] -= ret.a[i] >= moder ? moder : 0;
		}
		for ( ; ~ret.length && !ret.a[ret.length]; -- ret.length)
			;
		return ret;
	}
	
	poly operator - ()const{
		poly ret(moder);
		ret.length = length;
		for (int i = 0; i <= ret.length; ++ i){
			ret.a[i] = a[i] ? moder - a[i] : 0;
		}
		return ret;
	}
	
	poly operator - (const poly &p)const{
		poly ret(moder);
		ret.length = std::max(length, p.length);
		for (int i = 0; i <= ret.length; ++ i){
			ret.a[i] = a[i] - p.a[i];
			ret.a[i] -= ret.a[i] < 0 ? moder : 0;
		}
		for ( ; ~ret.length && !ret.a[ret.length]; -- ret.length)
			;
		return ret;
	}
	
	poly operator * (const poly &p)const{
		poly ret(moder);
		if (!~length || !~p.length) return ret;
		ret.length = length + p.length;
		for (int i = 0; i <= length; ++ i){
			for (int j = 0; j <= p.length; ++ j){
				ret.a[i + j] = (ret.a[i + j] + 1ll * a[i] * p.a[j]) % moder;
			}
		}
		return ret;
	}
	
	poly operator * (const int &p)const{
		poly ret(moder);
		ret.length = length;
		for (int i = 0; i <= ret.length; ++ i){
			ret.a[i] = 1ll * a[i] * p % moder;
		}
		return ret;
	}
	
	poly operator / (const poly &p)const{
		poly ret(moder);
		if (!~p.length) assert(("division by zero!", 0));
		if (length < p.length) return ret;
		ret.length = length - p.length;
		poly aux = *this;
		while (aux.length >= p.length){
			int x = 1ll * aux.a[aux.length] * powermod(p.a[p.length], moder - 2, moder) % moder;
			ret.a[aux.length - p.length] = x;
			for (int j = 0; j <= p.length; ++ j){
				int &u = aux.a[aux.length + j - p.length];
				u = (u - 1ll * x * p.a[j]) % moder;
				u += u < 0 ? moder : 0;
			}
			for ( ; ~aux.length && !aux.a[aux.length]; -- aux.length)
				;
		}
		return ret;
	}
	
	poly operator % (const poly &p)const{
		if (!~p.length) assert(("division by zero!", 0));
		poly ret = p;
		while (ret.length >= p.length){
			int x = 1ll * ret.a[ret.length] * powermod(p.a[p.length], moder - 2, moder) % moder;
			for (int j = 0; j <= p.length; ++ j){
				int &u = ret.a[ret.length + j - p.length];
				u = (u - 1ll * x * p.a[j]) % moder;
				u += u < 0 ? moder : 0;
			}
			for ( ; ~ret.length && !ret.a[ret.length]; -- ret.length)
				;
		}
		return ret;
	}
	
	static poly interpolation(std::vector <pii> vec, int moder){
		int n = vec.size() - 1;
		poly aux(moder); aux.length = 0; aux.a[0] = 1;
		for (int i = 0; i <= n; ++ i){
			poly aux1(moder); aux1.length = 1;
			aux1.a[1] = 1; aux1.a[0] = moder - vec[i].first;
			aux1.a[0] -= aux1.a[0] >= moder ? moder : 0;
			aux = aux * aux1;
		}
		poly ret(moder);
		for (int i = 0; i <= n; ++ i){
			poly aux1(moder); aux1.length = 1;
			aux1.a[1] = 1; aux1.a[0] = moder - vec[i].first;
			aux1.a[0] -= aux1.a[0] >= moder ? moder : 0;
			poly aux2 = aux / aux1;
			int x = 1;
			for (int j = 0; j <= n; ++ j){
				if (i == j) continue;
				x = 1ll * x * (vec[i].first - vec[j].first) % moder;
				x += x < 0 ? moder : 0;
			}
			x = powermod(x, moder - 2, moder);
			ret = ret + (aux2 * x) * vec[i].second;
		}
		return ret;
	}
};

int n;
int a[MAXN][MAXN][MAXN];
int du[MAXN];
int u[MAXN], v[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++ i){
		scanf("%d%d", u + i, v + i);
		++ du[u[i]];
		++ du[v[i]];
	}
	for(int t = 0; t <= n - 1; ++ t){
		for(int i = 1; i < n; ++ i){
			for(int j = 1; j < n; ++ j){
				if(i == j){
					a[t][i - 1][j - 1] = du[i] * t + (n - 1 - du[i]);
				}
				else{
					a[t][i - 1][j - 1] = -1;
				}
			}
		}
		for(int i = 1; i < n; ++ i){
			if(u[i] < n && v[i] < n){
				a[t][u[i] - 1][v[i] - 1] = a[t][v[i] - 1][u[i] - 1] = -t;
			}
		}
	}
	for (int i = 0; i <= n - 1; ++ i){
		x[i] = det(a[i], n - 1);
	}
	
	std::vector <pii> vec;
	for (int i = 0; i <= n - 1; ++ i){
		vec.push_back({i, x[i]});
	}
	poly ret = poly::interpolation(vec, moder);
	
	for(int i = 0; i <= n - 1; ++ i){
		printf("%d ", ret[i]);
	}
	printf("\n");
	return 0;
}