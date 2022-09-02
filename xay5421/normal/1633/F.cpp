#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
namespace fenwick_helper{

template<class T>
T plus(const T&x,const T&y){
	return x+y;
}
template<class T>
T multiplies(const T&x,const T&y){
	return x*y;
}
template<class T>
T bit_xor(const T&x,const T&y){
	return x^y;
}
template<class T>
T min(const T&x,const T&y){
	return x<y?x:y;
}
template<class T>
T max(const T&x,const T&y){
	return x<y?y:x;
}
template<class T>
T e(){
	return T();
}

}
template<class T,T (*op)(const T&,const T&)=fenwick_helper::plus<T>,T (*e)()=fenwick_helper::e<T> >
struct fenwick{
	int n;
	vector<T>t;
	fenwick():n(0),t(0){}
	fenwick(int n):n(n),t(n,e()){}
	void assign(int n_){n=n_,t.assign(n_,e());}
	void add(int x,const T&y){ // 0<=x
		++x;
		for(int i=x;i<=n;i+=i&-i)t[i-1]=op(t[i-1],y);
	}
	void add(int l,int r,const T&x){ // [l,r]
		add(l,x);
		add(r+1,-x);
	}
	T query(int x){ // x<n
		++x;
		T y=e();
		for(int i=x;i>0;i&=i-1)y=op(y,t[i-1]);
		return y;
	}
	T query(int l,int r){ // [l,r]
		return op(query(r),-query(l-1)); // operator-()
	}
	void add2(int x,const T&y){ // x<n
		++x;
		for(int i=x;i>0;i&=i-1)t[i-1]=op(t[i-1],y);
	}
	T query2(int x){ // 0<=x
		++x;
		T y=e();
		for(int i=x;i<=n;i+=i&-i)y=op(y,t[i-1]);
		return y;
	}
};
/*
T unite(const T&x,const T&y){
	
}
fenwick_helper::plus<T>
fenwick_helper::multiplies<T>
fenwick_helper::bit_xor<T>
fenwick_helper::min<T>
fenwick_helper::max<T>

T zero(){
	
}

unite=plus<T>
zero=T()
fenwick<T,unite,zero>
*/
const int N=200005;
int n,sz[N],son[N],fa[N],dep[N],bel[N],ind,tin[N],tou[N],ord[N],eid[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	fa[k1]=k2,dep[k1]=dep[k2]+1,sz[k1]=1;
	each(x,e[k1])if(x!=k2){
		dfs1(x,k1),sz[k1]+=sz[x];
		if(sz[x]>sz[son[k1]])son[k1]=x;
	}
}
void dfs2(int k1){
	tin[k1]=++ind,ord[ind]=k1;
	if(son[k1]){
		bel[son[k1]]=bel[k1];
		dfs2(son[k1]);
	}
	each(x,e[k1])if(x!=fa[k1]&&x!=son[k1]){
		bel[x]=x;
		dfs2(x);
	}
	tou[k1]=ind;
}
struct segTree1{
	int cnt[N*4][2];
	long long sum[N*4][2];
	int tg[N*4];
	void upd(int k1){
		cnt[k1][0]=cnt[k1*2][0]+cnt[k1*2+1][0];
		cnt[k1][1]=cnt[k1*2][1]+cnt[k1*2+1][1];
		sum[k1][0]=sum[k1*2][0]+sum[k1*2+1][0];
		sum[k1][1]=sum[k1*2][1]+sum[k1*2+1][1];
	}
	void bud(int k1,int k2,int k3){
		tg[k1]=0;
		if(k2==k3){
			cnt[k1][0]=0;
			cnt[k1][1]=k2>1;
			sum[k1][0]=0;
			sum[k1][1]=eid[ord[k2]];
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void pst(int k1){
		tg[k1]^=1,swap(cnt[k1][0],cnt[k1][1]),swap(sum[k1][0],sum[k1][1]);
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2);
			pst(k1*2+1);
			tg[k1]=0;
		}
	}
	void flip(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		flip(k1*2,k2,mid,k4,k5),flip(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
}tr1;
struct segTree2{
	int mx[N*4][2];
	int tg[N*4];
	void upd(int k1){
		mx[k1][0]=max(mx[k1*2][0],mx[k1*2+1][0]);
		mx[k1][1]=max(mx[k1*2][1],mx[k1*2+1][1]);
	}
	void bud(int k1,int k2,int k3){
		tg[k1]=0;
		if(k2==k3){
			mx[k1][0]=0;
			mx[k1][1]=k2>1;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void pst(int k1){
		tg[k1]^=1,swap(mx[k1][0],mx[k1][1]);
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2);
			pst(k1*2+1);
			tg[k1]=0;
		}
	}
	void add(int k1,int k2,int k3,int k4,int k5){
		//if(k1==1)D("add %d %d\n",k4,k5);
		if(k2==k3){
			mx[k1][0]+=k5;
			mx[k1][1]+=k5;
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		if(k4<=mid)add(k1*2,k2,mid,k4,k5);
		else add(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	void flip(int k1,int k2,int k3,int k4,int k5){
		//if(k1==1)D("flip %d %d\n",k4,k5);
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		flip(k1*2,k2,mid,k4,k5);
		flip(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
}tr2;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	vector<pair<int,int> >es;
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
		es.eb(u,v);
	}
	dfs1(1,0);
	bel[1]=1;
	dfs2(1);
	rep(i,0,SZ(es)-1){
		int u,v;
		tie(u,v)=es[i];
		if(dep[u]<dep[v])swap(u,v);
		eid[u]=i+1;
	}
	tr1.bud(1,1,n);
	tr2.bud(1,1,n);
	fenwick<int>sizes(n+1);
	auto query_size=[&](int u){
		return sizes.query(tin[u],tou[u]);
	};
	int tot=1;
	sizes.add(1,1);
	bool last=0;
	while(1){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int u;
			scanf("%d",&u);
			++tot;
			int old_u=u;
			int old_size=0;
			while(u){
				tr1.flip(1,1,n,tin[bel[u]],tin[u]);
				if(old_size){
					if(old_size&1){
						tr2.add(1,1,n,tin[u],-1);
					}else{
						tr2.add(1,1,n,tin[u],1);
					}
				}
				if(u!=bel[u]){
					tr2.flip(1,1,n,tin[bel[u]],tin[u]-1);
				}
				old_size=query_size(bel[u]);
				u=fa[bel[u]];
			}
			sizes.add(tin[old_u],1);
			if(tot&1){
				last=0;
				puts("0");
			}else{
				if(tr1.cnt[1][0]==tot/2&&tr2.mx[1][0]<=1){
					last=1;
					printf("%lld\n",tr1.sum[1][0]);
				}else{
					last=0;
					puts("0");
				}
			}
		}else if(opt==2){
			if(!last){
				puts("0");
			}else{
				printf("%d ",tot/2);
				rep(i,0,SZ(es)-1){
					int u,v;
					tie(u,v)=es[i];
					if(dep[u]<dep[v])swap(u,v);
					if(query_size(u)&1){
						printf("%d ",i+1);
					}
				}
				puts("");
			}
		}else{
			break;
		}
		fflush(stdout);
	}
	return 0;
}