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
int n=read(),m=read();
vector<pair<int,int> > g[500005];
int L[500005],R[500005],dist[500005],idx=0;
inline void dfs1(int x,int fa){
	L[x]=++idx;
	foreach(it,g[x]){
		int y=it->first,z=it->second;
		if(y==fa)	continue;
		dist[y]=dist[x]+z;
		dfs1(y,x);
	}
	R[x]=idx;
}
struct Q{
	int v,l,r;
} q[500005];
vector<int> qvec[500005];
int ans[500005],offset=0,isLeaf[500005];
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[500005<<2];
	inline void pushdown(int k){
		if(!s[k].lz)	return;
		s[k<<1].lz+=s[k].lz;
		s[k<<1].val+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;
		s[k].lz=0;
	}
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].lz=0;
		if(l==r){
			if(isLeaf[l])	s[k].val=dist[l];
			else			s[k].val=1ll<<55;
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
//		cout<<l<<" "<<r<<" "<<s[k].val<<endl;
	}
	inline void modify(int k,int l,int r,int val){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].lz+=val;
			s[k].val+=val;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,val);
		else if(l>mid)	modify(k<<1|1,l,r,val);
		else			modify(k<<1,l,mid,val),modify(k<<1|1,mid+1,r,val);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(int k,int l,int r){
//		cout<<"l r k "<<s[k].l<<" "<<s[k].r<<" "<<s[k].val<<endl;
		if(l<=s[k].l&&s[k].r<=r){
//			cout<<l<<" "<<r<<" "<<s[k].val<<endl;
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} st;
inline void dfs2(int x,int fa,int w){
//	cout<<"x="<<x<<" "<<offset<<" "<<st.query(1,3,5)<<endl;
	st.modify(1,L[x],R[x],-2*w);
	offset+=w;
	foreach(it,qvec[x]){
		int ind=*it;
		ans[ind]=st.query(1,q[ind].l,q[ind].r)+offset;
	}
	foreach(it,g[x]){
		int y=it->first,z=it->second;
		if(y==fa)	continue;
		dfs2(y,x,z);
	}
	st.modify(1,L[x],R[x],2*w);
	offset-=w;
}
signed main(){
	fz(i,2,n){
		int u=read(),v=i,w=read();
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	fz(i,1,n)	sort(all(g[i]));
	fz(i,1,n)	isLeaf[i]=(g[i].size()==1);
	dfs1(1,0);
//	fz(i,1,n)	cout<<"dist["<<i<<"]="<<dist[i]<<endl;
	st.build(1,1,n);
	fz(i,1,m){
		q[i].v=read();q[i].l=read();q[i].r=read();
		qvec[q[i].v].push_back(i);
	}
	dfs2(1,0,0);
	fz(i,1,m)	print(ans[i]),eoln;
	return 0;
}//