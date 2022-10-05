//Created time: 2022/3/25 16:21:54
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
typedef __int128_t i128;
const int MAXN = 1000;
int n, m; i128 a[MAXN + 5], b[MAXN + 5], c[MAXN + 5][MAXN + 5];
void read(i128 &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
void print(i128 x) {if (!x) return; print(x / 10); putchar(x % 10 + '0');}
void print(i128 x, char c) {print(x); putchar(c);}
i128 _gcd(i128 x, i128 y) {return (!y) ? x : _gcd(y, x % y);}
struct segtree {
	int op;
	i128 val[MAXN * 4 + 5];
	void build(int k, int l, int r) {
		if (l == r) {
			val[k] = (op > 0) ? (a[op] / c[op][l]) : (b[-op] / c[l][-op]);
			return;
		}
		int mid = l + r >> 1;
		build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		val[k] = _gcd(val[k << 1], val[k << 1 | 1]);
	}
	void modify(int k, int l, int r, int p) {
		if (l == r) return val[k] = 0, void(); int mid = l + r >> 1;
		if (p <= mid) modify(k << 1, l, mid, p);
		else modify(k << 1 | 1, mid + 1, r, p);
		val[k] = _gcd(val[k << 1], val[k << 1 | 1]);
	}
} A[MAXN + 5], B[MAXN + 5];
bool bana[MAXN + 5], banb[MAXN + 5];
void solve() {
	scanf("%d%d", &n, &m);
	memset(bana, 0, sizeof(bana)); memset(banb, 0, sizeof(banb));
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= m; i++) read(b[i]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		c[i][j] = _gcd(a[i], b[j]);
	for (int i = 1; i <= n; i++) {A[i].op = i; A[i].build(1, 1, m);}
	for (int i = 1; i <= m; i++) {B[i].op = -i; B[i].build(1, 1, n);}
	while (1) {
		int id = 0;
		for (int i = 1; i <= n; i++) if (!bana[i] && A[i].val[1] > 1) id = i;
		for (int i = 1; i <= m; i++) if (!banb[i] && B[i].val[1] > 1) id = -i;
		if (id != 0) {
			if (id > 0) {
				bana[id] = 1;
				for (int i = 1; i <= m; i++) if (!banb[i])
					B[i].modify(1, 1, n, id);
			} else {
				banb[-id] = 1;
				for (int i = 1; i <= n; i++) if (!bana[i])
					A[i].modify(1, 1, m, -id);
			}
		} else break;
	}
	int suma = 0, sumb = 0;
	for (int i = 1; i <= n; i++) if (!bana[i]) suma++;
	for (int i = 1; i <= m; i++) if (!banb[i]) sumb++;
	if (!suma || !sumb) puts("NO");
	else {
		puts("YES"); printf("%d %d\n", suma, sumb);
		for (int i = 1; i <= n; i++) if (!bana[i]) print(a[i], ' ');
		putchar('\n');
		for (int i = 1; i <= m; i++) if (!banb[i]) print(b[i], ' ');
		putchar('\n');
	}
}
int main(){
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}