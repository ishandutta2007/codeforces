//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
struct SegTree{
	struct node{
		int l,r,val,sum,lz;
		bool is_same;
	} s[100005<<2];
	inline void pushup(int k){
		if(s[k<<1].is_same&&s[k<<1|1].is_same&&s[k<<1].val==s[k<<1|1].val){
			s[k].is_same=1;
			s[k].val=s[k<<1].val;
		}
		else{
			s[k].is_same=0;
			s[k].val=0;
		}
		s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
	}
	inline void pushdown(int k){
		if(s[k].lz){
			s[k<<1].is_same=1;
			s[k<<1].lz+=s[k].lz;
			s[k<<1].sum+=(s[k<<1].r-s[k<<1].l+1)*s[k].lz;
			s[k<<1].val=s[k].val;
			s[k<<1|1].is_same=1;
			s[k<<1|1].lz+=s[k].lz;
			s[k<<1|1].sum+=(s[k<<1|1].r-s[k<<1|1].l+1)*s[k].lz;
			s[k<<1|1].val=s[k].val;
			s[k].lz=0;
		}
	}
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].is_same=1;
			s[k].val=l;
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	inline void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r&&s[k].is_same){
			s[k].lz+=abs(s[k].val-x);
			s[k].sum+=(s[k].r-s[k].l+1)*abs(s[k].val-x);
			s[k].val=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		pushup(k);
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].sum;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
} st;
int n=read(),m=read();
signed main(){
	st.build(1,1,n);
	while(m--){
		int opt=read();
		if(opt==1){
			int x=read(),y=read(),c=read();
			st.modify(1,x,y,c);
		}
		else{
			int x=read(),y=read();
			cout<<st.query(1,x,y)<<endl;
		}
	}
	return 0;
}