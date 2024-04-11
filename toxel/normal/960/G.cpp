#include<bits/stdc++.h>

typedef long long ll;

int powermod(int a, int exp, int moder){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

void NTT(int *a, int length, int type, int moder, int root){
	if (length == 1) return;
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1);
	for(int i = 1, j = 0; i < length - 1; ++ i){
		for(int s = length; j ^= s >>= 1, ~j & s; )
			;
		if(i < j){
			std::swap(a[i], a[j]);
		}
	}
	int *w = new int [length];
	w[0] = 1, w[1] = powermod(root, moder - 1 >> len, moder);
	for (int i = 2; i < length; ++ i){
		w[i] = 1ll * w[i - 1] * w[1] % moder;
	}
	for (int i = 1; i <= len; ++ i){
		for (int j = 0, szk = 1 << i - 1, szw = length >> i; j < length; j += 1 << i){
			for (int k = j, noww = 0; k < j + szk; ++ k, noww += szw){
				int s = a[k], t = 1ll * w[noww] * a[k + szk] % moder;
				a[k] = s + t >= moder ? s + t - moder : s + t;
				a[k + szk] = s - t < 0 ? s - t + moder : s - t;
			}
		}
	}
	delete [] w;
	if (type == 1) return;
	int inv = powermod(length, moder - 2, moder);
	for (int i = 0; i < length; ++ i){
		a[i] = (ll) a[i] * inv % moder;
	}
}

typedef long long ll;

// orz 
class poly{
private:
	int *a;
	int length, size;
	int moder, root, invroot;
	//  ((119 << 23) + 1, 3, 332748118)  ((479 << 21) + 1, 3, 334845270)
	
	void apply(int size){
		if (!size) return;
		a = new int [size]();
		this -> size = size;
	}
	
	void resize(int size){
		if (!size) return;
		int *aux = a;
		a = new int [size]();
		memcpy(a, aux, sizeof(int) * (length + 1));
		if (this -> size) delete [] aux;
		this -> size = size;
	}
	
	void initpoly(const poly &p, int length){
		clear();
		apply(length + 2 << 1);
		memcpy(a, p.a, sizeof(int) * (std::min(length, p.length) + 1));
		this -> length = length;
		moder = p.moder, root = p.root, invroot = p.invroot;
	}

public:
	poly():a(nullptr), length(-1), moder(0), root(0), invroot(0){}
	// NTT root  invroot ~ 
	poly(int length, int moder, int root, int invroot):a(nullptr), length(length), moder(moder), root(root), invroot(invroot){apply(length + 2 << 1);}
	poly(const poly &p):a(nullptr){initpoly(p, p.length);}
	poly(const poly &p, int length):a(nullptr){initpoly(p, length);}
	~poly(){clear();}
	void clear(){delete [] a; a = nullptr; size = length = moder = root = invroot = 0;}
	int &operator [](int n){return a[n];}
	int getlength(){return length;}
	void setmoder(int moder, int root, int invroot){this -> moder = moder, this -> root = root, this -> invroot = invroot;}
	int getmoder(){return moder;}
	
	void setlength(int length){
		if (length >= size) resize(length + 2 << 1);
		if (length >= this -> length){
			this -> length = length;
			return;
		}
		memset(a + length + 1, 0, sizeof(int) * (this -> length - length));
		this -> length = length;
	}
	
	poly &operator = (const poly &p){
		if (&p != this) initpoly(p, p.length);
		return *this;
	}
	
	//  x ^ dis
	poly operator << (const int &dis)const{
		poly ret(length + dis, moder, root, invroot);
		memcpy(ret.a + dis, a, sizeof(int) * (length + 1));
		return ret;
	}
	
	//  x ^ dis
	poly operator >> (const int &dis)const{
		if (dis > length) return poly(-1, moder, root, invroot);
		poly ret(length - dis, moder, root, invroot);
		memcpy(ret.a, a + dis, sizeof(int) * (ret.length + 1));
		return ret;
	}
	
