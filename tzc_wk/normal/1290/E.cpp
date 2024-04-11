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
const int MAXN=1.5e5;
int n,a[MAXN+5],p[MAXN+5];
struct node{int l,r,len,slen,mx,smx,mxc,tg,stg;ll sum;} s[MAXN*4+5];
void build(int k,int l,int r){s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);}
void clear(int k){
	s[k].len=s[k].slen=s[k].mx=s[k].smx=s[k].mxc=s[k].tg=s[k].stg=s[k].sum=0;
	if(s[k].l==s[k].r) return;else clear(k<<1),clear(k<<1|1);
}
void pushup(int k){
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
	if(s[k<<1].mx>s[k<<1|1].mx){
		s[k].len=s[k<<1].len;s[k].smx=max(s[k<<1].smx,s[k<<1|1].mx);
		s[k].slen=s[k<<1].slen+s[k<<1|1].len+s[k<<1|1].slen;
	} else if(s[k<<1].mx<s[k<<1|1].mx){
		s[k].len=s[k<<1|1].len;s[k].smx=max(s[k<<1|1].smx,s[k<<1].mx);
		s[k].slen=s[k<<1|1].slen+s[k<<1].len+s[k<<1].slen;
	} else {
		s[k].len=s[k<<1].len+s[k<<1|1].len;s[k].slen=s[k<<1].slen+s[k<<1|1].slen;
		s[k].smx=max(s[k<<1].smx,s[k<<1|1].smx);
	}
}
void pushtag(int k,int t1,int t2,bool is){
	if(!is) t1=t2;
	s[k].mx+=t1;s[k].tg+=t1;s[k].smx+=t2;s[k].stg+=t2;
	s[k].sum+=1ll*t1*s[k].len+1ll*t2*s[k].slen;
}
void pushdown(int k){
	bool tmp=s[k<<1|1].mx>=s[k<<1].mx;
	pushtag(k<<1,s[k].tg,s[k].stg,s[k<<1].mx>=s[k<<1|1].mx);
	pushtag(k<<1|1,s[k].tg,s[k].stg,tmp);s[k].tg=s[k].stg=0;
}
int add(int k,int l,int r){
	if(l>r) return 0;
	if(l<=s[k].l&&s[k].r<=r) return pushtag(k,1,1,1),s[k].len+s[k].slen;
	int mid=(pushdown(k),s[k].l+s[k].r>>1),ret;
	if(r<=mid) ret=add(k<<1,l,r);else if(l>mid) ret=add(k<<1|1,l,r);
	else ret=add(k<<1,l,mid)+add(k<<1|1,mid+1,r);
	return pushup(k),ret;
}
void turn(int k,int x,int v){
	if(s[k].l==s[k].r) return s[k].sum=s[k].mx=v,s[k].len=1,void();
	int mid=(pushdown(k),s[k].l+s[k].r>>1);
	((x<=mid)?turn(k<<1,x,v):turn(k<<1|1,x,v)),pushup(k);
}
void modify(int k,int l,int r,int v){
	if(l>r||v>=s[k].mx) return;
	if(l<=s[k].l&&s[k].r<=r){
		if(v>s[k].smx) return pushtag(k,v-s[k].mx,0,1),void();
		else{
			int mid=(pushdown(k),l+r>>1);
			return modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v),pushup(k),void();
		}
	} int mid=(pushdown(k),s[k].l+s[k].r>>1);
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
ll ans[MAXN+5];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;build(1,1,n);
	for(int ycxakioi=1;ycxakioi<=2;ycxakioi++){
		clear(1);for(int i=1,x;i<=n;i++){
			x=add(1,p[i]+1,n);turn(1,p[i],i+1);
			modify(1,1,p[i]-1,i-x);ans[i]+=s[1].sum;
//			printf("%lld\n",s[1].sum);
		} for(int i=1;i<=n;i++) p[i]=n-p[i]+1;
	} for(int i=1;i<=n;i++) printf("%lld\n",ans[i]-1ll*i*(i+2));
	return 0;
}