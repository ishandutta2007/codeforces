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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e4;
const int MAXV=2e4;
const int MAXK=100;
const int MAXP=MAXN*30;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,k,a[MAXN+5];ll dp[MAXN+5][MAXK+5];
struct line{
	ll k,b;
	line(ll _k=0,ll _b=INF):k(_k),b(_b){}
	ll get(int x){return 1ll*k*x+b;}
} lns[MAXN*2+5];
int lcnt=0;
struct node{int ch[2],mx;} s[MAXP+5];
int rt[MAXN+5],R=0,ocnt=0,ncnt=0;
struct chg{int k,on,ori;} op[MAXP+5];
void deal(int k,int id,int o){
//	printf("deal %d %d %d\n",k,id,o);
	if(o) op[++ocnt]={k,o,s[k].mx};
	s[k].mx=id;
}
void insert(int &k,int l,int r,int v,int is){
	if(!k) return k=++ncnt,deal(k,v,is),void();int mid=l+r>>1;
	ll l1=lns[s[k].mx].get(l),r1=lns[s[k].mx].get(r),m1=lns[s[k].mx].get(mid);
	ll l2=lns[v].get(l),r2=lns[v].get(r),m2=lns[v].get(mid);
	if(l1<=l2&&r1<=r2) return;
	if(l2<=l1&&r2<=r1) return deal(k,v,is),void();
	if(m2<=m1){
		if(l2<=l1) insert(s[k].ch[1],mid+1,r,s[k].mx,is),deal(k,v,is);
		else insert(s[k].ch[0],l,mid,s[k].mx,is),deal(k,v,is);
	} else {
		if(l2<=l1) insert(s[k].ch[0],l,mid,v,is);
		else insert(s[k].ch[1],mid+1,r,v,is);
	}
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x+y;insert(x,l,r,s[y].mx,0);
	int mid=l+r>>1;//printf("%d %d\n",s[x].mx,s[y].mx);
	s[x].ch[0]=merge(s[x].ch[0],s[y].ch[0],l,mid);
	s[x].ch[1]=merge(s[x].ch[1],s[y].ch[1],mid+1,r);
	return x;
}
ll query(int k,int l,int r,int p){
	if(!k) return INF;int mid=l+r>>1;
	if(l==r) return lns[s[k].mx].get(p);
	return min((p<=mid)?query(s[k].ch[0],l,mid,p):query(s[k].ch[1],mid+1,r,p),
	lns[s[k].mx].get(p));
}
int stk[MAXN+5],tp=0;
void clear(){
	memset(rt,0,sizeof(rt));
	for(int i=1;i<=ncnt;i++) s[i].ch[0]=s[i].ch[1]=s[i].mx=0;
	ncnt=lcnt=ocnt=tp=R=0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));dp[0][0]=0;
	for(int j=1;j<=k;j++){
		clear();
		for(int i=1;i<=n;i++){
			lns[++lcnt]=line(-(i-1),dp[i-1][j-1]);
			insert(rt[i],1,MAXV,lcnt,0);
//			printf("lns[%d]={%lld,%lld}\n",lcnt,lns[lcnt].k,lns[lcnt].b);
			while(tp>0&&a[stk[tp]]<a[i]){
				while(ocnt>0&&op[ocnt].on==stk[tp]) s[op[ocnt].k].mx=op[ocnt].ori,ocnt--;
				rt[i]=merge(rt[i],rt[stk[tp]],1,MAXV);tp--;
			} lns[++lcnt]=line(a[i],query(rt[i],1,MAXV,a[i]));
//			printf("lns[%d]={%lld,%lld}\n",lcnt,lns[lcnt].k,lns[lcnt].b);
			insert(R,1,n,lcnt,i);dp[i][j]=query(R,1,n,i);
			stk[++tp]=i;
//			printf("%d %d %lld\n",i,j,dp[i][j]);
		}
	} printf("%lld\n",dp[n][k]);
	return 0;
}