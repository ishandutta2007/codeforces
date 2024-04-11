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
const int INF=0x3f3f3f3f;
int n,p[MAXN+5],pos[MAXN+5];
struct node{int l,r,lz;pii fst,snd;} s[MAXN*4+5];
void pushup(int k){
	static pii p[4];
	p[0]=s[k<<1].fst;p[1]=s[k<<1].snd;
	p[2]=s[k<<1|1].fst;p[3]=s[k<<1|1].snd;
	sort(p,p+4);s[k].fst=mp(p[0].fi,0);int cur=0;
	while(p[cur].fi==p[0].fi) s[k].fst.se+=p[cur].se,cur++;
	s[k].snd=mp(p[cur].fi,0);
	while(p[cur].fi==s[k].snd.fi) s[k].snd.se+=p[cur].se,cur++;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].fst=mp(0,1);s[k].snd=mp(INF,0);return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].fst.fi+=s[k].lz;s[k<<1].snd.fi+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].fst.fi+=s[k].lz;s[k<<1|1].snd.fi+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].fst.fi+=x;s[k].snd.fi+=x;s[k].lz+=x;
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r){
		int ret=0;
		if(s[k].fst.fi<=2) ret+=s[k].fst.se;
		if(s[k].snd.fi<=2) ret+=s[k].snd.se;
		return ret; 
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d",&n);ll ans=0;build(1,1,n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;i++){
		modify(1,1,i,1);
		if(pos[i]!=1&&p[pos[i]-1]<i) modify(1,1,p[pos[i]-1],-1);
		if(pos[i]!=n&&p[pos[i]+1]<i) modify(1,1,p[pos[i]+1],-1);
		if(i!=1) ans+=query(1,1,i-1);
	} printf("%lld\n",ans);
	return 0;
}