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
const int MAXN=3.5e4;
const int MAXK=100;
const int INF=0x3f3f3f3f;
int n,k,a[MAXN+5],dp[MAXN+5][MAXK+5],pre[MAXN+5];
struct segtree{
	struct node{int l,r,val,lz;} s[MAXN*4+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].val=INF;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		if(s[k].lz){
			s[k<<1].val+=s[k].lz;s[k<<1].lz+=s[k].lz;
			s[k<<1|1].val+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
			s[k].lz=0;
		}
	}
	void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r) return s[k].val+=x,s[k].lz+=x,void();
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,x);
		else if(l>mid) modify(k<<1|1,l,r,x);
		else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	void assign(int k,int p,int v){
		if(s[k].l==s[k].r) return s[k].val=v,void();
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		(p<=mid)?assign(k<<1,p,v):assign(k<<1|1,p,v);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].val;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} s[MAXK+5];
int main(){
	scanf("%d%d",&n,&k);memset(dp,63,sizeof(dp));dp[0][0]=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=k;i++) s[i].build(1,0,n);s[0].assign(1,0,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++) if(pre[a[i]])
			s[j].modify(1,0,pre[a[i]]-1,i-pre[a[i]]);
		pre[a[i]]=i;
		for(int j=1;j<=k;j++){
			chkmin(dp[i][j],s[j-1].query(1,0,i-1));
			s[j].assign(1,i,dp[i][j]);
		}
	} printf("%d\n",dp[n][k]);
	return 0;
}