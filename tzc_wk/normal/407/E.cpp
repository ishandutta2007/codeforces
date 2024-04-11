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
const int MAXN=2e5;
int n,k,d,a[MAXN+5],b[MAXN+5],c[MAXN+5];
map<int,int> pre;
int getmod(int x,int v){return (x%v+v)%v;}
int getdiv(int x,int v){return (x-getmod(x,v))/v;}
struct node{int l,r,mn,lz;} s[MAXN*4+5];
void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void tag(int x,int v){s[x].mn+=v;s[x].lz+=v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
int findleq(int k,int l,int r,int v){
	if(s[k].mn>v) return -1;
	if(l<=s[k].l&&s[k].r<=r){
		if(s[k].l==s[k].r) return s[k].l;
		pushdown(k);int ps,mid=s[k].l+s[k].r>>1;
		if(~(ps=findleq(k<<1,l,mid,v))) return ps;
		return findleq(k<<1|1,mid+1,r,v);
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return findleq(k<<1,l,r,v);
	else if(l>mid) return findleq(k<<1|1,l,r,v);
	else{
		int ps;
		if(~(ps=findleq(k<<1,l,mid,v))) return ps;
		return findleq(k<<1|1,mid+1,r,v);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(!d){
		pii res=mp(0,0);
		for(int l=1,r;l<=n;l++){
			r=l;while(r<=n&&a[l]==a[r]) ++r;
			chkmax(res,mp(r-l,-l));
		} printf("%d %d\n",-res.se,-res.se+res.fi-1);
		return 0;
	} build(1,1,n);pii res;
	for(int i=1;i<=n;i++) b[i]=getdiv(a[i],d),c[i]=getmod(a[i],d);
	stack<int> stk_mn,stk_mx;stk_mn.push(0);stk_mx.push(0);
	for(int i=1,mnl=1;i<=n;i++){//(mx-mn)-(r-l)<=k
		if(c[i]!=c[i-1]) chkmax(mnl,i);
		chkmax(mnl,pre[b[i]]+1);pre[b[i]]=i;
		while(stk_mn.size()>1&&b[i]<b[stk_mn.top()]){
			int p=stk_mn.top();stk_mn.pop();
			modify(1,stk_mn.top()+1,p,b[p]-b[i]);
//			printf("modify %d %d %d\n",stk_mn.top()+1,p,b[p]-b[i]);
		} while(stk_mx.size()>1&&b[i]>b[stk_mx.top()]){
			int p=stk_mx.top();stk_mx.pop();
			modify(1,stk_mx.top()+1,p,-b[p]+b[i]);
//			printf("modify %d %d %d\n",stk_mx.top()+1,p,-b[p]+b[i]);
		} if(i^1) modify(1,1,i-1,-1)/*,printf("modify %d %d %d\n",1,i-1,-1)*/;
		stk_mn.push(i);stk_mx.push(i);
		int ps=findleq(1,mnl,i,k);
		if(~ps) chkmax(res,mp(i-ps+1,-ps));
	} printf("%d %d\n",-res.se,-res.se+res.fi-1);
	return 0;
}