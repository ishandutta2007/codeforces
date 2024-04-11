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
const int MAXN=2e5;
const int MOD=998244353;
int n,qu;
struct node{int l,r,sum,lz_add,lz_mul;} s[MAXN*4+5];
void pushup(int k){s[k].sum=(s[k<<1].sum+s[k<<1|1].sum)%MOD;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void tag_mul(int k,int v){
	s[k].sum=1ll*s[k].sum*v%MOD;
	s[k].lz_add=1ll*s[k].lz_add*v%MOD;
	s[k].lz_mul=1ll*s[k].lz_mul*v%MOD;
}
void tag_add(int k,int v){
	s[k].sum=(s[k].sum+1ll*v*(s[k].r-s[k].l+1))%MOD;
	s[k].lz_add=(s[k].lz_add+v)%MOD;
}
void pushdown(int k){
	if(s[k].lz_mul!=1) tag_mul(k<<1,s[k].lz_mul),tag_mul(k<<1|1,s[k].lz_mul),s[k].lz_mul=1;
	if(s[k].lz_add) tag_add(k<<1,s[k].lz_add),tag_add(k<<1|1,s[k].lz_add),s[k].lz_add=0;
}
void add1(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return tag_add(k,1),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) add1(k<<1,l,r);else if(l>mid) add1(k<<1|1,l,r);
	else add1(k<<1,l,mid),add1(k<<1|1,mid+1,r);
	pushup(k);
}
void mul2(int k,int l,int r){
//	printf("%d %d %d\n",k,l,r);
	if(l<=s[k].l&&s[k].r<=r) return tag_mul(k,2),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) mul2(k<<1,l,r);else if(l>mid) mul2(k<<1|1,l,r);
	else mul2(k<<1,l,mid),mul2(k<<1|1,mid+1,r);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return (query(k<<1,l,mid)+query(k<<1|1,mid+1,r))%MOD;
}
struct itvl{
	int l,r;
	itvl(int _l=0,int _r=0):l(_l),r(_r){}
	bool operator <(const itvl &rhs) const{
		return l<rhs.l;
	}
};
set<itvl> st[MAXN+5];
void split(int x,int p){
	if(st[x].empty()) return;
	set<itvl>::iterator it=st[x].upper_bound(itvl(p,0));
//	printf("split %d %d\n",x,p);
	if(it==st[x].begin()) return;--it;
	itvl t=*it;//printf("%d %d\n",t.l,t.r);
	if(t.r<=p) return;
	st[x].erase(st[x].find(t));
	st[x].insert(itvl(t.l,p));
	st[x].insert(itvl(p+1,t.r));
}
void deal(int l,int r,int x){
	split(x,l-1);split(x,r);
	set<itvl>::iterator it=st[x].lower_bound(itvl(l,0));
	vector<itvl> del;
	while(it!=st[x].end()&&(it->l)<=r){
		del.pb(*it);
		it=st[x].upper_bound(*it);
	} int pre=l-1;
//	puts("-1");
	for(int i=0;i<del.size();i++){
		int L=del[i].l,R=del[i].r;
//		printf("%d %d\n",L,R);
		mul2(1,L,R);if(pre!=L-1) add1(1,pre+1,L-1);
		pre=R;st[x].erase(st[x].find(del[i]));
	} if(pre!=r) add1(1,pre+1,r);
	st[x].insert(itvl(l,r));
}
int main(){
	scanf("%d%d",&n,&qu);build(1,1,n);
	while(qu--){
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		if(opt==1){
			int x;scanf("%d",&x);
			deal(l,r,x);
		} else printf("%d\n",query(1,l,r));
	}
	return 0;
}