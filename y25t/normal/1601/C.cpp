#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define N 1000005

int T;

int n,m,a[N],b[N];

int val[N],tot;

int tt[N];
inline int lb(int x){
	return x&-x;
}
inline void Add(int x,int d){
	for(;x<=tot;x+=lb(x))
		tt[x]+=d;
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res+=tt[x];
	return res;
}

struct node{
	int mn,add;
}t[N<<2];
inline void psh(int p,int d){
	t[p].mn+=d,t[p].add+=d;
}
inline void pshd(int p){
	psh(p<<1,t[p].add),psh(p<<1|1,t[p].add);
	t[p].add=0;
}
inline void build(int p,int L,int R){
	t[p].add=0;
	if(L==R)
		return t[p].mn=L,void();
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
	t[p].mn=std::min(t[p<<1].mn,t[p<<1|1].mn);
}
inline void add(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r)
		return psh(p,d),void();
	pshd(p);
	int mid=(L+R)>>1;
	add(p<<1,L,mid,l,r,d),add(p<<1|1,mid+1,R,l,r,d);
	t[p].mn=std::min(t[p<<1].mn,t[p<<1|1].mn);
}
inline int mn(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return inf;
	if(l<=L&&R<=r)
		return t[p].mn;
	pshd(p);
	int mid=(L+R)>>1;
	return std::min(mn(p<<1,L,mid,l,r),mn(p<<1|1,mid+1,R,l,r));
}

int p[N];

ll ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			val[++tot]=a[i];
		}
		std::sort(val+1,val+tot+1),tot=std::unique(val+1,val+tot+1)-val-1;
		for(int i=1;i<=tot;i++)
			tt[i]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			int x=std::lower_bound(val+1,val+tot+1,a[i])-val;
			Add(x,1);
			ans+=i-sum(x);
		}
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		std::sort(b+1,b+m+1);
		build(1,0,n);
		std::iota(p+1,p+n+1,1);
		std::sort(p+1,p+n+1,[&](int i,int j){
			return a[i]<a[j];
		});
		for(int i=1,j=0,k=0,cnt=0;i<=m;i++){
			while(k<n&&a[p[k+1]]<=b[i])
				add(1,0,n,p[++k],n,-1);
			while(j<n&&a[p[j+1]]<b[i])
				cnt++,add(1,0,n,p[++j],n,-1);
			ans+=cnt+t[1].mn;
		}
		printf("%lld\n",ans);
	}
}