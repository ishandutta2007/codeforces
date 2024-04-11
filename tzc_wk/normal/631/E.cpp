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
const int MAXN=2e5;
const ll INF=1e18;
int n,a[MAXN+5];ll pre[MAXN+5],ans=0;
struct line{
	ll k,b;
	line(ll _k=0,ll _b=-INF):k(_k),b(_b){}
	ll ask(int x){return x*k+b;}
};
struct node{int l,r,hav;line mx;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].hav=0;s[k].mx=line();if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,line x){
	if(!s[k].hav) return s[k].mx=x,s[k].hav=1,void();
	int mid=s[k].l+s[k].r>>1;
	ll l1=x.ask(s[k].l),r1=x.ask(s[k].r);
	ll l2=s[k].mx.ask(s[k].l),r2=s[k].mx.ask(s[k].r);
	if(l2>=l1&&r2>=r1) return;
	if(l1>=l2&&r1>=r2) return s[k].mx=x,void();
	double ix=1.*(s[k].mx.b-x.b)/(x.k-s[k].mx.k);
	if(ix<=mid){
		if(l1>=l2) modify(k<<1,x);
		else modify(k<<1,s[k].mx),s[k].mx=x;
	} else {
		if(l1>=l2) modify(k<<1|1,s[k].mx),s[k].mx=x;
		else modify(k<<1|1,x);
	}
}
ll query(int k,int p){
	if(s[k].l==s[k].r) return s[k].mx.ask(p);int mid=s[k].l+s[k].r>>1;
	return max((p<=mid)?query(k<<1,p):query(k<<1|1,p),s[k].mx.ask(p));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
	build(1,1,n);
	for(int i=1;i<=n;i++){
		chkmax(ans,-pre[i]+query(1,i));
		modify(1,line(a[i],pre[i]-1ll*i*a[i]));
	} build(1,1,n);
	for(int i=n;i;i--){
		chkmax(ans,-pre[i-1]+query(1,i));
		modify(1,line(a[i],pre[i-1]-1ll*i*a[i]));
	} for(int i=1;i<=n;i++) ans+=1ll*i*a[i];
	printf("%lld\n",ans);
	return 0;
}