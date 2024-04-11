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
using namespace fastio;
const int MAXN=5e5;
const int INF=0x3f3f3f3f;
int n,d,key[MAXN*2+5],uni[MAXN*2+5],cnt=0,num=0;
struct climber{
	int s,a;
	bool operator <(const climber &rhs){
		return 1ll*s*a<1ll*rhs.s*rhs.a;
	}
} b[MAXN+5];
int mx[MAXN*8+5],lz[MAXN*8+5];
void pushup(int k){mx[k]=max(mx[k<<1],mx[k<<1|1]);}
void tag(int k,int v){mx[k]+=v;lz[k]+=v;}
void pushdown(int k){if(lz[k]) tag(k<<1,lz[k]),tag(k<<1|1,lz[k]),lz[k]=0;}
void modify(int k,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr) return tag(k,v),void();
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) modify(k<<1,l,mid,ql,qr,v);
	else if(ql>mid) modify(k<<1|1,mid+1,r,ql,qr,v);
	else modify(k<<1,l,mid,ql,mid,v),modify(k<<1|1,mid+1,r,mid+1,qr,v);
	pushup(k);
}
void assign(int k,int l,int r,int p,int v){
	if(l==r) return chkmax(mx[k],v),void();
	pushdown(k);int mid=l+r>>1;
	if(p<=mid) assign(k<<1,l,mid,p,v);
	else assign(k<<1|1,mid+1,r,p,v);
	pushup(k);
}
int query(int k,int l,int r,int ql,int qr){
	if(ql>qr) return -INF;
	if(ql<=l&&r<=qr) return mx[k];
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query(k<<1,l,mid,ql,qr);
	else if(ql>mid) return query(k<<1|1,mid+1,r,ql,qr);
	else return max(query(k<<1,l,mid,ql,mid),query(k<<1|1,mid+1,r,mid+1,qr));
}
int main(){
	scanf("%d%d",&n,&d);key[++cnt]=d;
	for(int i=1;i<=n;i++){
		read(b[i].s);read(b[i].a);
		key[++cnt]=b[i].s;key[++cnt]=b[i].a;
	} sort(b+1,b+n+1);sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) uni[++num]=key[i];
	memset(mx,192,sizeof(mx));int posd=lower_bound(uni+1,uni+num+1,d)-uni;
	assign(1,1,num,posd,0);
	for(int i=1;i<=n;i++){
		int s=lower_bound(uni+1,uni+num+1,b[i].s)-uni;
		int a=lower_bound(uni+1,uni+num+1,b[i].a)-uni;
		if(s<=a){
			int dp=query(1,1,num,1,s)+1;
			if(dp>0) assign(1,1,num,a,dp);
		} else {
			int dp=query(1,1,num,1,a)+1;
			if(dp>0) assign(1,1,num,a,dp);
			modify(1,1,num,a+1,s,1);
		} //printf("%d %d\n",s,a);
	} printf("%d\n",mx[1]);
	return 0;
}//