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
const int MAXN=1e5;
const int MAXV=2e5;
const int MAXP=MAXN<<7;
const int LOG_N=17;
const int MOD=1e9+7;
int n,qu,a[MAXN+5];
int pr[MAXV/6+5],prcnt=0,mnp[MAXV+5];
bitset<MAXV+5> vis;
vector<pii> ps[MAXV+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i,mnp[i]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
struct node{int ch[2],val;} s[MAXP+5];
int rt[MAXN+5],ncnt=0;
void pushup(int k){s[k].val=1ll*s[s[k].ch[0]].val*s[s[k].ch[1]].val%MOD;}
void insert_in(int &k,int l,int r,int p,int v){
	if(!k) k=++ncnt,s[k].val=1;
	if(l==r) return s[k].val=1ll*s[k].val*v%MOD,void();
	int mid=l+r>>1;
	if(p<=mid) insert_in(s[k].ch[0],l,mid,p,v);
	else insert_in(s[k].ch[1],mid+1,r,p,v);
	pushup(k);
}
void insert(int x,int l,int r,int v){
	int iv=qpow(v,MOD-2);
	for(int i=x;i<=n;i+=(i&(-i))){
		insert_in(rt[i],1,n,l,v);
		if(r!=n) insert_in(rt[i],1,n,r+1,iv);
	}
}
int query_in(int k,int l,int r,int ql,int qr){
	if(!k) return 1;if(ql<=l&&r<=qr) return s[k].val;
	int mid=l+r>>1;
	if(qr<=mid) return query_in(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query_in(s[k].ch[1],mid+1,r,ql,qr);
	else return 1ll*query_in(s[k].ch[0],l,mid,ql,mid)*query_in(s[k].ch[1],mid+1,r,mid+1,qr)%MOD;
}
int query(int x,int y){
	int ret=1;
	for(;x;x&=(x-1)) ret=1ll*ret*query_in(rt[x],1,n,1,y)%MOD;
	return ret;
}
void add(int l1,int r1,int l2,int r2,int v){
//	printf("%d %d %d %d %d\n",l1,r1,l2,r2,v);
	insert(l1,l2,r2,v);if(r1^n) insert(r1+1,l2,r2,qpow(v,MOD-2));
}
int st[27][MAXN+5][LOG_N+2];
int query_st(int x,int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return max(st[x][l][k],st[x][r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n,&qu);sieve(MAXV);s[0].val=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		while(tmp^1){
			int p=mnp[tmp],cnt=0;
			while(tmp%p==0) tmp/=p,cnt++;
			ps[p].pb(mp(cnt,i));
		}
	}
	for(int i=1;i<=25;i++){
		for(pii p:ps[pr[i]]) st[i][p.se][0]=p.fi;
		for(int j=1;j<=LOG_N;j++) for(int k=1;k+(1<<j)-1<=n;k++)
			st[i][k][j]=max(st[i][k][j-1],st[i][k+(1<<j-1)][j-1]);
	}
	for(int i=101;i<=MAXV;i++) if(!ps[i].empty()){
		sort(ps[i].begin(),ps[i].end());
		reverse(ps[i].begin(),ps[i].end());
		set<int> st;st.insert(0);st.insert(n+1);
		for(pii p:ps[i]){
			st.insert(p.se);
			set<int>::iterator it=st.find(p.se);
			int pre=*--it,nxt=*++ ++it;
//			printf("%d %d\n",pre,nxt);
			add(pre+1,p.se,p.se,nxt-1,qpow(i,p.fi));
		}
	} scanf("%d",&qu);int pre=0;
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);
		x=(x+pre)%n+1;y=(y+pre)%n+1;
		if(x>y) swap(x,y);
//		printf("%d %d\n",x,y);
		pre=query(x,y);
		for(int i=1;i<=25;i++) pre=1ll*pre*qpow(pr[i],query_st(i,x,y))%MOD;
		printf("%d\n",pre);
	}
	return 0;
}