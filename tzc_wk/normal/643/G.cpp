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
const int MAXN=1.5e5;
const int INF=0x3f3f3f3f;
int n,qu,p,a[MAXN+5];
struct seq{
	int cnt,x[8],y[8];
	seq(){cnt=0;fill0(x);fill0(y);}
};
struct node{int l,r,lz;seq v;} s[MAXN*4+5];
seq merge(seq a,seq b){
	for(int i=1;i<=b.cnt;i++){
		bool ok=0;
		for(int j=1;j<=a.cnt;j++){
			if(a.x[j]==b.x[i]){
				a.y[j]+=b.y[i];
				ok=1;break;
			}
		} if(ok) continue;
		a.x[++a.cnt]=b.x[i];a.y[a.cnt]=b.y[i];int mn=INF;
		if(a.cnt<=p) continue;
		for(int j=1;j<=a.cnt;j++) chkmin(mn,a.y[j]);
		seq c;
		for(int j=1;j<=a.cnt;j++) if(a.y[j]-mn)
			c.x[++c.cnt]=a.x[j],c.y[c.cnt]=a.y[j]-mn;
		a=c;
	} return a;
}
void pushup(int k){s[k].v=merge(s[k<<1].v,s[k<<1|1].v);}
void build(int k=1,int l=1,int r=n){
	s[k].l=l;s[k].r=r;if(l==r){s[k].v.cnt=1;s[k].v.x[1]=a[l];s[k].v.y[1]=1;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].v.cnt=1;s[k<<1].v.x[1]=s[k].lz;
		s[k<<1].v.y[1]=s[k<<1].r-s[k<<1].l+1;
		s[k<<1].lz=s[k].lz;
		s[k<<1|1].v.cnt=1;s[k<<1|1].v.x[1]=s[k].lz;
		s[k<<1|1].v.y[1]=s[k<<1|1].r-s[k<<1|1].l+1;
		s[k<<1|1].lz=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].v.cnt=1;s[k].v.x[1]=x;
		s[k].v.y[1]=s[k].r-s[k].l+1;
		s[k].lz=x;return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
seq query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;pushdown(k);
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return merge(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int main(){
	scanf("%d%d%d",&n,&qu,&p);p=100/p;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);build();
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){int l,r,x;scanf("%d%d%d",&l,&r,&x);modify(1,l,r,x);}
		else{
			int l,r;scanf("%d%d",&l,&r);seq ret=query(1,l,r);
			printf("%d ",ret.cnt);for(int i=1;i<=ret.cnt;i++) printf("%d ",ret.x[i]);
			printf("\n");
		}
	}
	return 0;
}