//Created time: 2022/4/19 22:37:22
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN = 2e5;
const int MAXP = 1 << 19;
const int pr = 3;
const int ipr = 332748118;
const int MOD = 998244353;
int n, lim, fac[MAXN + 5], ifac[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % MOD;
	}
}
int qpow(int x, int e) {
	int ret = 1;
	for(; e; e >>= 1, x = 1ll * x * x % MOD) if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int rev[MAXP + 5];
void NTT(vector<int> &a, int len, int type) {
	int lg = 31 - __builtin_clz(len);
	for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg - 1);
	for (int i = 0; i < len; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 2; i <= len; i <<= 1) {
		int W = qpow((type < 0) ? ipr : pr, (MOD - 1) / i);
		for (int j = 0; j < len; j += i) {
			for (int k = 0, w = 1; k < (i >> 1); k++, w = 1ll * w * W % MOD) {
				int X = a[j + k], Y = 1ll * a[(i >> 1) + j + k] * w % MOD;
				a[j + k] = (X + Y) % MOD; a[(i >> 1) + j + k] = (X - Y + MOD) % MOD;
			}
		}
	}
	if (!~type) {
		int iv = qpow(len,MOD-2);
		for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * iv % MOD;
	}
}
vector<int> conv(vector<int> a, vector<int> b){
	int LEN = 1; while (LEN < a.size() + b.size()) LEN <<= 1;
	a.resize(LEN, 0); b.resize(LEN, 0); NTT(a, LEN, 1); NTT(b, LEN, 1);
	for (int i = 0; i < LEN; i++) a[i] = 1ll * a[i] * b[i] % MOD;
	NTT(a, LEN, -1); return a;
}
int binom(int n, int k) {return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;}
int F[MAXN + 5], sf[MAXN + 5];
int main() {
	scanf("%d", &n); lim = n + 1 >> 1; init_fac(MAXN);
	vector<int> A(n + 1), B(n + 1);
	for (int k = lim; k < n; k++) B[n - k - 1] = fac[n - k - 1];
	for (int k = 0; k <= n; k++) A[k] = ifac[k];
	reverse(A.begin(), A.end());
	vector<int> C = conv(A, B);
	for (int i = 2; i <= lim; i++) {
		int coef = 1ll * fac[n - i] * C[n + i - 2] % MOD;
		F[i] = (F[i] + coef) % MOD;
	}
	for (int i = n; i; i--) sf[i] = (sf[i + 1] + F[i]) % MOD;
	for (int i = 1; i <= n; i++) {
		int sum = fac[n - 1];
		sum = (sum - sf[i + 1] + MOD) % MOD;
		if (i != 1) sum = (sum - (fac[n - 1] - 1ll * F[i] * (i - 1) % MOD + MOD) % MOD + MOD) % MOD;
		printf("%d%c", sum, " \n"[i == n]);
	}
	return 0;
}