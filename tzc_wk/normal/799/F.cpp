//Created time: 2022/4/1 18:24:21
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
const u64 BS1 = 1004535809;
const u64 BS2 = 19260817;
const u64 V1 = 1234567891011121314ull;
const u64 V2 = 233333333333333333ull;
int n, m, sum[MAXN + 5];
u64 hs1[MAXN + 5], hs2[MAXN + 5]; ll res = 0;
map<pair<u64, u64>, vector<int> > occ;
ll work(vector<int> vec) {
	ll ss = 0;
	for (int i = 1; i < vec.size(); i++)
		ss += 1ll * (vec[i] - vec[i - 1]) * i * (vec.size() - i);
	ss += 1ll * vec.size() * (vec.size() + 1) / 2;
	return ss;
}
ll calc() {
	ll sum = 0;
	for (auto p : occ) sum += work(p.se);
	return sum;
}
int main(){
	scanf("%d%d", &n, &m); u64 pw1 = 1, pw2 = 1;
	for (int i = 1, l, r; i <= n; i++) {
		scanf("%d%d", &l, &r); pw1 *= BS1; pw2 *= BS2;
		u64 H1 = pw1 + V1, H2 = pw2 + V2;
		hs1[l + 1] ^= H1; hs1[r + 1] ^= H1;
		hs2[l + 1] ^= H2; hs2[r + 1] ^= H2;
		sum[l]++; sum[r + 1]--;
	}
	for (int i = 1; i <= m; i++) hs1[i] ^= hs1[i - 1], hs2[i] ^= hs2[i - 1], sum[i] += sum[i - 1];
	for (int i = 1; i <= m; i++) hs1[i] ^= hs1[i - 1], hs2[i] ^= hs2[i - 1];
	for (int i = 1; i <= m; i++) occ[mp(hs1[i], hs2[i])].pb(i);
	res = calc();
	for (int l = 1, r; l <= m; l = r) {
		if (sum[l]) r = l + 1;
		else {
			r = l; while (r <= m && !sum[r]) ++r; occ.clear();
			for (int i = l; i < r; i++) occ[mp(hs1[i], hs2[i])].pb(i);
			res -= calc();
		}
	}
	printf("%lld\n", res);
	return 0;
}