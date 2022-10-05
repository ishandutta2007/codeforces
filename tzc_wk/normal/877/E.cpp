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
int n=read(),a[200005];
vector<int> g[200005];
int idx,id[200005],L[200005],R[200005];
inline void dfs(int x){
	L[x]=++idx;
	id[idx]=x;
	foreach(it,g[x]){
		dfs(*it);
	}
	R[x]=idx;
}
struct SegTree{
	struct node{
		int l,r,val;
		bool lz;
	} s[200005<<2];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=a[id[l]];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=s[k<<1].val+s[k<<1|1].val; 
	}
	inline void pushdown(int k){
		if(s[k].lz){
			s[k<<1].val=s[k<<1].r-s[k<<1].l+1-s[k<<1].val;
			s[k<<1].lz^=1;
			s[k<<1|1].val=s[k<<1|1].r-s[k<<1|1].l+1-s[k<<1|1].val;
			s[k<<1|1].lz^=1;
			s[k].lz=0;
		}
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
	inline void modify(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val=s[k].r-s[k].l+1-s[k].val;
			s[k].lz^=1;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r);
		else if(l>mid)	modify(k<<1|1,l,r);
		else			modify(k<<1,l,mid),modify(k<<1|1,mid+1,r);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
} st;
signed main(){
	for(int i=2;i<=n;i++){
		int x=read();
		g[x].push_back(i);
	}
	for(int i=1;i<=n;i++)	a[i]=read();
	dfs(1);
	st.build(1,1,n);
	int q=read();
	while(q--){
		char opt[15];scanf("%s",opt+1);
		if(opt[1]=='p'){
			int x=read();
			st.modify(1,L[x],R[x]);
		}
		else{
			int x=read();
			cout<<st.query(1,L[x],R[x])<<endl;
		}
	}
}