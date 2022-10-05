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
const int MAXN = 5e5;
int n, a[MAXN + 5], dp[MAXN + 5];
ll sum[MAXN + 5], key[MAXN + 5], uni[MAXN + 5], num;
struct fenwick {
	int t[MAXN + 5];
	void init() {for (int i = 0; i <= n + 1; i++) t[i] = -1e9;}
	void add(int x, int v) {for (int i = x; i <= n + 1; i += (i & (-i))) chkmax(t[i], v);}
	int query(int x) {int ret = -1e9; for (int i = x; i; i &= (i - 1)) chkmax(ret, t[i]); return ret;}
} T1, T2;
int get(ll v) {return lower_bound(uni + 1, uni + num + 1, v) - uni;}
void ins(int x) {T1.add(get(sum[x]), dp[x] - x); T2.add(get(sum[x]), dp[x]);}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	for (int i = 0; i <= n; i++) key[i + 1] = sum[i]; num = 0;
	sort(key + 1, key + n + 2); key[0] = -1e18;
	for (int i = 1; i <= n + 1; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= n; i++) dp[i] = -1e9; dp[0] = 0;
	T1.init(); T2.init(); ins(0);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] - 1;
		chkmax(dp[i], T1.query(get(sum[i]) - 1) + i);
		chkmax(dp[i], T2.query(get(sum[i])));
		ins(i);
	}
	printf("%d\n", dp[n]);
}
int main(){
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}