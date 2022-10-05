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
int def_mn[1000005],att_mn[1000005];
int n=read(),m=read(),p=read();
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[1000005<<2];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=-def_mn[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=max(s[k<<1].val,s[k<<1|1].val);
	}
	inline void pushdown(int k){
		s[k<<1].val+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
	inline void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val+=x;
			s[k].lz+=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=max(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(){
		return s[1].val;
	}
} st;
struct A{
	int a,b,c;
	friend bool operator <(A x,A y){
		return x.a<y.a;
	}
} a[200005];
signed main(){
	fillbig(def_mn);fillbig(att_mn);
	fz(i,1,n){
		int x=read(),y=read();
		att_mn[x]=min(att_mn[x],y);
	}
	fz(i,1,m){
		int x=read(),y=read();
		def_mn[x]=min(def_mn[x],y);
	}
	fd(i,1000000,0){
		def_mn[i]=min(def_mn[i+1],def_mn[i]);
		att_mn[i]=min(att_mn[i+1],att_mn[i]);
	}
	fz(i,1,p){
		a[i].a=read();a[i].b=read();a[i].c=read();
	}
//	fz(i,1,10)	cout<<def_mn[i]<<" "<<att_mn[i]<<endl;
	sort(a+1,a+p+1);
	st.build(1,1,1000001);
	int ans=-att_mn[1]-def_mn[1];
	fz(i,1,p){
		st.modify(1,a[i].b+1,1000001,a[i].c);
		ans=max(ans,st.query()-att_mn[a[i].a+1]);
//		cout<<st.query()<<" "<<att_mn[a[i].a+1]<<endl;
	}
	print(ans);eoln;
	return 0;
}