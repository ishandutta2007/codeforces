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
const int MAXN=1e5;
int n,m,ans[MAXN+5];vector<int> qv[MAXN+5];
int hd[MAXN+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int bgt[MAXN+5],edt[MAXN+5],tim=0;
void dfs(int x,int f){
	bgt[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);
	} edt[x]=tim;
}
struct node{int val,lz;} s[MAXN*4+5];
stack<stack<pair<int,node> > > stk;
void pushup(int k){
	stk.top().push(mp(k,s[k]));
	s[k].val=s[k<<1].val+s[k<<1|1].val;
}
void build(int k,int l,int r){
	if(k==1) stk.push(stack<pair<int,node> >());
	s[k].val=r-l+1;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void tag(int k){stk.top().push(mp(k,s[k]));s[k].val=0;s[k].lz=1;}
void pushdown(int k){
	stk.top().push(mp(k,s[k]));
	if(s[k].lz) tag(k<<1),tag(k<<1|1),s[k].lz=0;
}
void modify(int k,int ql,int qr,int l,int r){
	if(k==1) stk.push(stack<pair<int,node> >());
	if(ql<=l&&r<=qr){tag(k);return;}
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) modify(k<<1,ql,qr,l,mid);
	else if(ql>mid) modify(k<<1|1,ql,qr,mid+1,r);
	else modify(k<<1,ql,mid,l,mid),modify(k<<1|1,mid+1,qr,mid+1,r);
	pushup(k);
}
void cancel(){
	stack<pair<int,node> > tmp=stk.top();stk.pop();
	while(!tmp.empty()) s[tmp.top().fi]=tmp.top().se,tmp.pop();
}
void calc(int x,int f){
	int tmp=stk.size();
	for(int i=0;i<qv[x].size();i++){
		int y=qv[x][i];
		modify(1,bgt[x],edt[x],1,n);
		modify(1,bgt[y],edt[y],1,n);
	} ans[x]=n-s[1].val;
	if(ans[x]) ans[x]--;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		calc(y,x);
	}
	while(stk.size()>tmp) cancel();
}
int main(){
	scanf("%d%d",&n,&m);build(1,1,n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);dfs(1,0);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),qv[u].pb(v),qv[v].pb(u);calc(1,0);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],(i==n)?'\n':' ');
	return 0;
}