//Created time: 2022/3/25 14:32:44
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
int n, a[MAXN + 5], f[MAXN + 5]; vector<int> occ[MAXN + 5], cyc[MAXN + 5];
int P1[MAXN + 5], P2[MAXN + 5], res[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x ^ y) f[x] = y;}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) f[i] = 0, occ[i].clear(), cyc[i].clear();
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), occ[a[i]].pb(i);
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += (occ[i].size() & 1);
	if (sum >= 2) return puts("NO"), void();
	if ((n & 1) && (occ[a[n + 1 >> 1]].size() == 1)) return puts("NO"), void();
	puts("YES");
	for (int i = 1; i <= n; i++) if (occ[i].size() & 1) {
		for (int j = 0; j < occ[i].size(); j++) if (occ[i][j] != (n + 1 >> 1)) {
			P1[n + 1 >> 1] = occ[i][j];
			occ[i].erase(occ[i].begin() + j);
			break;
		}
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < occ[i].size(); j += 2)
		cur++, P1[cur] = occ[i][j], P1[n - cur + 1] = occ[i][j + 1];
//	for (int i = 1; i <= n; i++) printf("%d%c", P1[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) P2[i] = P1[i], merge(i, P1[i]);
	for (int i = 1; i <= (n >> 1); i++) {
		if (find(i) != find(n - i + 1)) {
			swap(P2[i], P2[n - i + 1]);
			merge(i, n - i + 1);
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d%c", P2[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) cyc[find(i)].pb(i);
	for (int i = 1; i <= n; i++) res[i] = P2[i];
	vector<int> ind;
	for (int i = 1; i <= n; i++) if (!cyc[i].empty()) {
		for (int x : cyc[i]) {
			if ((~n & 1) || (x != (n + 1 >> 1))) {
				ind.pb(x); break;
			}
		}
	}
	ind.pb(ind[0]);
	for (int i = 1; i < ind.size(); i++) {
		if (i != ind.size() - 1) {
			res[ind[i]] = P2[n - ind[i - 1] + 1];
			res[n - ind[i] + 1] = P2[ind[i - 1]];
		} else {
			res[ind[i]] = P2[ind[i - 1]];
			res[n - ind[i] + 1] = P2[n - ind[i - 1] + 1];
		}
	}
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
}
int main(){
	int qu; scanf("%d", &qu);
	while (qu--) solve();	
	return 0;
}