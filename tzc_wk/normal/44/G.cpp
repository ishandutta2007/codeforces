//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
#define y1 y111111111
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
const int K=2;
const int INF=0x3f3f3f3f;
int n,qu;
struct plane{
	int z,x1,y1,x2,y2,id;
	bool operator <(const plane &rhs){
		return z<rhs.z;
	}
} a[MAXN+5];
struct point{
	int x[K+2],t;
	point(){memset(x,0,sizeof(x));t=0;}
	int& operator [](int id){return x[id];}
} p[MAXN+5];
int pos[MAXN+5],res[MAXN+5];
struct node{int ch[2],mnt;point val,mn,mx;} s[MAXN+5];
int rt=0,ncnt=0;
void pushup(int k){s[k].mnt=min(s[k].val.t,min(s[s[k].ch[0]].mnt,s[s[k].ch[1]].mnt));}
void build(int &k,int l,int r){
	if(l>r) return;k=++ncnt;
	static double avg[K+2],var[K+2];
	fill(avg,avg+K,0);fill(var,var+K,0);
	for(int i=l;i<=r;i++) for(int j=0;j<K;j++) avg[j]+=p[i][j];
	for(int j=0;j<K;j++) avg[j]/=(r-l+1);
	function<double(double)> sqr=[&](double x){return x*x;};
	for(int i=l;i<=r;i++) for(int j=0;j<K;j++) var[j]+=sqr(p[i][j]-avg[j]);
	double mx=0;int dim=0;
	for(int j=0;j<K;j++) if(var[j]>mx) mx=var[j],dim=j;
	int mid=l+r>>1;
	nth_element(p+l,p+mid,p+r+1,[&](point lhs,point rhs){return lhs[dim]<rhs[dim];});
	s[k].val=s[k].mn=s[k].mx=p[mid];
//	printf("node %d %d %d %d %.10lf %.10lf\n",k,p[mid][0],p[mid][1],p[mid].t,avg[0],avg[1]);
	build(s[k].ch[0],l,mid-1);build(s[k].ch[1],mid+1,r);
	for(int i=0;i<K;i++){
		if(s[k].ch[0]) chkmin(s[k].mn[i],s[s[k].ch[0]].mn[i]),chkmax(s[k].mx[i],s[s[k].ch[0]].mx[i]);
		if(s[k].ch[1]) chkmin(s[k].mn[i],s[s[k].ch[1]].mn[i]),chkmax(s[k].mx[i],s[s[k].ch[1]].mx[i]);
	} pushup(k);
}
void chg(int k,int l,int r,int p){
	int mid=l+r>>1;
	if(mid==p) return s[k].val.t=INF,pushup(k),void();
	if(p<mid) chg(s[k].ch[0],l,mid-1,p);
	else chg(s[k].ch[1],mid+1,r,p);
	pushup(k);
}
int query(int k,int x1,int y1,int x2,int y2){
	if(!k) return INF;
	if(s[k].mn[0]>x2||s[k].mx[0]<x1||s[k].mn[1]>y2||s[k].mx[1]<y1) return INF;
	if(s[k].mn[0]>=x1&&x2>=s[k].mx[0]&&s[k].mn[1]>=y1&&y2>=s[k].mx[1]) return s[k].mnt;
	int res=INF;
	if(x1<=s[k].val[0]&&s[k].val[0]<=x2&&y1<=s[k].val[1]&&s[k].val[1]<=y2) res=s[k].val.t;
	chkmin(res,query(s[k].ch[0],x1,y1,x2,y2));chkmin(res,query(s[k].ch[1],x1,y1,x2,y2));
	return res;
}
int main(){
	scanf("%d",&n);s[0].mnt=INF;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&a[i].x1,&a[i].x2,&a[i].y1,&a[i].y2,&a[i].z);
		a[i].id=i;
	} sort(a+1,a+n+1);scanf("%d",&qu);//pay attention to the sequence of input!!!
	for(int i=1;i<=qu;i++) scanf("%d%d",&p[i][0],&p[i][1]),p[i].t=i;
	build(rt,1,qu);for(int i=1;i<=qu;i++) pos[p[i].t]=i;
	for(int i=1;i<=n;i++){
		int p=query(1,a[i].x1,a[i].y1,a[i].x2,a[i].y2);
//		printf("p=%d\n",p);
		if(p!=INF) res[p]=a[i].id,chg(1,1,qu,pos[p]);
	} for(int i=1;i<=qu;i++) printf("%d\n",res[i]);
	return 0;
}