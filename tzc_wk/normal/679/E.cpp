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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int LOG_42=13;
const ll INF=1e18;
int n,qu;set<int> st;
ll pw42[LOG_42+2];
ll get42(ll v){return *lower_bound(pw42,pw42+LOG_42+1,v);}
struct node{int l,r;ll v,tag_lz,add_lz;} s[MAXN*4+5];
ll a[MAXN+5],nxt42[MAXN+5];
void pushup(int k){s[k].v=min(s[k<<1].v,s[k<<1|1].v);}
void pushdown(int k){
	if(s[k].tag_lz!=0){
		s[k<<1].v=s[k].tag_lz;s[k<<1|1].v=s[k].tag_lz;
		s[k<<1].tag_lz=s[k].tag_lz;s[k<<1|1].tag_lz=s[k].tag_lz;
		s[k].tag_lz=0;
	}
	if(s[k].add_lz!=0){
		s[k<<1].v+=s[k].add_lz;s[k<<1|1].v+=s[k].add_lz;
		s[k<<1].add_lz+=s[k].add_lz;s[k<<1|1].add_lz+=s[k].add_lz;
		s[k].add_lz=0;
	}
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r){nxt42[l]=get42(a[l]);s[k].v=nxt42[l]-a[l];return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void assign(int k,int l,int r,ll x){
	if(l<=s[k].l&&s[k].r<=r){s[k].tag_lz=s[k].v=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) assign(k<<1,l,r,x);
	else if(l>mid) assign(k<<1|1,l,r,x);
	else assign(k<<1,l,r,x),assign(k<<1|1,mid+1,r,x);
	pushup(k);
}
void change_v(int k,int p,ll x){
	if(s[k].l==s[k].r){
		nxt42[s[k].l]=get42(x);s[k].v=nxt42[s[k].l]-x;return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(p<=mid) change_v(k<<1,p,x);
	else change_v(k<<1|1,p,x);
	pushup(k);
}
void add(int k,int l,int r,ll x){
	if(l<=s[k].l&&s[k].r<=r){s[k].add_lz+=x;s[k].v+=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) add(k<<1,l,r,x);
	else if(l>mid) add(k<<1|1,l,r,x);
	else add(k<<1,l,r,x),add(k<<1|1,mid+1,r,x);
	pushup(k);
}
void killneg(int k){
	if(s[k].v>=0) return;
	if(s[k].l==s[k].r){
		s[k].v=nxt42[s[k].l]-s[k].v;
		nxt42[s[k].l]=get42(s[k].v);
		s[k].v=nxt42[s[k].l]-s[k].v;
		return;
	} pushdown(k);killneg(k<<1);killneg(k<<1|1);
	pushup(k);
}
ll getdif(int k,int p){
	if(s[k].l==s[k].r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;pushdown(k);
	if(p<=mid) return getdif(k<<1,p);
	else return getdif(k<<1|1,p);
}
ll query(int k,int p){
	if(s[k].l==s[k].r) return nxt42[s[k].l]-s[k].v;
	int mid=s[k].l+s[k].r>>1;pushdown(k);
	if(p<=mid) return query(k<<1,p);
	else return query(k<<1|1,p);
}
void split(int x){
	int nxt=*st.lower_bound(x);
	if(nxt==x) return;st.insert(nxt);
	change_v(1,x,query(1,nxt));st.insert(x);
}
int main(){
	pw42[0]=1;for(int i=1;i<=LOG_42;i++) pw42[i]=pw42[i-1]*42ll;
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),st.insert(i);
	build(1,1,n);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){int x;scanf("%d",&x);printf("%lld\n",query(1,*st.lower_bound(x)));}
		else if(opt==2){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			if(l>1) split(l-1);split(r);
			st.erase(st.lower_bound(l),st.lower_bound(r));
			if(l<r) assign(1,l,r-1,INF);
			change_v(1,r,v);
		} else {
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			if(l>1) split(l-1);split(r);
			do {
				add(1,l,r,-v);killneg(1);
			} while(s[1].v==0);
		}
	}
	return 0;
}
/*
6 13
40 1700 7 1672 4 1722
3 2 4 42
1 2
1 3
1 4
3 2 6 50
1 2
1 4
1 6
2 3 4 41
3 1 5 1
1 1
1 3
1 5
*/