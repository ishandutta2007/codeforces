#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,X=1000000007;
int n,r;
struct node{
	int h,t;
	bool operator<(const node&rhs)const{
		return t<rhs.t;
	}
}a[N];
int root;
struct segTree{
	const static int M=N*40;
	int ind,tg[M],mx[M],lc[M],rc[M];
	void upd(int u){
		mx[u]=max(mx[lc[u]],mx[rc[u]])+tg[u];
	}
	void set(int&u,int l,int r,int x,int y){
		if(!u){
			u=++ind;
		}
		if(l==r){
			tg[u]=mx[u]=y;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)set(lc[u],l,mid,x,y);
		else set(rc[u],mid+1,r,x,y);
		assert(tg[u]==0);
		upd(u);
	}
	void set(int x,int y){
		set(root,0,X,x,y);
	}
	void add(int&u,int l,int r,int ll,int rr,int x){
		if(l>rr||r<ll||!u)return;
		if(ll<=l&&r<=rr){
			tg[u]+=x,mx[u]+=x;
			return;
		}
		int mid=(l+r)>>1;
		add(lc[u],l,mid,ll,rr,x),add(rc[u],mid+1,r,ll,rr,x);
		upd(u);
	}
	int res;
	void ask(int&u,int l,int r,int ll,int rr,int x){
		if(l>rr||r<ll||!u)return;
		if(ll<=l&&r<=rr){
			res=max(res,mx[u]+x);
			return;
		}
		int mid=(l+r)>>1;
		ask(lc[u],l,mid,ll,rr,x+tg[u]),ask(rc[u],mid+1,r,ll,rr,x+tg[u]);
	}
	int ask(int r){
		if(r<0)return 0;
		res=0;
		ask(root,0,X,0,r,0);
		return res;
	}
	int ask(int l,int r){
		assert(l<=r);
		assert(l>=0);
		assert(r<=X);
		res=0;
		ask(root,0,X,l,r,0);
		return res;
	}
	void query(int u,int l,int r,int k){
		if(!u||mx[u]<=k)return;
		if(l==r){
			if(mx[u]>k){
				res=l;
			}
			return;
		}
		int mid=(l+r)>>1;
		query(lc[u],l,mid,k-tg[u]);
		if(res>X){
			query(rc[u],mid+1,r,k-tg[u]);
		}
	}
	int query(int k){ // first big than k
		res=X+1;
		query(root,0,X,k);
		return res;
	}
}tr;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&r);
	rep(i,1,n){
		scanf("%d%d",&a[i].h,&a[i].t);
		if(a[i].h<0)a[i].h=0;
		if(a[i].t<0){
			--i;
			--n;
			continue;
		}
	}
	sort(a+1,a+n+1);
	int nex=X+1;
	set<int>S;
	rep(i,1,n)S.insert(a[i].h);
	for(int i=1,j;i<=n;){
		if(!S.empty()){
			nex=min(nex,*S.begin());
		}
		if(nex<a[i].t){
			while(!S.empty()&&*S.begin()<=nex)S.erase(S.begin());
			D("! %d\n",nex);
			int cur=tr.ask(nex-r);
			tr.set(nex,cur);
			cur=tr.ask(nex-r);
			nex=tr.query(cur);
			if(nex<=X)nex+=r;
		}else{
			while(!S.empty()&&*S.begin()<=a[i].t)S.erase(S.begin());
			D("? %d\n",a[i].t);
			j=i+1;
			while(j<=n&&a[i].t==a[j].t)++j;
			int cur=tr.ask(a[i].t-r);
			tr.set(a[i].t,cur);
			rep(k,i,j-1){
				tr.add(root,0,X,a[k].h,a[k].t,1);
			}
			cur=tr.ask(a[i].t-r);
			nex=tr.query(cur);
			if(nex<=X)nex+=r;
			i=j;
		}
	}
	printf("%d\n",tr.mx[1]);
	return 0;
}