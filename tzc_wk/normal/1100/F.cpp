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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int LOG_V=20;
int n,qu,a[MAXN+5];pii q[MAXN+5];
struct lbase{
	int a[LOG_V+2];
	lbase(){memset(a,0,sizeof(a));}
	void reset(){memset(a,0,sizeof(a));}
	void insert(int v){
		for(int i=LOG_V;~i;i--) if(v>>i&1){
			if(a[i]) v^=a[i];
			else return a[i]=v,void();
		}
	}
	int query(){
		int ret=0;
		for(int i=LOG_V;~i;i--) if((ret^a[i])>ret) ret^=a[i];
		return ret;
	}
	lbase operator +(const lbase &rhs){
		lbase res=*this;
		for(int i=0;i<=LOG_V;i++) if(rhs.a[i])
			res.insert(rhs.a[i]);
		return res;
	}
};
lbase suf[MAXN+5],pre[MAXN+5];
int res[MAXN+5];
void solve(int l,int r,vector<int> cd){
	if(l==r){
		for(int id:cd) res[id]=a[l];
		return;
	} int mid=l+r>>1;vector<int> nL,nR;
	for(int i=l;i<=r;i++) suf[i].reset(),pre[i].reset();
	for(int i=mid;i>=l;i--) suf[i]=suf[i+1],suf[i].insert(a[i]);
	for(int i=mid+1;i<=r;i++) pre[i]=pre[i-1],pre[i].insert(a[i]);
	for(int id:cd){
		if(q[id].se<=mid) nL.pb(id);
		else if(q[id].fi>mid) nR.pb(id);
		else{
			lbase cur=suf[q[id].fi]+pre[q[id].se];
			res[id]=cur.query();
		}
	} solve(l,mid,nL);solve(mid+1,r,nR);
}
int main(){
	scanf("%d",&n);vector<int> ini;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);scanf("%d",&qu);
	for(int i=1;i<=qu;i++) scanf("%d%d",&q[i].fi,&q[i].se),ini.pb(i);
	solve(1,n,ini);for(int i=1;i<=qu;i++) printf("%d\n",res[i]);
	return 0;
}