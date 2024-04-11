#include<cstdio>
#include<algorithm>
#define int long long
#define N 100005
#define B 333
#define C (N/B+5)

int n,q;

int fa[N];

int tot,bel[N],L[N],R[N],mx[C],tag[C],top[N];
inline void upd(int x){
	mx[x]=0;
	for(int i=L[x];i<=R[x];i++)
		mx[x]=std::max(mx[x],fa[i]);
	for(int i=L[x];i<=R[x];i++)
		top[i]=fa[i]<L[x]?i:top[fa[i]];
}
inline void build(){
	for(int i=1;i<=n;i++){
		if(i%B==1){
			tot++;
			L[tot]=i;
		}
		bel[i]=tot;
		R[tot]=i;
	}
	for(int i=1;i<=tot;i++)
		upd(i);
}
inline void chg(int l,int r,int d){
	int x=bel[l],y=bel[r];
	if(x==y){
		for(int i=l;i<=r;i++)
			fa[i]=std::max(fa[i]-d,1ll);
		upd(x);
		return;
	}
	for(int i=x+1;i<y;i++)
		if(mx[i]<L[i])
			tag[i]-=d;
		else{
			for(int j=L[i];j<=R[i];j++)
				fa[j]=std::max(fa[j]-d,1ll);
			upd(i);
		}
	for(int i=l;i<=R[x];i++)
		fa[i]=std::max(fa[i]-d,1ll);
	upd(x);
	for(int i=L[y];i<=r;i++)
		fa[i]=std::max(fa[i]-d,1ll);
	upd(y);
}
inline int qry(int u,int v){
	while(top[u]!=top[v]){
		if(top[u]<top[v])
			std::swap(u,v);
		u=std::max(fa[top[u]]+tag[bel[u]],1ll);
	}
	while(u!=v){
		if(u<v)
			std::swap(u,v);
		u=std::max(fa[u]+tag[bel[u]],1ll);
	}
	return u;
}

signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i=2;i<=n;i++)
		scanf("%lld",&fa[i]);
	build();
	while(q--){
		int opt;
		scanf("%lld",&opt);
		if(opt==1){
			int l,r,d;
			scanf("%lld%lld%lld",&l,&r,&d);
			chg(l,r,d);
		}
		else{
			int u,v;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",qry(u,v));
		}
	}
}