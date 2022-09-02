#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define fi first
#define se second
#define ls t[v].lc,l,mid
#define ls2 t[u].lc,l,mid
#define rs t[v].rc,mid+1,r
#define rs2 t[u].rc,mid+1,r
#define lm l==mid?t[u].lc:t[t[u].lc].mx
#define rm mid+1==r?t[u].rc:t[t[u].rc].mx
typedef unsigned long long ull;typedef std::pair<int,int> pii;const int N=200005,M=N*40;
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
template<typename T>T max(const T&x,const T&y){return x>y?x:y;}
int n,m,q,ans,tot,rt[N];pii a[N];struct node{ull lc:23,rc:23,mx:18;}t[M];
int mdf(int v,int l,int r,int lx,int rx){
	if(l==r)return v+1;
	int u=++tot;t[u]=t[v];
	if(l==lx&&r==rx)return++t[u].mx,u;int mid=l+r>>1,tag=t[u].mx-max(lm,rm);
	if(rx<=mid)t[u].lc=mdf(ls,lx,rx);else if(mid<lx)t[u].rc=mdf(rs,lx,rx);else t[u].lc=mdf(ls,lx,mid),t[u].rc=mdf(rs,mid+1,rx);
	t[u].mx=max(lm,rm)+tag;return u;
}
int qry(int u,int l,int r,int lx,int rx){
	if(l==r)return u;
	if(l==lx&&r==rx)return t[u].mx;int mid=l+r>>1,tag=t[u].mx-max(lm,rm),res=0;
	if(rx<=mid)res=qry(ls2,lx,rx);else if(mid<lx)res=qry(rs2,lx,rx);else res=max(qry(ls2,lx,mid),qry(rs2,mid+1,rx));return res+tag;
}
int main(){
	scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&a[i].fi),a[i].fi=-a[i].fi,a[i].se=i;std::sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)rt[i]=mdf(rt[i-1],1,n-m+1,max(1,a[i].se-m+1),min(a[i].se,n-m+1));scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int l,r,x;scanf("%d%d%d",&l,&r,&x);x^=ans;
		int pos=std::upper_bound(a+1,a+1+n,std::make_pair(-x,n+1))-a-1;
		printf("%d\n",ans=m-qry(rt[pos],1,n-m+1,l,r));
	}
	return 0;
}