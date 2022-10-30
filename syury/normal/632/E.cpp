#include<bits/stdc++.h>

using namespace std;

typedef double fftdbl;

const fftdbl fftpi = acos(-1.0);

struct base{
	fftdbl re, im;
	base(){}
	base(fftdbl _re, fftdbl _im):re(_re), im(_im){}
	base operator + (const base & a)const{return base(re + a.re, im + a.im);}
	base operator - (const base & a)const{return base(re - a.re, im - a.im);}
	base operator * (const base & a)const{return base(re * a.re - im * a.im, re * a.im + im * a.re);}
	base operator / (const fftdbl & val)const{return base(re / val, im / val);}
};

vector<base> root_pw[30];
vector<base> root_inv_pw[30];

void FFT_prepare(int max_lg){
	for(int i = max_lg; i >= 1; i--){
		root_pw[i].resize(1<<(i - 1));
		fftdbl ang = 2 * fftpi / (1<<i);
		base root(cos(ang), sin(ang));
		base w(1, 0);
		for(int j = 0; j < (int)root_pw[i].size(); j++){
			root_pw[i][j] = w;
			w = w * root;
		}
	}
	for(int i = max_lg; i >= 1; i--){
		root_inv_pw[i].resize(1<<(i - 1));
		fftdbl ang = -2 * fftpi / (1<<i);
		base root(cos(ang), sin(ang));
		base w(1, 0);
		for(int j = 0; j < (int)root_inv_pw[i].size(); j++){
			root_inv_pw[i][j] = w;
			w = w * root;
		}
	}
}

void FFT(base * from, base * to, bool inv){
	int n = to - from;
	int lg = __builtin_ctz(n);
	for(int i = 0; i < n; i++){
		int rev = 0;
		int k = lg - 1;
		for(int j = 0; j < lg; j++){
			rev |= i&(1<<j) ? 1<<k : 0;
			--k;
		}
		if(i < rev)swap(*(from + i), *(from + rev));
	}
	lg = 0;
	for(int len = 2; len <= n; len <<= 1){
		++lg;
		vector<base> & w = inv ? root_inv_pw[lg] : root_pw[lg];
		for(int i = 0; i < n; i += len){
			base *l = from + i, *r = from + i + len/2;
			for(int j = 0; j < len/2; j++){
				base u = *l, v = *r * w[j];
				*l = u + v;
				*r = u - v;
				++l; ++r;
			}
		}
	}
	if(inv)
		for(base * curr = from; curr != to; curr++)
			*curr = *curr / n;
}

const int maxw = 1<<21;

base kek[1<<21];
base curr[1<<21];
int a[1003];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	FFT_prepare(21);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		curr[a[i]] = base(1, 0);
	int asz = 1<<10;
	kek[0] = base(1, 0);
	while(k){
		asz <<= 1;
		FFT(curr, curr + asz, false);
		if(k&1){
			FFT(kek, kek + asz, false);
			for(int i = 0; i < asz; i++)
				kek[i] = kek[i] * curr[i];
			FFT(kek, kek + asz, true);
			for(int i = 0; i < asz; i++){
				kek[i].im = 0;
				kek[i].re = int(kek[i].re + 0.5);
				if(kek[i].re > 0.1)kek[i].re = 1;
			}
		}
		for(int i = 0; i < asz; i++)
			curr[i] = curr[i] * curr[i];
		FFT(curr, curr + asz, true);
		for(int i = 0; i < asz; i++){
			curr[i].im = 0;
			curr[i].re = int(curr[i].re + 0.5);
			if(curr[i].re > 0.1)curr[i].re = 1;
		}
		k >>= 1;
	}
	for(int i = 1; i < maxw; i++)
		if(int(kek[i].re + 0.5) != 0)
			printf("%d ", i);
}