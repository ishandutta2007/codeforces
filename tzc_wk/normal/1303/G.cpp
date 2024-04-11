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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1.5e5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,a[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct line{
	ll k,b;
	line(ll _k=0,ll _b=-INF):k(_k),b(_b){}
	ll get(int x){return 1ll*k*x+b;}
};
struct node{int l,r;line v;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
vector<int> opts;
void modify(int k,line v){
	int mid=s[k].l+s[k].r>>1;
	ll l1=s[k].v.get(s[k].l),r1=s[k].v.get(s[k].r),m1=s[k].v.get(mid);
	ll l2=v.get(s[k].l),r2=v.get(s[k].r),m2=v.get(mid);
	if(l1>=l2&&r1>=r2) return;
	if(l2>=l1&&r2>=r1) return s[k].v=v,opts.pb(k),void();
	if(m2>=m1){
		if(l2<l1) return modify(k<<1,s[k].v),s[k].v=v,void();
		else return modify(k<<1|1,s[k].v),s[k].v=v,void();
	} else {
		if(l2<l1) return modify(k<<1|1,v),void();
		else return modify(k<<1,v),void();
	}
}
ll query(int k,int x){
	if(s[k].l==s[k].r) return s[k].v.get(x);int mid=s[k].l+s[k].r>>1;
	return max(s[k].v.get(x),(x<=mid)?query(k<<1,x):query(k<<1|1,x));
}
bool vis[MAXN+5];int siz[MAXN+5],mx[MAXN+5],cent=0,subsiz[MAXN+5];
ll ans=0,sum[MAXN+5],_sum[MAXN+5],__sum[MAXN+5];int dep[MAXN+5];
void findcent(int x,int f,int tot){
	siz[x]=1;mx[x]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,tot);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	} chkmax(mx[x],tot-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
vector<int> pts;
void getdis(int x,int f){
	pts.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		dep[y]=dep[x]+1;sum[y]=sum[x]+a[y];
		_sum[y]=_sum[x]+sum[y];
		__sum[y]=__sum[x]+1ll*a[y]*dep[y];
		getdis(y,x);
	}
}
void divcent(int x){
	vis[x]=1;chkmax(ans,a[x]);dep[x]=1;
	sum[x]=_sum[x]=__sum[x]=a[x];
	modify(1,line(sum[x],__sum[x]));
	stack<int> stk;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		sum[y]=sum[x]+a[y];dep[y]=2;
		_sum[y]=sum[x]+a[x]+a[y];
		__sum[y]=sum[x]+(a[y]<<1);
		pts.clear();getdis(y,x);subsiz[y]=pts.size();
		for(int i=0;i<pts.size();i++){
			int z=pts[i];
			chkmax(ans,_sum[z]+query(1,dep[z]-1)-1ll*a[x]*dep[z]);
		}
		for(int i=0;i<pts.size();i++){
			int z=pts[i];
			modify(1,line(sum[z],__sum[z]));
		} stk.push(y);
	}
	for(int i=0;i<opts.size();i++) s[opts[i]].v=line();
	opts.clear();
	while(!stk.empty()){
		int y=stk.top();stk.pop();
		pts.clear();getdis(y,x);
		for(int i=0;i<pts.size();i++){
			int z=pts[i];
			chkmax(ans,_sum[z]+query(1,dep[z]-1)-1ll*a[x]*dep[z]);
		}
		for(int i=0;i<pts.size();i++){
			int z=pts[i];
			modify(1,line(sum[z],__sum[z]));
		}
	} chkmax(ans,_sum[x]+query(1,0)-a[x]);
	for(int i=0;i<opts.size();i++) s[opts[i]].v=line();
	opts.clear();
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		cent=0;findcent(y,x,subsiz[y]);
		divcent(cent);
	} 
}
int main(){
	scanf("%d",&n);mx[0]=1e9;build(1,0,n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	findcent(1,0,n);divcent(cent);printf("%lld\n",ans);
	return 0;
}