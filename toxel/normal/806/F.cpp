#include<bits/stdc++.h>
#define ll long long

ll multmod(ll a, ll b, ll moder){
	a = (a % moder + moder) % moder, b = (b % moder + moder) % moder;
	ll ret = 0;
	for ( ; b; b >>= 1){
		if (b & 1){
			ret = ret + a >= moder ? ret + a - moder : ret + a;
		}
		a = a << 1 > moder ? (a << 1) - moder : a << 1;
	}
	return ret;
}

template <typename T> 
class modequa{
private:
	T remain, moder;
	
public:
	modequa <T>(){}
	modequa <T>(T remain, T moder) : remain(remain), moder(moder){}
	T getremain(){return remain;}
	T getmoder(){return moder;}
	
	void setvalue(T remain, T moder){
		this -> remain = remain;
		this -> moder = moder;
	}
	
	modequa <T> crt(const modequa <T> &p){
		T gcd = moder, x = 1, y = 0;
		for (T b = p.moder, x1 = 0, y1 = 1, r, s; b; ){
			r = x, s = y;
			x = x1, y = y1, x1 = r - x1 * (gcd / b), y1 = s - y1 * (gcd / b);
			r = gcd % b, gcd = b, b = r;
		}
		if ((p.remain - remain) % gcd) return modequa <T>(0, 0);
		T lcm = moder / gcd * p.moder;
		T ans = (p.remain - remain) / gcd;
		ans = multmod(multmod(ans, x, lcm), moder, lcm);
		ans += remain;
		ans += ans < 0 ? lcm : ans >= lcm ? -lcm : 0;
		return modequa <T>(ans, lcm);
	}
};

// orz 
class poly{
private:
	int *a;
	int length, size;
	int moder, root, invroot;
	//  ((119 << 23) + 1, 3, 332748118)  ((479 << 21) + 1, 3, 334845270)

	int powermod(int a, int exp, int moder)const &{
		int ret = 1;
		for ( ; exp; exp >>= 1){
			if (exp & 1){
				ret = 1ll * a * ret % moder;
			}
			a = 1ll * a * a % moder;
		}
		return ret;
	}
	
	void NTT(int *a, int length, int type, int moder, int root)const &{
		int len = -1;
		for (int x = length; x; ++ len, x >>= 1);
		for(int i = 1, j = 0; i < length - 1; ++ i){
			for(int s = length; j ^= s >>= 1, ~j & s; );
			if(i < j){
				std::swap(a[i], a[j]);
			}
		}
		for (int i = 1; i <= len; ++ i){
			int unit = powermod(root, moder - 1 >> i, moder);
			for (int j = 0; j < length; j += 1 << i){
				int w = 1;
				for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
					int s = a[k], t = 1ll * w * a[k + szk] % moder;
					a[k] = s + t >= moder ? s + t - moder : s + t;
					a[k + szk] = s - t < 0 ? s - t + moder : s - t;
					w = 1ll * w * unit % moder;
				}
			}
		}
		if (type == 1) return;
		int inv = powermod(length, moder - 2, moder);
		for (int i = 0; i < length; ++ i){
			a[i] = 1ll * a[i] * inv % moder;
		}
	}
	
	void apply(int size){
		if (!size) return;
		a = new int [size]();
		this -> size = size;
	}
	
	void destroy(){
		if (!size) return;
		delete [] a;
		a = nullptr;
	}
	
	void resize(int size){
		if (!size) return;
		int *aux = a;
		a = new int [size]();
		memcpy(a, aux, sizeof(int) * (length + 1));
		if (this -> size) delete [] aux;
		this -> size = size;
	}

