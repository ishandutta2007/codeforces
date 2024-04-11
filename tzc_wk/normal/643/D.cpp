//Created time: 2022/3/27 23:22:33
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
const int MAXN=1e5;
int n,qu,f[MAXN+5],deg[MAXN+5];
ll a[MAXN+5],res[MAXN+5];
multiset<ll> st[MAXN+5],mx,mn;
void ins(int x){
	if(!st[x].empty()){
		mx.insert((*st[x].rbegin())+a[x]/(deg[x]+1));
		mn.insert((*st[x].begin())+a[x]/(deg[x]+1));
	}
}
void del(int x){
	if(!st[x].empty()){
		mx.erase(mx.find((*st[x].rbegin())+a[x]/(deg[x]+1)));
		mn.erase(mn.find((*st[x].begin())+a[x]/(deg[x]+1)));
	}
}
void upd(int x,int y){
	set<int> chg,f_chg;
	chg.insert(x);chg.insert(f[x]);chg.insert(f[f[x]]);
	chg.insert(y);chg.insert(f[y]);
	for(int z:chg) f_chg.insert(f[z]);
	f_chg.insert(y);
	for(int z:f_chg) del(z);
	for(int z:chg) st[f[z]].erase(st[f[z]].find(res[z]));
	for(int u:chg){
		res[u]-=a[u]-a[u]/(deg[u]+1)*deg[u];
		for(int v:chg) if(f[v]==u) res[u]-=a[v]/(deg[v]+1);
	}
	deg[f[x]]--;f[x]=y;deg[f[x]]++;
	for(int u:chg){
		res[u]+=a[u]-a[u]/(deg[u]+1)*deg[u];
		for(int v:chg) if(f[v]==u) res[u]+=a[v]/(deg[v]+1);
	}
	for(int z:chg) st[f[z]].insert(res[z]);
	for(int z:f_chg) ins(z);
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]),++deg[i],++deg[f[i]];
	for(int i=1;i<=n;i++){
		res[i]+=a[i]-a[i]/(deg[i]+1)*deg[i];
		res[f[i]]+=a[i]/(deg[i]+1);
	}
	for(int i=1;i<=n;i++) st[f[i]].insert(res[i]);
	for(int i=1;i<=n;i++) ins(i);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,y;scanf("%d%d",&x,&y);
			upd(x,y);
		} else if(opt==2){
			int x;scanf("%d",&x);
			printf("%lld\n",res[x]+a[f[x]]/(deg[f[x]]+1));
		} else {
			printf("%lld %lld\n",(*mn.begin()),(*mx.rbegin()));
		}
//		for(int i=1;i<=n;i++) assert(st[f[i]].find(res[i])!=st[f[i]].end());
//		for(int i=1;i<=n;i++) if(!st[i].empty()){
//			assert(mx.find((*st[i].rbegin())+a[i]/(deg[i]+1))!=mx.end());
//			assert(mn.find((*st[i].begin())+a[i]/(deg[i]+1))!=mn.end());
//		}
	}
	return 0;
}