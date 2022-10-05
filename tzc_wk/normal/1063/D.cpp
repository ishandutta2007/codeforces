//Created time: 2022/4/5 14:12:14
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
ll n, _l, _r, k, mx = -1;
ll calc(ll _l, ll _r, ll n, ll k, ll limB) {
	ll len = (_l <= _r) ? (_r - _l + 1) : (n - _l + 1 + _r), ret = -1;
	if (len == n) len = 0;
	for (ll l = 1, r; l <= k; l = r + 1) {
		r = k / (k / l);
		if (l > n * 2) break;
		ll L = max(l, n) - n, R = min(r, n * 2) - n;
		if (L <= R) {
			ll x = k / l;
			ll v = k - x * n - len;
			if (v >= 0) {
				ll lim = v / x * x;
				ll A = v - lim;
				if (A <= len) {
					ll B = lim / x - A;
					if (B >= limB) {
						ll nd = 0;
						if (A + B > R) chkmax(nd, A + B - R);
						if (B > n - len) chkmax(nd, (B - (n - len) - 1) / (x + 1) + 1);
						A += nd * x; B -= nd * (x + 1);
						if (A <= len && B >= limB && A + B >= L)
							chkmax(ret, A + B);
					}
				}
			}
		}
	}
	if (k >= len && k <= len * 2) chkmax(ret, k - len + n - len);
	return ret;
}
int main(){
	scanf("%lld%lld%lld%lld", &n, &_l, &_r, &k);
	chkmax(mx, calc(_l, _r, n, k, 0));
	chkmax(mx, calc(_l, (_r + n - 2) % n + 1, n, k - 1, 1));
	printf("%lld\n", mx);
	return 0;
}