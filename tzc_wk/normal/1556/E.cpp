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
const int MAXN=1e5;
int n,qu,a[MAXN+5];
struct dat{
	ll sum,mxv,mnv;
	dat(ll x=0){sum=x;mxv=max(x,0ll);mnv=min(x,0ll);}
	dat operator +(const dat &rhs){
		dat res;res.sum=sum+rhs.sum;
		res.mxv=max(mxv,sum+rhs.mxv);
		res.mnv=min(mnv,sum+rhs.mnv);
		return res;
	}
};
struct node{int l,r;dat v;} s[MAXN*4+10];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].v=dat(a[l]),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	s[k].v=s[k<<1].v+s[k<<1|1].v;
}
dat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),a[i]+=x;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),a[i]-=x;
	build(1,1,n);
	while(qu--){
		int l,r;scanf("%d%d",&l,&r);dat v=query(1,l,r);
		if(v.sum!=0||v.mxv>0) puts("-1");
		else printf("%lld\n",max(v.mxv,-v.mnv));
	}
	return 0;
}