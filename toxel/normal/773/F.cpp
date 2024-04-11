#include<bits/stdc++.h>
#define ll long long

const int N = 100;
const double PI = acos(-1);

int moder;

struct Poly{
	const static int MAX = 17;
	
	int a[1 << MAX];
	int length;
	
	Poly () : length(-1){
		memset(a, 0, sizeof(a));
	}
	
	void setlength(int length){
		if (length >= this -> length){
			this -> length = length;
			return;
		}
		memset(a + length + 1, 0, sizeof(int) * (this -> length - length));
		this -> length = length;
	}
	
	void clear(){
		memset(a, 0, sizeof(int) * (length + 1));
		length = -1;
	}
};

void assign(Poly &p, Poly &q){
	memset(p.a, 0, sizeof(int) * (p.length + 1));
	memcpy(p.a, q.a, sizeof(int) * (q.length + 1));
	p.length = q.length;
}

void add(Poly &p, Poly &q){
	if (!~p.length){
		p = q;
		return;
	}
	if (!~q.length){
		return;
	}
	p.length = std::max(p.length, q.length);
	for (int i = 0; i <= p.length; ++ i){
		p.a[i] = (p.a[i] + q.a[i]) % moder;
	}
	for ( ; ~p.length && !p.a[p.length]; -- p.length);
}

void minus(Poly &p, Poly &q){
	if (!~p.length){
		p = q;
		return;
	}
	if (!~q.length){
		return;
	}
	p.length = std::max(p.length, q.length);
	for (int i = 0; i <= p.length; ++ i){
		p.a[i] = (p.a[i] - q.a[i] + moder) % moder;
	}
	for ( ; ~p.length && !p.a[p.length]; -- p.length);
}

void FFT(std::complex <double> *a, int length, int type){
	static std::complex <double> w[2][1 << Poly::MAX];
	if (std::abs(w[0][0].real()) < 1e-8){
		for (int i = 0; i < 1 << Poly::MAX; ++ i){
			w[0][i] = std::complex <double>(cos(i * PI / (1 << Poly::MAX - 1)), -sin(i * PI / (1 << Poly::MAX - 1)));
			w[1][i] = std::complex <double>(cos(i * PI / (1 << Poly::MAX - 1)), sin(i * PI / (1 << Poly::MAX - 1)));
		}
	}
	int len = -1;
	for (int x = length; x; ++ len, x >>= 1)
		;
	for (int i = 1, j = 0; i < length - 1; ++ i){
		for (int s = length; j ^= s >>= 1, ~j & s; )
			;
		if (i < j){
			std::swap(a[i], a[j]);
		}
	}
	for (int i = 1; i <= len; ++ i){
		for (int j = 0, szk = 1 << i - 1, szw = 1 << Poly::MAX - i; j < length; j += 1 << i){
			for (int k = j, noww = 0; k < j + szk; ++ k, noww += szw){
				std::complex <double> s = a[k], t = w[!~type][noww] * a[k + szk];
				a[k] = s + t, a[k + szk] = s - t;
			}
		}
	}
	if (type == 1) return;
	for (int i = 0; i < length; ++ i){
		a[i] /= length;
	}
}

void mult(Poly &p, Poly &q){
	static std::complex <double> a[1 << Poly::MAX];
	static std::complex <double> b[1 << Poly::MAX];
	int n = p.length + q.length;
	int length = 1;
	for ( ; length <= n; length <<= 1)
		;
	for (int i = 0; i < length; ++ i){
		a[i] = p.a[i];
		b[i] = q.a[i];
	}
	FFT(a, length, 1);
	FFT(b, length, 1);
	for (int i = 0; i < length; ++ i){
		a[i] *= b[i];
	}
	FFT(a, length, -1);
	for (int i = 0; i <= n; ++ i){
		p.a[i] = (ll) (a[i].real() + 0.3) % moder;
	}
	p.length = n;
}

int maxn, maxa;
Poly a, b, ret1, ret2;
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
	a.a[0] = b.a[1] = 1;
	a.length = b.length = maxn;
	for (int i = 0; i < cnt - 1; ++ i){
		assign(ret1, a);
		add(ret1, b);
		mult(ret1, q[i] & 1 ? b : a);
		if (q[i] & 1 ? b.a[0] : a.a[0]){
			minus(ret1, b);
		}
		else{
			add(ret1, a);
		}
		ret1.setlength(maxn);
		assign(ret2, a);
		add(ret2, b);
		mult(ret2, q[i] & 1 ? a : b);
		if (q[i] & 1 ? a.a[0] : b.a[0]){
			minus(ret2, a);
		}
		else{
			add(ret2, b);
		}
		ret2.setlength(maxn);
		if (q[i + 1] & 1){
			for (int i = 1; i <= maxn; ++ i){
				a.a[i] = ret1.a[i];
			}
			for (int i = 1; i <= maxn; ++ i){
				b.a[i] = (ret2.a[i] + ret1.a[i - 1] + ret2.a[i - 1]) % moder;
			}
		}
		else{
			assign(a, ret1);
			assign(b, ret2);
		}
		for (int i = 1; i <= maxn; ++ i){
			if (i & 1){
				ans = (ans + b.a[i]) % moder;
			}
		}
	}
	return printf("%d\n", ans), 0;
}