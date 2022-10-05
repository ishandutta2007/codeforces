// FFT
// 
//  O(nmlognm)

#include<bits/stdc++.h>

const int MAX = 11;
const double PI = acos(-1);
const double eps = 1e-9;

void FFT(std::complex <double> *a, int length, int type){
	static std::complex <double> w[2][1 << MAX];
	if (std::abs(w[0][0].real()) < eps){
		for (int i = 0; i < 1 << MAX; ++ i){
			double cospart = cos(1.0 * i / (1 << MAX - 1) * PI), sinpart = sin(1.0 * i / (1 << MAX - 1) * PI);
			w[0][i] = std::complex <double>(cospart, -sinpart);
			w[1][i] = std::complex <double>(cospart, sinpart);
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
		for (int j = 0, szk = 1 << i - 1, szw = 1 << MAX - i; j < length; j += 1 << i){
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

void FFT_2D(std::complex <double> (*a)[1 << MAX], int lengthx, int lengthy, int type){
	for (int i = 0; i < lengthx; ++ i){
		FFT(a[i], lengthy, type);
	}
	for (int i = 0, sz = std::max(lengthx, lengthy); i < sz; ++ i){
		for (int j = i + 1; j < sz; ++ j){
			std::swap(a[i][j], a[j][i]);
		}
	}
	for (int i = 0; i < lengthy; ++ i){
		FFT(a[i], lengthx, type);
	}
}

// a[i][j] a  (x^i)*(y^j) 
// lengthax  x lengthay  y 
//  a  
void mult(std::complex <double> (*a)[1 << MAX], int lengthax, int lengthay, std::complex <double> (*b)[1 << MAX], int lengthbx, int lengthby){
	static std::complex <double> aux[2][1 << MAX][1 << MAX];
	memset(aux, 0, sizeof(aux));
	int lengthx = 1, lengthy = 1, nx = lengthax + lengthbx - 1, ny = lengthay + lengthby - 1;
	for ( ; lengthx < nx; lengthx <<= 1)
		;
	for ( ; lengthy < ny; lengthy <<= 1)
		;
	for (int i = 0; i < lengthax; ++ i){
		for (int j = 0; j < lengthay; ++ j){
			aux[0][i][j] = a[i][j];
		}
	}
	for (int i = 0; i < lengthbx; ++ i){
		for (int j = 0; j < lengthby; ++ j){
			aux[1][i][j] = b[i][j];
		}
	}
	FFT_2D(aux[0], lengthx, lengthy, 1);
	FFT_2D(aux[1], lengthx, lengthy, 1);
	for (int i = 0; i < lengthy; ++ i){
		for (int j = 0; j < lengthx; ++ j){
			aux[0][i][j] *= aux[1][i][j];
		}
	}
	FFT_2D(aux[0], lengthy, lengthx, -1);
	for (int i = 0; i < nx; ++ i){
		for (int j = 0; j < ny; ++ j){
			a[i][j] = aux[0][i][j];
		}
	}
}

std::complex <double> a[1 << MAX][1 << MAX], b[1 << MAX][1 << MAX];
int n, m, r, c;
char s[1 << MAX][1 << MAX];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			a[i][j] = std::complex <double> {sin(2 * PI * s[i][j] / 26), cos(2 * PI * s[i][j] / 26)};
		}
	}
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++ i){
		scanf("%s", s[i]);
	}
	int cnt = 0;
	for (int i = 0; i < r; ++ i){
		for (int j = 0; j < c; ++ j){
			b[r - i - 1][c - j - 1] = s[i][j] == '?' ? ++ cnt, 0 : std::complex <double> {sin(2 * PI * s[i][j] / 26), -cos(2 * PI * s[i][j] / 26)};
		}
	}
	for (int i = 0; i < 1 << MAX - 1; ++ i){
		for (int j = 0; j < 1 << MAX - 1; ++ j){
			a[i][j] = a[i % n][j % m];
		}
	}
	mult(a, 1 << MAX - 1, 1 << MAX - 1, b, r, c);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			putchar(std::abs(r * c - cnt - a[i + r - 1][j + c - 1].real()) < eps ? '1' : '0');
		}
		putchar('\n');
	}
	return 0;
}