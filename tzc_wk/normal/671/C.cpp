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
const int MAXN=2e5;
const int MAX_ITEM=3e6;
int n,a[MAXN+5];vector<int> pos[MAXN+5];
struct chain_list{
	int hd[MAXN+5],v[MAX_ITEM+5],nxt[MAX_ITEM+5],item_n=0;
	void ins(int p,int q){v[++item_n]=q;nxt[item_n]=hd[p];hd[p]=item_n;}
} fac;
void prework(int n){
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) fac.ins(j,i);
}
struct node{int l,r,tag,mx;ll sum;} s[MAXN*4+5];
void pushup(int k){
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
}
void pushdown(int k){
	if(s[k].tag!=0){
		s[k<<1].mx=s[k].tag;s[k<<1].tag=s[k].tag;
		s[k<<1].sum=1ll*(s[k<<1].r-s[k<<1].l+1)*s[k].tag;
		s[k<<1|1].mx=s[k].tag;s[k<<1|1].tag=s[k].tag;
		s[k<<1|1].sum=1ll*(s[k<<1|1].r-s[k<<1|1].l+1)*s[k].tag;
		s[k].tag=0;
	}
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].sum=l;s[k].mx=l;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].tag=x;s[k].mx=x;
		s[k].sum=1ll*(s[k].r-s[k].l+1)*x;return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int get_first_le(int k,int x){//find the first element >= x
	if(s[k].l==s[k].r) return s[k].l;
	pushdown(k);
	if(s[k<<1|1].mx<x) return s[k].r+1;
	else if(s[k<<1].mx<x) return get_first_le(k<<1|1,x);
	else return get_first_le(k<<1,x);
}
void deal_max(int l,int r,int x){
	if(l>r) return;
	int pos=get_first_le(1,x)-1;
//	printf("%d %d %d %d\n",l,r,x,pos);
	if(pos>r) pos=r;if(pos<l) return;
	modify(1,l,pos,x);
}
int main(){
	scanf("%d",&n);prework(MAXN);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) for(int e=fac.hd[a[i]];e;e=fac.nxt[e])
		pos[fac.v[e]].pb(i);
	build(1,1,n);ll ans=0;
	for(int i=MAXN;i;i--){
		if(pos[i].size()>=2){
			int fst=pos[i][0],fst_se=pos[i][1];
			int lst=pos[i][pos[i].size()-1],lst_se=pos[i][pos[i].size()-2];
			deal_max(1,fst,lst_se);
			deal_max(fst+1,fst_se,lst);
			deal_max(fst_se+1,n,n+1);
		} ans+=s[1].sum-1ll*n*(n+1)/2;
//		printf("%d %lld\n",i,s[1].sum);
	} printf("%lld\n",ans);
	return 0;
}