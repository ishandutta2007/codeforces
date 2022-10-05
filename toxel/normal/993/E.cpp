#include<bits/stdc++.h>

const double PI = acos(-1.0);

void FFT(std::complex <double> *a, int length, int type){
	std::complex <double> *w = new std::complex <double> [length];
	for (int i = 0; i < length; ++ i){
		double angle = 1.0 * i / (length >> 1) * PI;
		w[i] = std::complex <double>(cos(angle), type * sin(angle));
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
		for (int j = 0, szk = 1 << i - 1, szw = length >> i; j < length; j += 1 << i){
			for (int k = j, noww = 0; k < j + szk; ++ k, noww += szw){
				std::complex <double> s = a[k], t = w[noww] * a[k + szk];
				a[k] = s + t, a[k + szk] = s - t;
			}
		}
	}
	delete [] w;
	if (type == 1) return;
	for (int i = 0; i < length; ++ i){
		a[i] /= length;
	}
}

typedef long long ll;
const int N = 1000010;

ll ret[N];

void mult(int *a, int *b, int lena, int lenb){
	int n = lena + lenb;
	int lengthret = 1;
	for ( ; lengthret <= n; lengthret <<= 1)
		;
	std::complex <double> *aux = new std::complex <double> [lengthret];
	std::complex <double> *aux1 = new std::complex <double> [lengthret];
	for (int i = 0; i < lengthret; ++ i){
		aux[i] = i > lena ? 0 : a[i];
		aux1[i] = i > lenb ? 0 : b[i];
	}
	FFT(aux, lengthret, 1);
	FFT(aux1, lengthret, 1);
	for (int i = 0; i < lengthret; ++ i){
		aux[i] *= aux1[i];
	}
	FFT(aux, lengthret, -1);
	for (int i = 0; i <= n; ++ i){
		ret[i] = (ll) (aux[i].real() + 0.5);
	}
	delete [] aux;
	delete [] aux1;
}


int a[N], b[N], c[N];
	
int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0, y; i < n; ++ i){
        scanf("%d", &y);
        a[i] = y < x;
    }
    int pre = -1, cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        if (a[i] == 1){
            b[cnt ++] = i - pre;
            ans += 1ll * (i - pre) * (i - pre - 1) / 2;
            pre = i;
        }
    }
    b[cnt ++] = n - pre;
    ans += 1ll * (n - pre) * (n - pre - 1) / 2;
    for (int i = 0; i < cnt; ++ i){
        c[cnt - i - 1] = b[i];
    }
    mult(b, c, cnt - 1, cnt - 1);
    printf("%lld ", ans);
    for (int i = 1; i <= n; ++ i){
        printf("%lld%c", ret[i + cnt - 1], " \n"[i == n]);
    }
    return 0;
}