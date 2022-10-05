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
const int MOD=1e9+7;
const int INV3=333333336;
int n,qu,a[MAXN+5],key[MAXN+5],uni[MAXN+5],num=0;
int t[MAXN+5],pre[MAXN+5],nxt[MAXN+5];
void add(int x,int v){for(int i=x;i<=num;i+=(i&-i)) t[i]+=v;}
int ask(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
vector<int> pos[MAXN+5];int where[MAXN+5],cnt[MAXN+5];
struct node{
	int ch[2];
	int lz_pre,lz_nxt,cnt;
	int pre0,pre1;
	int nxt0,nxt1;
} s[MAXN*4+5];
int rt[MAXN+5],ncnt=0;
void pushup(int k){
	s[k].pre0=(s[s[k].ch[0]].pre0+s[s[k].ch[1]].pre0)%MOD;
	s[k].pre1=(s[s[k].ch[0]].pre1+s[s[k].ch[1]].pre1)%MOD;
	s[k].nxt0=(s[s[k].ch[0]].nxt0+s[s[k].ch[1]].nxt0)%MOD;
	s[k].nxt1=(s[s[k].ch[0]].nxt1+s[s[k].ch[1]].nxt1)%MOD;
	s[k].cnt=s[s[k].ch[0]].cnt+s[s[k].ch[1]].cnt;
}
void build(int &k,int l,int r,int v){
	k=++ncnt;
	if(l==r){
		s[k].cnt=1;
		s[k].pre0=pre[pos[v][l-1]];s[k].pre1=1ll*l*s[k].pre0%MOD;
		s[k].nxt0=nxt[pos[v][l-1]];s[k].nxt1=1ll*(cnt[v]-l+1)*s[k].nxt0%MOD;
		return;
	} int mid=l+r>>1;
	build(s[k].ch[0],l,mid,v);build(s[k].ch[1],mid+1,r,v);
	pushup(k);
}
void pushdown(int k){
	if(s[k].lz_pre){
		s[s[k].ch[0]].pre1=(s[s[k].ch[0]].pre1+1ll*s[k].lz_pre*s[s[k].ch[0]].pre0%MOD)%MOD;
		s[s[k].ch[0]].lz_pre=(s[s[k].ch[0]].lz_pre+s[k].lz_pre)%MOD;
		s[s[k].ch[1]].pre1=(s[s[k].ch[1]].pre1+1ll*s[k].lz_pre*s[s[k].ch[1]].pre0%MOD)%MOD;
		s[s[k].ch[1]].lz_pre=(s[s[k].ch[1]].lz_pre+s[k].lz_pre)%MOD;
		s[k].lz_pre=0;
	} if(s[k].lz_nxt){
		s[s[k].ch[0]].nxt1=(s[s[k].ch[0]].nxt1+1ll*s[k].lz_nxt*s[s[k].ch[0]].nxt0%MOD)%MOD;
		s[s[k].ch[0]].lz_nxt=(s[s[k].ch[0]].lz_nxt+s[k].lz_nxt)%MOD;
		s[s[k].ch[1]].nxt1=(s[s[k].ch[1]].nxt1+1ll*s[k].lz_nxt*s[s[k].ch[1]].nxt0%MOD)%MOD;
		s[s[k].ch[1]].lz_nxt=(s[s[k].ch[1]].lz_nxt+s[k].lz_nxt)%MOD;
		s[k].lz_nxt=0;
	}
}
int query_cnt(int k,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(ql<=l&&r<=qr) return s[k].cnt;
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query_cnt(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_cnt(s[k].ch[1],mid+1,r,ql,qr);
	else return query_cnt(s[k].ch[0],l,mid,ql,mid)+query_cnt(s[k].ch[1],mid+1,r,mid+1,qr);
}
int query_pre0(int k,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(ql<=l&&r<=qr) return s[k].pre0;
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query_pre0(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_pre0(s[k].ch[1],mid+1,r,ql,qr);
	else return (query_pre0(s[k].ch[0],l,mid,ql,mid)+query_pre0(s[k].ch[1],mid+1,r,mid+1,qr))%MOD;
}
int query_pre1(int k,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(ql<=l&&r<=qr) return s[k].pre1;
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query_pre1(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_pre1(s[k].ch[1],mid+1,r,ql,qr);
	else return (query_pre1(s[k].ch[0],l,mid,ql,mid)+query_pre1(s[k].ch[1],mid+1,r,mid+1,qr))%MOD;
}
int query_nxt0(int k,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(ql<=l&&r<=qr) return s[k].nxt0;
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query_nxt0(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_nxt0(s[k].ch[1],mid+1,r,ql,qr);
	else return (query_nxt0(s[k].ch[0],l,mid,ql,mid)+query_nxt0(s[k].ch[1],mid+1,r,mid+1,qr))%MOD;
}
int query_nxt1(int k,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(ql<=l&&r<=qr) return s[k].nxt1;
	pushdown(k);int mid=l+r>>1;
	if(qr<=mid) return query_nxt1(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_nxt1(s[k].ch[1],mid+1,r,ql,qr);
	else return (query_nxt1(s[k].ch[0],l,mid,ql,mid)+query_nxt1(s[k].ch[1],mid+1,r,mid+1,qr))%MOD;
}
void modify(int k,int l,int r,int p,int x,int ps,int ss,int v){
	if(l==r){
		if(v==-1){
			s[k].cnt=s[k].pre0=s[k].pre1=0;
			s[k].nxt0=s[k].nxt1=0;
		} else {
			s[k].cnt=1;
			s[k].pre0=pre[x];s[k].pre1=1ll*pre[x]*ps%MOD;
			s[k].nxt0=nxt[x];s[k].nxt1=1ll*nxt[x]*ss%MOD;
		} return;
	} pushdown(k);int mid=l+r>>1;
	if(p<=mid) modify(s[k].ch[0],l,mid,p,x,ps,ss,v);
	else modify(s[k].ch[1],mid+1,r,p,x,ps,ss,v);
	pushup(k);
}
void modify_pre(int k,int l,int r,int ql,int qr,int x){
	if(ql>qr) return;
	if(ql<=l&&r<=qr){
		s[k].pre1=(s[k].pre1+1ll*x*s[k].pre0%MOD)%MOD;
		s[k].lz_pre=(s[k].lz_pre+x)%MOD;return;
	} pushdown(k);int mid=l+r>>1;
	if(qr<=mid) modify_pre(s[k].ch[0],l,mid,ql,qr,x);
	else if(ql>mid) modify_pre(s[k].ch[1],mid+1,r,ql,qr,x);
	else modify_pre(s[k].ch[0],l,mid,ql,mid,x),modify_pre(s[k].ch[1],mid+1,r,mid+1,qr,x);
	pushup(k);
}
void modify_nxt(int k,int l,int r,int ql,int qr,int x){
	if(ql>qr) return;
	if(ql<=l&&r<=qr){
		s[k].nxt1=(s[k].nxt1+1ll*x*s[k].nxt0%MOD)%MOD;
		s[k].lz_nxt=(s[k].lz_nxt+x)%MOD;return;
	} pushdown(k);int mid=l+r>>1;
	if(qr<=mid) modify_nxt(s[k].ch[0],l,mid,ql,qr,x);
	else if(ql>mid) modify_nxt(s[k].ch[1],mid+1,r,ql,qr,x);
	else modify_nxt(s[k].ch[0],l,mid,ql,mid,x),modify_nxt(s[k].ch[1],mid+1,r,mid+1,qr,x);
	pushup(k);
}
int get(int x){
	if(!query_cnt(rt[a[x]],1,cnt[a[x]],where[x],where[x])) return 0;
	int ret=0;
	ret=(ret+1ll*query_pre0(rt[a[x]],1,cnt[a[x]],1,where[x]-1)*
				 query_nxt0(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]]))%MOD;
	ret=(ret+1ll*nxt[x]*
		(1ll*(query_cnt(rt[a[x]],1,cnt[a[x]],1,where[x])-1)*
			  query_pre0(rt[a[x]],1,cnt[a[x]],1,where[x]-1)%MOD-
			  query_pre1(rt[a[x]],1,cnt[a[x]],1,where[x]-1)+MOD))%MOD;
	ret=(ret+1ll*pre[x]*
		(1ll*(query_cnt(rt[a[x]],1,cnt[a[x]],where[x],cnt[a[x]])-1)*
			  query_nxt0(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]])%MOD-
			  query_nxt1(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]])+MOD))%MOD;
	return ret;
}
void toggle(int x,int v){
	if(v==-1){
		modify(rt[a[x]],1,cnt[a[x]],where[x],x,0,0,-1);
		modify_pre(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]],MOD-1);
		modify_nxt(rt[a[x]],1,cnt[a[x]],1,where[x]-1,MOD-1);
	} else {
		int ps=query_cnt(rt[a[x]],1,cnt[a[x]],1,where[x]-1);
		int ss=query_cnt(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]]);
		modify(rt[a[x]],1,cnt[a[x]],where[x],x,ps+1,ss+1,1);
		modify_pre(rt[a[x]],1,cnt[a[x]],where[x]+1,cnt[a[x]],1);
		modify_nxt(rt[a[x]],1,cnt[a[x]],1,where[x]-1,1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];
	sort(key+1,key+n+1);
	for(int i=1;i<=n;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
	for(int i=1;i<=n;i++) add(a[i],1),pre[i]=ask(a[i])-1;memset(t,0,sizeof(t));
	for(int i=n;i;i--) add(a[i],1),nxt[i]=ask(a[i])-1;
	for(int i=1;i<=n;i++) pos[a[i]].push_back(i),where[i]=pos[a[i]].size();
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	for(int i=1;i<=num;i++) build(rt[i],1,cnt[i],i);
	int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+get(i))%MOD;
	ans=1ll*ans*INV3%MOD;
	int qu;scanf("%d",&qu);
	while(qu--){
		int opt,x;scanf("%d%d",&opt,&x);
		if(opt==1){
			ans=(ans-get(x)+MOD)%MOD;
			toggle(x,-1);
		} else {
			toggle(x,1);
			ans=(ans+get(x))%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
9
3 4 4 2 4 5 4 4 1
3
1 5
2 5
1 2
*/