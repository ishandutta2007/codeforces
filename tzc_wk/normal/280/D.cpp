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
int n,qu,a[MAXN+5];
struct dat{
	int sum;
	pii pre_mx,suf_mx;
	pair<int,pii> mx;
	dat(int x=0,int pos=0){
		sum=x;
		if(x>=0) pre_mx=mp(x,pos),suf_mx=mp(x,pos),mx=mp(x,mp(pos,pos));
		else pre_mx=mp(0,pos-1),suf_mx=mp(0,pos+1),mx=mp(0,mp(pos,pos+1));
	}
	dat operator +(const dat &rhs){
		dat res;res.sum=sum+rhs.sum;
		res.pre_mx=max(pre_mx,mp(rhs.pre_mx.fi+sum,rhs.pre_mx.se));
		res.suf_mx=max(rhs.suf_mx,mp(suf_mx.fi+rhs.sum,suf_mx.se));
		res.mx=max(max(mx,rhs.mx),mp(suf_mx.fi+rhs.pre_mx.fi,
		mp(suf_mx.se,rhs.pre_mx.se)));
		return res;
	}
};
struct node{int l,r;dat mx,mn;} s[MAXN*4+5];
void pushup(int k){
	s[k].mx=s[k<<1].mx+s[k<<1|1].mx;
	s[k].mn=s[k<<1].mn+s[k<<1|1].mn;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].mx=dat(a[l],l),s[k].mn=dat(-a[l],l),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void modify(int k,int p,int v){
	if(s[k].l==s[k].r) return s[k].mx=dat(v,p),s[k].mn=dat(-v,p),void();
	int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,v):modify(k<<1|1,p,v);
	pushup(k);
}
dat query_mx(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mx;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query_mx(k<<1,l,r);
	else if(l>mid) return query_mx(k<<1|1,l,r);
	else return query_mx(k<<1,l,mid)+query_mx(k<<1|1,mid+1,r);
}
dat query_mn(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query_mn(k<<1,l,r);
	else if(l>mid) return query_mn(k<<1|1,l,r);
	else return query_mn(k<<1,l,mid)+query_mn(k<<1|1,mid+1,r);
}
struct itvl_mx{
	int l,r,val;
	itvl_mx(){l=r=val=0;}
	itvl_mx(int _l,int _r){l=_l;r=_r;val=query_mx(1,l,r).mx.fi;}
	bool operator <(const itvl_mx &rhs) const{return val<rhs.val;}
};
struct itvl_mn{
	int l,r,val;
	itvl_mn(){l=r=val=0;}
	itvl_mn(int _l,int _r){l=_l;r=_r;val=-query_mn(1,l,r).mx.fi;}
	bool operator <(const itvl_mn &rhs) const{return val>rhs.val;}
};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);scanf("%d",&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==0){
			int x,v;scanf("%d%d",&x,&v);
			modify(1,x,v);
		} else {
			int l,r,k,res=0;scanf("%d%d%d",&l,&r,&k);
			priority_queue<itvl_mx> q1;
			priority_queue<itvl_mn> q2;
			q1.push(itvl_mx(l,r));
			while((!q1.empty()||!q2.empty())&&k--){
				if(q2.empty()||(!q1.empty()&&q1.top().val>=-q2.top().val)){
					itvl_mx p=q1.top();q1.pop();if(p.val<=0) break;
					dat d=query_mx(1,p.l,p.r);res+=p.val;
					int L=d.mx.se.fi,R=d.mx.se.se;
					if(L!=p.l) q1.push(itvl_mx(p.l,L-1));
					if(R!=p.r) q1.push(itvl_mx(R+1,p.r));
					q2.push(itvl_mn(L,R));
				} else {
					itvl_mn p=q2.top();q2.pop();if(p.val>=0) break;
					dat d=query_mn(1,p.l,p.r);res-=p.val;
					int L=d.mx.se.fi,R=d.mx.se.se;
					if(L!=p.l) q2.push(itvl_mn(p.l,L-1));
					if(R!=p.r) q2.push(itvl_mn(R+1,p.r));
					q1.push(itvl_mx(L,R));
				}
			} printf("%d\n",res);
		}
	}
	return 0;
}
/*
9
9 -8 9 -1 -1 -1 9 -8 9
1
1 1 1 1
*/