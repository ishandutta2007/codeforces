#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 500005

int n,m;
ll a[N],b[N],c[N];

std::vector<std::tuple<int,int,int>> V[N],U[N];

int id[N];

struct node{
	ll mn,tag,res;
}t[N<<2];
inline void upd(int p){
	t[p].mn=std::min(t[p<<1].mn,t[p<<1|1].mn);
	t[p].res=std::max(t[p].tag-t[p].mn,std::max(t[p<<1].res,t[p<<1|1].res));
}
inline void build(int p,int L,int R){
	t[p].tag=-inf,t[p].mn=inf,t[p].res=-inf;
	if(L==R)
		return;
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
}
inline void chg(int p,int L,int R,int x,ll d){
	if(L==R)
		return t[p].mn=d,t[p].res=std::max(-inf,t[p].res-d),void();
	int mid=(L+R)>>1;
	x<=mid?chg(p<<1,L,mid,x,d):chg(p<<1|1,mid+1,R,x,d);
	upd(p);
}
inline void cmx(int p,int L,int R,int l,int r,ll d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r)
		return t[p].tag=std::max(t[p].tag,d),t[p].res=std::max(t[p].res,t[p].tag-t[p].mn),void();
	int mid=(L+R)>>1;
	cmx(p<<1,L,mid,l,r,d),cmx(p<<1|1,mid+1,R,l,r,d);
	upd(p);
}
inline ll sch(int p,int L,int R,int l,int r,ll d=-inf){
	if(L>r||R<l)
		return -inf;
	if(l<=L&&R<=r)
		return std::max(t[p].res,t[p].tag-t[p].mn);
	int mid=(L+R)>>1;
	d=std::max(d,t[p].tag);
	return std::max(sch(p<<1,L,mid,l,r,d),sch(p<<1|1,mid+1,R,l,r,d));
}

ll T[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,ll d){
	for(;x;x-=lb(x))
		T[x]=std::max(T[x],d);
}
inline ll sum(int x){
	ll res=-inf;
	for(;x<=n;x+=lb(x))
		res=std::max(res,T[x]);
	return res;
}

ll f[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]),b[i]+=b[i-1];
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(int i=n;i;i--)
		c[i]+=c[i+1];
	for(int i=1;i<=n;i++)
		a[i]-=b[i-1],c[i]+=b[i];
	for(int i=1;i<=m;i++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		V[l].emplace_back(r,x,i);
		U[r].emplace_back(l,x,i);
	}
	m=0;
	for(int i=1;i<=n;i++)
		for(auto [r,x,o]:V[i])
			id[o]=++m;
	build(1,1,m);
	for(int i=1;i<=n;i++)
		T[i]=-inf;
	ll ans=-inf;
	for(int i=1,tmp=0;i<=n;i++){
		for(auto [l,x,o]:U[i-1])
			chg(1,1,m,id[o],inf);
		for(auto [r,x,o]:V[i])
			chg(1,1,m,id[o],x),tmp=std::max(tmp,id[o]);
		cmx(1,1,m,1,tmp,a[i]);
		f[i]=std::max(sum(i),sch(1,1,m,1,tmp));
		for(auto [r,x,o]:V[i+1])
			add(r,f[i]-x);
		ans=std::max(ans,f[i]+c[i]);
	}
	printf("%lld\n",ans);
}