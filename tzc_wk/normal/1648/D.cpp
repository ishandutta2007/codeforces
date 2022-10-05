//Created time: 2022/3/6 17:53:19
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
template<typename T1,typename T2> void chkmin(T1 &x, T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x, T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getc();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getc();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getc();
		if(neg) x=(~x)+1;
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
}
using namespace fastio;
#endif
const int MAXN = 5e5;
const int LOG_N = 19;
const ll INFll = 1e18;
int n, qu, a[4][MAXN + 5]; ll sum[4][MAXN + 5];
ll va[MAXN + 5], vb[MAXN + 5];
struct itvl {
	int l, r, k;
	bool operator < (const itvl &rhs) {
		return r < rhs.r;
	}
} q[MAXN + 5];
namespace S1 {
	struct node {int l, r; ll mx;} s[MAXN * 4 + 5];
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; s[k].mx = -INFll; if (l == r) return;
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	}
	void modify(int k, int p, ll v) {
		if (s[k].l == s[k].r) return chkmax(s[k].mx, v), void();
		int mid = s[k].l + s[k].r >> 1;
		(p <= mid) ? modify(k << 1, p, v) : modify(k << 1 | 1, p, v);
		s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx); 
	}
	ll query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].mx;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return max(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
	}
}
ll st[LOG_N + 2][MAXN + 5]; int hib[MAXN + 5];
ll query_st(int l, int r) {
	int k = hib[r - l + 1];
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}
ll dpv[MAXN + 5];
struct dat {
	ll mx1, mx2, mx;
	dat operator + (const dat &rhs) {
		dat ret;
		ret.mx1 = max(mx1, rhs.mx1);
		ret.mx2 = max(mx2, rhs.mx2);
		ret.mx = max(max(mx, rhs.mx), mx1 + rhs.mx2);
		return ret;
	}
};
namespace S2 {
	struct node {int l, r; dat v;} s[MAXN * 4 + 5];
	multiset<ll> vs[MAXN + 5];
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r;
		if (l == r) {
			s[k].v.mx2 = dpv[l]; vs[l].insert(-INFll);
			s[k].v.mx1 = -INFll; s[k].v.mx = dpv[l] - INFll;
			return;
		}
		int mid = l + r >> 1;
		build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		s[k].v = s[k << 1].v + s[k << 1 | 1].v;
	}
	void ins(int k, int p, ll v) {
		if (s[k].l == s[k].r) {
			vs[p].insert(v);
			s[k].v.mx1 = *vs[p].rbegin();
			s[k].v.mx = s[k].v.mx1 + s[k].v.mx2;
			return;
		}
		int mid = s[k].l + s[k].r >> 1;
		if (p <= mid) ins(k << 1, p, v);
		else ins(k << 1 | 1, p, v);
		s[k].v = s[k << 1].v + s[k << 1 | 1].v;
	}
	void del(int k, int p, ll v) {
		if (s[k].l == s[k].r) {
			vs[p].erase(vs[p].find(v));
			s[k].v.mx1 = *vs[p].rbegin();
			s[k].v.mx = s[k].v.mx1 + s[k].v.mx2;
			return;
		}
		int mid = s[k].l + s[k].r >> 1;
		if (p <= mid) del(k << 1, p, v);
		else del(k << 1 | 1, p, v);
		s[k].v = s[k << 1].v + s[k << 1 | 1].v;
	}
	dat query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].v;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
	}
}
namespace S3 {
	struct node {int l, r; dat v;} s[MAXN * 4 + 5];
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r;
		if (l == r) {
			s[k].v.mx1 = va[l], s[k].v.mx2 = vb[l];
			s[k].v.mx = va[l] + vb[l]; return;
		}
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
		s[k].v = s[k << 1].v + s[k << 1 | 1].v;
	}
	dat query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].v;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
	}
}
vector<int> ad[MAXN + 5], dl[MAXN + 5];
int main(){
	for (int i = 2; i <= MAXN; i++) hib[i] = hib[i >> 1] + 1;
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
		for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + a[i][j];
	}
	for (int i = 1; i <= n; i++) va[i] = sum[1][i] - sum[2][i - 1];
	for (int i = 1; i <= n; i++) vb[i] = sum[2][i] + sum[3][n] - sum[3][i - 1];
	for (int i = 1; i <= qu; i++) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
	sort(q + 1, q + qu + 1); S1 :: build(1, 1, n);
	for (int i = 1; i <= n; i++) st[0][i] = va[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++)
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	ll ret = -INFll;
	for (int i = 1; i <= qu; i++) {
		ll dp = query_st(q[i].l, q[i].r) - q[i].k;
		chkmax(dp, S1 :: query(1, max(q[i].l - 1, 1), q[i].r) - q[i].k);
		S1 :: modify(1, q[i].r, dp);
	}
	for (int i = 1; i <= n; i++) dpv[i] = S1 :: query(1, i, i);
	dpv[0] = -INFll; S2 :: build(1, 0, n); S3 :: build(1, 1, n);
	for (int i = 1; i <= qu; i++) chkmax(ret, S3 :: query(1, q[i].l, q[i].r).mx - q[i].k);
	for (int i = 1; i <= qu; i++) ad[q[i].l].pb(i), dl[q[i].r + 1].pb(i);
	for (int i = 1; i <= n; i++) {
		for (int x : ad[i]) S2 :: ins(1, q[x].l - 1, -q[x].k);
		for (int x : dl[i]) S2 :: del(1, q[x].l - 1, -q[x].k);
		dat v = S2 :: query(1, 0, i); chkmax(ret, v.mx + vb[i]);
	}
	for (int i = 1; i <= qu; i++) chkmax(ret, dpv[q[i].l] + vb[q[i].l] - q[i].k);
	printf("%lld\n", ret);
	return 0;
}