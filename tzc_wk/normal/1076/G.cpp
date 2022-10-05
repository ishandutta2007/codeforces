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
const int MAXN=2e5;
const int MAXM=5;
int n,m,qu;ll a[MAXN+5];
struct data{
	int a[MAXM+3];
	data(){memset(a,0,sizeof(a));}
	friend data operator +(data x,data y){
		data res;
		for(int i=1;i<=m+1;i++) res.a[i]=y.a[x.a[i]];
		return res;
	}
};
struct node{int l,r,rev;data v[2];} s[MAXN*4+5];
void pushup(int k){
	s[k].v[0]=s[k<<1|1].v[0]+s[k<<1].v[0];
	s[k].v[1]=s[k<<1|1].v[1]+s[k<<1].v[1];
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;
	if(l==r){
		for(int i=1;i<=m;i++){
			s[k].v[a[l]].a[i]=s[k].v[a[l]^1].a[i]=i+1;
		} s[k].v[a[l]].a[m+1]=1;s[k].v[a[l]^1].a[m+1]=m+1;return;
	} int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void pushdown(int k){
	if(s[k].rev){
		swap(s[k<<1].v[0],s[k<<1].v[1]);s[k<<1].rev^=1;
		swap(s[k<<1|1].v[0],s[k<<1|1].v[1]);s[k<<1|1].rev^=1;
		s[k].rev=0;
	}
}
void flip(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return swap(s[k].v[0],s[k].v[1]),s[k].rev^=1,void();
	int mid=(pushdown(k),s[k].l+s[k].r>>1);
	if(r<=mid) flip(k<<1,l,r);else if(l>mid) flip(k<<1|1,l,r);
	else flip(k<<1,l,mid),flip(k<<1|1,mid+1,r);pushup(k);
}
data query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v[0];
	int mid=(pushdown(k),s[k].l+s[k].r>>1);
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1|1,mid+1,r)+query(k<<1,l,mid);
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]=(~a[i])&1;
	build(1,1,n);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r;ll x;scanf("%d%d%lld",&l,&r,&x);
			if(x&1) flip(1,l,r);
		} else {
			int l,r;scanf("%d%d",&l,&r);data t=query(1,l,r);
			printf("%d\n",1+(t.a[m+1]==1));
		}
	}
	return 0;
}