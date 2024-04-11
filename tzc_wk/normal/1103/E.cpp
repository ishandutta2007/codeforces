//Created time: 2022/4/2 8:41:20
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
const int MAXN = 1e5;
const u64 MOD = 1ll << 58;
u64 qpow(u64 x, u64 e) {
	u64 ret = 1;
	for (; e; e >>= 1, x = x * x) if (e & 1) ret = ret * x;
	return ret;
}
const u64 INV3125 = qpow(3125, (1ull << 63) - 1);
int n;
struct comp {
	u64 a[5];
	comp() {a[0] = a[1] = a[2] = a[3] = a[4] = 0;}
	void clear() {memset(a, 0, sizeof(a));}
	friend comp operator + (const comp &X, const comp &Y) {
		comp ret;
		for (int i = 0; i < 5; i++) ret.a[i] = X.a[i] + Y.a[i];
		return ret;
	}
	friend comp operator - (const comp &X, const comp &Y) {
		comp ret;
		for (int i = 0; i < 5; i++) ret.a[i] = X.a[i] - Y.a[i];
		return ret;
	}
	friend comp operator * (const comp &X, const comp &Y) {
		comp ret;
		for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
			ret.a[(i + j) % 5] += X.a[i] * Y.a[j];
		return ret;
	}
	friend comp operator * (const comp &X, const u64 &Y) {
		comp ret;
		for (int i = 0; i < 5; i++) ret.a[i] = X.a[i] * Y;
		return ret;
	}
} W[10], A[MAXN + 5];
comp qpow_comp(comp x, int e) {
	comp ret; ret.a[0] = 1;
	for (; e; e >>= 1, x = x * x) if (e & 1) ret = ret * x;
	return ret;
}
void FFT(comp *a, int len, int type) {
	for (int i = 1; i < len; i *= 10) {
		for (int j = 0; j < len; j += i * 10) {
			for (int k = 0; k < i; k++) {
				static comp b[10];
				for (int l = 0; l < 10; l++) b[l] = a[i * l + j + k], a[i * l + j + k].clear();
				for (int x = 0; x < 10; x++) for (int y = 0; y < 10; y++)
					a[i * x + j + k] = a[i * x + j + k] + b[y] * W[(x * y * type % 10 + 10) % 10];
			}
		}
	}
	if (type < 0) {
		for (int i = 0; i < len; i++)
			a[i] = a[i] * INV3125;
	}
}
int main(){
	W[0].a[0] = 1; W[1].a[3] = -1;
	for (int i = 2; i < 10; i++) W[i] = W[i - 1] * W[1];
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), A[x].a[0]++;
	FFT(A, MAXN, 1);
//	cerr << INV3125 << endl;
	for (int i = 0; i < MAXN; i++) A[i] = qpow_comp(A[i], n);
	FFT(A, MAXN, -1);
	for (int i = 0; i < n; i++) printf("%llu\n", (A[i].a[0] - A[i].a[4]) / 32 % MOD);
	return 0;
}