public:
	poly() : length(-1), moder(0), root(0), invroot(0){a = nullptr;}
	// NTT root  invroot ~ 
	poly(int length, int moder, int root, int invroot):length(length), moder(moder), root(root), invroot(invroot){apply(length + 2 << 1);}
	poly(const poly &p):length(p.length), moder(p.moder), root(p.root), invroot(p.invroot){apply(p.size); memcpy(a, p.a, sizeof(int) * (p.length + 1));}
	poly(const poly &p, int length):length(length), moder(p.moder), root(p.root), invroot(p.invroot){apply(length + 2 << 1); memcpy(a, p.a, sizeof(int) * (std::min(length, p.length) + 1));}
	~poly(){destroy();}
	void clear(){destroy(); length = -1, size = moder = root = invroot = 0;}
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
		destroy();
		apply(p.size);
		length = p.length;
		moder = p.moder;
		root = p.root;
		invroot = p.invroot;
		memcpy(a, p.a, sizeof(int) * (length + 1));
		return *this;
	}
	
	//  x ^ dis
	poly operator << (const int &dis)const &{
		poly ret(length + dis, moder, root, invroot);
		memcpy(ret.a + dis, a, sizeof(double) * (length + 1));
		return ret;
	}
	
	//  x ^ dis
	poly operator >> (const int &dis)const &{
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
	
	poly operator + (const poly &p)const &{
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
	
	poly operator - (const poly &p)const &{
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
	
	poly operator - ()const &{
		poly ret(length, moder, root, invroot);
		for (int i = 0; i <= length; ++ i){
			ret.a[i] = a[i] ? moder - a[i] : 0;
		}
		return ret;
	}
	/*&
	poly operator * (const poly &p)const &{
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
	}*/
	
	///*-------------------- NTT~ ------------------------------
	poly operator *(const poly &p)const &{
		const int multmoder[2] = {(119 << 23) + 1, (479 << 21) + 1};
		const int multroot[2] = {3, 3};
		const int multinvroot[2] = {332748118, 334845270};
		if (!~length || !~p.length) return poly(-1, moder, root, invroot);
		int n = length + p.length;
		int lengthret = 1;
		for ( ; lengthret <= n; lengthret <<= 1)
			;
		int *aux = new int [lengthret]();
		int *aux1 = new int [lengthret]();
		int *aux2 = new int [lengthret]();
		memcpy(aux, a, sizeof(int) * (length + 1));
		memcpy(aux2, p.a, sizeof(int) * (p.length + 1));
		NTT(aux, lengthret, 1, multmoder[0], multroot[0]);
		NTT(aux2, lengthret, 1, multmoder[0], multroot[0]);
		for (int i = 0; i < lengthret; ++ i){
			aux[i] = 1ll * aux[i] * aux2[i] % multmoder[0];
		}
		NTT(aux, lengthret, -1, multmoder[0], multinvroot[0]);
		memcpy(aux1, a, sizeof(int) * (length + 1));
		memset(aux2, 0, sizeof(int) * lengthret);
		memcpy(aux2, p.a, sizeof(int) * (p.length + 1));
		NTT(aux1, lengthret, 1, multmoder[1], multroot[1]);
		NTT(aux2, lengthret, 1, multmoder[1], multroot[1]);
		for (int i = 0; i < lengthret; ++ i){
			aux1[i] = 1ll * aux1[i] * aux2[i] % multmoder[1];
		}
		NTT(aux1, lengthret, -1, multmoder[1], multinvroot[1]);
		poly ret(n, moder, root, invroot);
		for(int i = 0; i <= n; ++ i){
			modequa <ll> equa(aux[i], multmoder[0]), equb(aux1[i], multmoder[1]);
			ret.a[i] = equa.crt(equb).getremain() % moder;
		}
		delete [] aux;
		delete [] aux1;
		delete [] aux2;
		return ret;
	}
	//----------------------------------------------------------------------------------------*/
	
	poly operator * (const int &p)const &{
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

const int N = 100;

int maxn, maxa, moder;
int q[N];

int main(){
	scanf("%d%d%d", &maxn, &maxa, &moder);
	if (maxa == 1){
		return printf("0\n"), 0;
	}
	int cnt = 0;
	for (maxa >>= 1; maxa; maxa >>= 1){
		q[cnt ++] = maxa;
	}
	std::reverse(q, q + cnt);
	int ans = 1;
	poly a(maxn, moder, 0, 0);
	poly b(maxn, moder, 0, 0);
	a[0] = 1;
	b[1] = 1;
	for (int i = 0; i < cnt - 1; ++ i){
		poly ret1(a);
		ret1 = (ret1 + b) * (q[i] & 1 ? b : a);
		if (q[i] & 1 ? b[0] : a[0]){
			ret1 -= b;
		}
		else{
			ret1 += a;
		}
		ret1.setlength(maxn);
		poly ret2(a);
		ret2 = (ret2 + b) * (q[i] & 1 ? a : b);
		if (q[i] & 1 ? a[0] : b[0]){
			ret2 -= a;
		}
		else{
			ret2 += b;
		}
		ret2.setlength(maxn);
		if (q[i + 1] & 1){
			a = ret1;
			for (int i = 1; i <= maxn; ++ i){
				b[i] = (ret2[i] + ret1[i - 1] + ret2[i - 1]) % moder;
			}
		}
		else{
			a = ret1;
			b = ret2;
		}
		for (int i = 1; i <= maxn; i += 2){
			ans = (ans + b[i]) % moder;
		}
	}
	return printf("%d\n", ans), 0;
}