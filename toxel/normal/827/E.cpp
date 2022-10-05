#include<bits/stdc++.h>

const double PI = acos(-1.0);
const double eps = 1e-6;

void FFT(std::complex <double> *a, int length, int type){
	std::complex <double> *w[2];
	w[0] = new std::complex <double> [length], w[1] = new std::complex <double> [length];
	for (int i = 0; i < length; ++ i){
		double cospart = cos(1.0 * i / (length >> 1) * PI), sinpart = sin(1.0 * i / (length >> 1) * PI);
		w[0][i] = std::complex <double>(cospart, -sinpart);
		w[1][i] = std::complex <double>(cospart, sinpart);
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
				std::complex <double> s = a[k], t = w[!~type][noww] * a[k + szk];
				a[k] = s + t, a[k + szk] = s - t;
			}
		}
	}
	delete [] w[0];
	delete [] w[1];
	if (type == 1) return;
	for (int i = 0; i < length; ++ i){
		a[i] /= length;
	}
}

const int N = 1 << 21;

int n;
char s[N];
std::complex <double> a[N], b[N];

int main(){
	int test;
	scanf("%d", &test);
	while (test --){
		scanf("%d%s", &n, &s);
		int len = n << 1;
		int lengthret = 1;
		for ( ; lengthret < len; lengthret <<= 1)
			;
		for (int i = 0; i < n; ++ i){
			if (s[i] == 'V'){
				a[i] = std::complex <double>(1, 0);
			}
			else if (s[i] == 'K'){
				a[i] = std::complex <double>(0, 1);
			}
		}
		for (int i = 0; i < n; ++ i){
			b[i] = a[n - 1 - i];
		}
		FFT(a, lengthret, 1);
		FFT(b, lengthret, 1);
		for (int i = 0; i < lengthret; ++ i){
			a[i] *= b[i];
		}
		FFT(a, lengthret, -1);
		std::vector <int> ans;
		for (int i = 1; i < n; ++ i){
			bool flag = true;
			for (int j = i; j < n; j += i){
				if (a[n - 1 - j].imag() > eps){
					flag = false;
					break;
				}
			}
			if (flag){
				ans.push_back(i);
			}
		}
		ans.push_back(n);
		printf("%d\n", (int) ans.size());
		for (auto u : ans){
			printf("%d ", u);
		}
		putchar('\n');
		for (int i = 0; i < lengthret; ++ i){
			a[i] = b[i] = std::complex <double>(0, 0);
		}
	}
	return 0;
}