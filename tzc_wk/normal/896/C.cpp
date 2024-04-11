#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MOD=1e9+7;
int qpow(int x,int e,int mod){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%mod) if(e&1) ret=1ll*ret*x%mod;
	return ret;
}
int n,m,seed,vmax,a[MAXN+5];
int rnd(){
	int ret=seed;
	seed=(seed*7ll+13)%MOD;
	return ret;
}
struct node{
	int l,r;ll v;
	node(int _l=0,int _r=0,ll _v=0):l(_l),r(_r),v(_v){}
	bool operator <(const node &rhs) const{return l<rhs.l;}
};
set<node> st;
void split(int x){
	if(st.empty()) return;
	set<node>::iterator it=st.lower_bound(node(x+1,0,0));
	if(it==st.begin()) return;--it;
	node val=*it;if(val.r<=x) return;
	st.erase(st.find(val));
	st.insert(node(val.l,x,val.v));
	st.insert(node(x+1,val.r,val.v));
}
void add(int l,int r,int x){
	if(l!=1) split(l-1);split(r);
	set<node>::iterator it=st.lower_bound(node(l,0,0));
	while(1){
		node val=*it;st.erase(st.find(val));
		val.v+=x;st.insert(val);
		it=st.upper_bound(val);
		if(it==st.end()||(it->l)>r) break;
	}
}
void assign(int l,int r,int x){
	if(l!=1) split(l-1);split(r);
	set<node>::iterator it=st.lower_bound(node(l,0,0));
	while(1){
		node val=*it;st.erase(st.find(val));
		it=st.upper_bound(node(l,0,0));
		if(it==st.end()||(it->l)>r) break;
	} st.insert(node(l,r,x));
}
ll rnk(int l,int r,int x){
	if(l!=1) split(l-1);split(r);
	set<node>::iterator it=st.lower_bound(node(l,0,0));
	vector<pair<ll,int> > vec;
	while(1){
		node val=*it;vec.pb(mp(val.v,val.r-val.l+1));
		it=st.upper_bound(val);
		if(it==st.end()||(it->l)>r) break;
	} sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		x-=vec[i].se;
		if(x<=0) return vec[i].fi;
	} assert(0);
}
int query(int l,int r,int x,int y){
	if(l!=1) split(l-1);split(r);int ans=0;
	set<node>::iterator it=st.lower_bound(node(l,0,0));
	while(1){
		node val=*it;ans=(ans+1ll*(val.r-val.l+1)*qpow(val.v%y,x,y))%y;
		it=st.upper_bound(val);
		if(it==st.end()||(it->l)>r) break;
	} return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;i++) a[i]=rnd()%vmax+1,st.insert(node(i,i,a[i]));
	while(m--){
		int opt=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if(l>r) l^=r^=l^=r;
		if(opt==3) x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(opt==4) y=rnd()%vmax+1;
		if(opt==1) add(l,r,x);
		if(opt==2) assign(l,r,x);
		if(opt==3) printf("%lld\n",rnk(l,r,x));
		if(opt==4) printf("%d\n",query(l,r,x,y));
	}
	return 0;
}