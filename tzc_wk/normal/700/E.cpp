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
const int MAXN=2e5;
const int LOG_N=19;
const int INF=0x3f3f3f3f;
int n;char s[MAXN+5];pii x[MAXN+5];
int sa[MAXN+5],rk[MAXN+5],buc[MAXN+5],seq[MAXN+5],ht[MAXN+5];
int st[MAXN+5][LOG_N+2];
void getsa(){
	int vmax=122,gr=0;
	for(int i=1;i<=n;i++) buc[s[i]]++;
	for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
	for(int i=n;i;i--) sa[buc[s[i]]--]=i;
	for(int i=1;i<=n;i++){
		if(s[sa[i]]!=s[sa[i-1]]) gr++;
		rk[sa[i]]=gr;
	} vmax=gr;
	for(int k=1;k<=n;k<<=1){
		for(int i=1;i<=n;i++){
			if(i+k<=n) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));gr=0;int num=0;
		for(int i=n-k+1;i<=n;i++) seq[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=n;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=n;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=n;i++){
			if(x[sa[i]]!=x[sa[i-1]]) gr++;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==n) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(rk[i]==1) continue;if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
void buildst(){
	for(int i=1;i<=n;i++) st[i][0]=ht[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
}
int getlcp(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
pii get_interval(int x,int k){
	int L=1,R=x-1,l=x,r=x;
	while(L<=R){
		int mid=L+R>>1;
		if(getlcp(mid+1,x)>=k) l=mid,R=mid-1;
		else L=mid+1;
	} L=x+1;R=n;
	while(L<=R){
		int mid=L+R>>1;
		if(getlcp(x+1,mid)>=k) r=mid,L=mid+1;
		else R=mid-1;
	} return mp(l,r);
}
struct data{
	int f,len;
	data(){f=len=0;}
	data(int _f,int _len){f=_f;len=_len;}
	bool operator !=(const data &rhs){return f!=rhs.f||len!=rhs.len;}
	bool operator <(const data &rhs){
		if(f!=rhs.f) return f<rhs.f;
		return len>rhs.len;
	}
};
data max(data lhs,data rhs){return (lhs<rhs)?rhs:lhs;}
struct segtree1{
	struct node{int l,r;data v,lz;} s[MAXN*4+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		if(s[k].lz!=data(0,0)){
			s[k<<1].v=max(s[k<<1].v,s[k].lz);s[k<<1].lz=max(s[k<<1].lz,s[k].lz);
			s[k<<1|1].v=max(s[k<<1|1].v,s[k].lz);s[k<<1|1].lz=max(s[k<<1|1].lz,s[k].lz);
			s[k].lz=data(0,0);
		}
	}
	void modify(int k,int l,int r,data x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].v=max(s[k].v,x);s[k].lz=max(s[k].lz,x);
			return;
		} pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,x);
		else if(l>mid) modify(k<<1|1,l,r,x);
		else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].v=max(s[k<<1].v,s[k<<1|1].v);
	}
	data query(int k,int x){
		if(s[k].l==s[k].r) return s[k].v;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(x<=mid) return query(k<<1,x);
		else return query(k<<1|1,x);
	}
} st1;
struct segtree2{
	struct node{int l,r,v;} s[MAXN*4+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].v=INF;if(l==r) return;
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void modify(int k,int p,int x){
		if(s[k].l==s[k].r){s[k].v=x;return;}
		int mid=s[k].l+s[k].r>>1;
		if(p<=mid) modify(k<<1,p,x);
		else modify(k<<1|1,p,x);
		s[k].v=min(s[k<<1].v,s[k<<1|1].v);
	}
	int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].v;
		int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} st2;
int main(){
	scanf("%d%s",&n,s+1);getsa();getht();buildst();
	st1.build(1,1,n);st2.build(1,1,n);int ans=0;
	for(int i=n;i;i--){
		data d=st1.query(1,rk[i]);
		data nd;nd.f=d.f+1;
		if(nd.f==1) nd.len=1;
		else{
			pii p=get_interval(rk[i],d.len);
			int id=st2.query(1,p.fi,p.se);
			nd.len=id-i+d.len;
		} chkmax(ans,nd.f);
//		printf("%d %d %d\n",i,nd.f,nd.len);
		pii q=get_interval(rk[i],nd.len);
		st1.modify(1,q.fi,q.se,nd);
		st2.modify(1,rk[i],i);
	} printf("%d\n",ans);
	return 0;
}