	int value(int x){
		int now = 1, ret = 0;
		for (int i = 0; i <= length; ++ i){
			ret = (ret + 1ll * a[i] * now) % moder;
			now = 1ll * now * x % moder;
		}
		return ret;
	}
	
	poly operator + (const poly &p)const{
		if (!~length) return p;
		if (!~p.length) return *this;
		poly ret(*this, std::max(length, p.length));
		for (int i = 0; i <= p.length; ++ i){
			ret.a[i] += p.a[i];
			ret.a[i] -= ret.a[i] >= moder ? moder : 0;
		}
		for ( ; ~ret.length && !ret.a[ret.length]; -- ret.length)
			;
		return ret;
	}
	
	poly operator - (const poly &p)const{
		if (!~length) return p;
		if (!~p.length) return *this;
		poly ret(*this, std::max(length, p.length));
		for (int i = 0; i <= p.length; ++ i){
			ret.a[i] -= p.a[i];
			ret.a[i] += ret.a[i] < 0 ? moder : 0;
		}
		for ( ; ~ret.length && !ret.a[ret.length]; -- ret.length)
			;
		return ret;
	}
	
	poly operator - ()const{
		poly ret(length, moder, root, invroot);
		for (int i = 0; i <= length; ++ i){
			ret.a[i] = a[i] ? moder - a[i] : 0;
		}
		return ret;
	}
	
	poly operator * (const poly &p)const{
		if (!~length || !~p.length) return poly(-1, moder, root, invroot);
		int n = length + p.length;
		int lengthret = 1;
		for ( ; lengthret <= n; lengthret <<= 1)
			;
		int *aux = new int [lengthret]();
		int *aux1 = new int [lengthret]();
		memcpy(aux, a, sizeof(int) * (length + 1));
		memcpy(aux1, p.a, sizeof(int) * (p.length + 1));
		NTT(aux, lengthret, 1, moder, root);
		NTT(aux1, lengthret, 1, moder, root);
		for (int i = 0; i < lengthret; ++ i){
			aux[i] = 1ll * aux[i] * aux1[i] % moder;
		}
		NTT(aux, lengthret, -1, moder, invroot);
		poly ret(n, moder, root, invroot);
		memcpy(ret.a, aux, sizeof(int) * (n + 1));
		delete [] aux;
		delete [] aux1;
		return ret;
	}
	
	poly operator * (const int &p)const{
		int q = (p % moder + moder) % moder;
		if (!q) return poly(-1, moder, root, invroot);
		poly ret(length, moder, root, invroot);
		for (int i = 0; i <= length; ++ i){
			ret.a[i] = 1ll * a[i] * q % moder;
		}
		return ret;
	}
	
	friend poly operator * (const int &q, const poly &p){return p * q;}
	poly &operator += (const poly &p){*this = *this + p; return *this;}
	poly &operator -= (const poly &p){*this = *this - p; return *this;}
	poly &operator *= (const poly &p){*this = *this * p; return *this;}
	poly &operator *= (const int &p){*this = *this * p; return *this;}
};

const int moder = (119 << 23) + 1;
const int root = 3;
const int invroot = 332748118;
const int N = 200010;

int fac[N], inv[N];

int comb(int n, int m){
	if (m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

poly solve(int l, int r){
	if (l == r){
		poly p(1, moder, root, invroot);
		p[0] = l;
		p[1] = 1;
		return p;
	}
	int mid = l + r >> 1;
	return solve(l, mid) * solve(mid + 1, r);
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2, moder);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * i * inv[i] % moder;
	}
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (!a || !b || a + b - 2 > n - 1){
		puts("0");
		return 0;
	}
	if (n == 1){
		puts("1");
		return 0;
	}
	poly p = solve(0, n - 2);
	int ans = 1ll * p[a + b - 2] * comb(a + b - 2, a - 1) % moder;
	printf("%d\n", ans);
	return 0;
}