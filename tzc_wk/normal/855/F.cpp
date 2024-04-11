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
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
int qu;set<int> ban1,ban2;
struct segtree{
	struct node{int l,r,mx,smx,c;ll sum,tag;} s[MAXN*4+5];
	void pushup(int k){
		s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
		s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
		if(s[k<<1].mx>s[k<<1|1].mx){
			s[k].smx=max(s[k<<1|1].mx,s[k<<1].smx);
			s[k].c=s[k<<1].c;
		} else if(s[k<<1].mx<s[k<<1|1].mx){
			s[k].smx=max(s[k<<1].mx,s[k<<1|1].smx);
			s[k].c=s[k<<1|1].c;
		} else {
			s[k].smx=max(s[k<<1].smx,s[k<<1|1].smx);
			s[k].c=s[k<<1].c+s[k<<1|1].c;
		}
	}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return s[k].mx=INF,s[k].smx=0,void();
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
	}
	void pushtag(int k,ll v){s[k].sum+=1ll*v*s[k].c;s[k].tag+=v;s[k].mx+=v;}
	void pushdown(int k){
		if(s[k].tag){
			bool tmp=s[k<<1|1].mx>=s[k<<1].mx;
			if(s[k<<1].mx>=s[k<<1|1].mx) pushtag(k<<1,s[k].tag);
			if(tmp) pushtag(k<<1|1,s[k].tag);s[k].tag=0;
		}
	}
	void modify(int k,int l,int r,int v){
		if(l>r||v>=s[k].mx) return;
		if(l<=s[k].l&&s[k].r<=r){
			if(v>s[k].smx) return pushtag(k,v-s[k].mx),void();
			else{
				int mid=(pushdown(k),l+r>>1);
				return modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v),pushup(k),void();
			}
		} int mid=(pushdown(k),s[k].l+s[k].r>>1);
		if(r<=mid) modify(k<<1,l,r,v);
		else if(l>mid) modify(k<<1|1,l,r,v);
		else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
		pushup(k);
	}
	ll query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].sum;
		int mid=(pushdown(k),s[k].l+s[k].r>>1);
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
	void turn(int k,int v){
		if(s[k].l==s[k].r) return s[k].c=1,s[k].sum=s[k].mx,void();
		int mid=(pushdown(k),s[k].l+s[k].r>>1);
		((v<=mid)?turn(k<<1,v):turn(k<<1|1,v)),pushup(k);
	}
} s1,s2;
int cnt[MAXN+5];
void del(set<int> &st,int l,int r){
	while(1){
		int val=*st.lower_bound(l);
		if(val>r) break;st.erase(st.find(val));cnt[val]++;
		if(cnt[val]>>1) s1.turn(1,val),s2.turn(1,val);
	}
}
int main(){
	scanf("%d",&qu);s1.build(1,1,MAXN);s2.build(1,1,MAXN);
	for(int i=1;i<=MAXN+1;i++) ban1.insert(i),ban2.insert(i);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r,v;scanf("%d%d%d",&l,&r,&v);--r;
			if(~v>>31) s1.modify(1,l,r,v),del(ban1,l,r);
			else s2.modify(1,l,r,-v),del(ban2,l,r);
		} else {
			int l,r;scanf("%d%d",&l,&r);--r;
			printf("%lld\n",s1.query(1,l,r)+s2.query(1,l,r));
		}
	}
	return 0;
}