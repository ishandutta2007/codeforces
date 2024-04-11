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
const int MAXN=3e5;
int n,qu,a[MAXN+5];
struct data{
	ll fst,lst;int len,llen,rlen,l_tower,r_tower,mx;
	data(){fst=lst=len=llen=rlen=l_tower=r_tower=mx=0;}
	data(int _fst,int _lst,int _len,int _llen,int _rlen,int _l_tower,int _r_tower,int _mx):
	fst(_fst),lst(_lst),len(_len),llen(_llen),rlen(_rlen),l_tower(_l_tower),r_tower(_r_tower),mx(_mx){}
	friend data operator +(data a,data b){
		data c;
		c.fst=a.fst;c.lst=b.lst;c.len=a.len+b.len;
		c.llen=(a.llen==a.len&&a.lst>b.fst)?(a.llen+b.llen):a.llen;
		c.rlen=(b.rlen==b.len&&a.lst<b.fst)?(b.rlen+a.rlen):b.rlen;
		c.l_tower=(a.rlen==a.len&&a.lst<b.fst)?(a.l_tower+b.l_tower):
				  ((a.l_tower==a.len&&a.lst>b.fst)?(a.l_tower+b.llen):(a.l_tower));
		c.r_tower=(b.llen==b.len&&a.lst>b.fst)?(b.r_tower+a.r_tower):
				  ((b.r_tower==b.len&&a.lst<b.fst)?(b.r_tower+a.rlen):(b.r_tower));
		c.mx=max(a.mx,b.mx);
		if(a.lst>b.fst) c.mx=max(c.mx,a.r_tower+b.llen);
		if(a.lst<b.fst) c.mx=max(c.mx,a.rlen+b.l_tower);
		return c;
	}
};
struct node{int l,r;ll lz;data v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].v=data(a[l],a[l],1,1,1,1,1,1);return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].lz+=s[k].lz;s[k<<1].v.fst+=s[k].lz;s[k<<1].v.lst+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;s[k<<1|1].v.fst+=s[k].lz;s[k<<1|1].v.lst+=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].lz+=x;s[k].v.fst+=x;s[k].v.lst+=x;
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);scanf("%d",&qu);
	while(qu--){
		int l,r,v;scanf("%d%d%d",&l,&r,&v);
		modify(1,l,r,v);printf("%d\n",s[1].v.mx);
	}
	return 0;
}