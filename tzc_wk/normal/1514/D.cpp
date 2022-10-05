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
const int MAXN=3e5;
int n,qu,a[MAXN+5];
struct data{
	int mx,cnt;
	data(){mx=cnt=0;}
	data operator +(const data &rhs) const{
		data ret;
		if(mx==rhs.mx) ret.mx=mx,ret.cnt=cnt+rhs.cnt;
		else if(cnt>rhs.cnt) ret.mx=mx,ret.cnt=cnt-rhs.cnt;
		else ret.mx=rhs.mx,ret.cnt=rhs.cnt-cnt;
		return ret;
	}
};
struct node{int l,r;data v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].v.mx=a[l];s[k].v.cnt=1;return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
data query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
vector<int> pos[MAXN+5];
int getcnt(int v,int l,int r){
	int cl=lower_bound(pos[v].begin(),pos[v].end(),l)-pos[v].begin();
	int cr=upper_bound(pos[v].begin(),pos[v].end(),r)-pos[v].begin();
	return cr-cl;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]].pb(i);
	build(1,1,n);
	while(qu--){
		int l,r;scanf("%d%d",&l,&r);
		data v=query(1,l,r);
		int cnt=getcnt(v.mx,l,r);
		if(cnt*2<=r-l+2) puts("1");
		else printf("%d\n",cnt*2-(r-l+1));
	}
	return 0;
}