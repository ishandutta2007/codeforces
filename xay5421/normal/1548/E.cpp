// author: xay5421
// created: Mon Aug  9 17:25:49 2021
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
typedef long long LL;
const int N=200005,K=20,INF=0X3F3F3F3F;
int n,m,x,a[N],b[N],lg[N];
LL ans;
struct ST{
	int *a,n,f[N][K],op;
	int max_(int k1,int k2){
		if(op==0){ // mn
			return a[k1]<a[k2]?k1:k2;
		}else{ // mx
			return a[k1]<a[k2]?k2:k1;
		}
	}
	void init(int*a_,int n_,int op_){
		a=a_,n=n_,op=op_;
		rep(i,1,n)f[i][0]=i;
		rep(j,1,K-1){
			rep(i,1,n-(1<<j)+1){
				f[i][j]=max_(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int askp(int l,int r){
		int x=lg[r-l+1];
		return max_(f[l][x],f[r-(1<<x)+1][x]);
	}
	int askv(int l,int r){return a[askp(l,r)];}
}st1,st2;
struct node{
	int l,r,w;
	node(int l,int r):l(l),r(r),w(st1.askv(l,r)){}
	bool operator<(const node&k)const{return w>k.w;}
};
vector<node>rgs;
void bud(int l,int r){
	if(l>r)return;
	rgs.emplace_back(l,r);
	int mid=st2.askp(l,r);
	bud(l,mid-1);
	bud(mid+1,r);
}
int id[N];
bool vis[N];
struct ufs{
	int fa[N],val[N];
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void mer(int k1,int k2){
		val[k1]=min(val[k1],val[k2]);
		fa[k2]=k1;
	}
}o;
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<N;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
int main(){
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	scanf("%d%d%d",&n,&m,&x);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]),id[i]=i;
	sort(id+1,id+1+m,[&](int x,int y){return b[x]<b[y];});
	st1.init(a,n,0);
	st2.init(a,n,1);
	a[0]=INF,a[n+1]=INF;
	bud(1,n);
	sort(rgs.begin(),rgs.end());
	int pos=1;
	auto pop=[&](int x){
		t.upd(o.val[x],-1);
	};
	auto put=[&](int x){
		t.upd(o.val[x],1);
	};
	auto ps=[&](int x){
		if(vis[x-1]){
			pop(o.fd(x-1));
		}
		if(vis[x+1]){
			pop(o.fd(x+1));
		}
		o.fa[x]=x,o.val[x]=b[x],vis[x]=1;
		if(vis[x-1]){
			o.mer(o.fd(x-1),o.fd(x));
		}
		if(vis[x+1]){
			o.mer(o.fd(x+1),o.fd(x));
		}
		put(o.fd(x));
	};
	for(auto cur:rgs){
		while(pos<=m&&b[id[pos]]<=x-cur.w)ps(id[pos++]);
		int lb=max(0,x-min(a[cur.l-1],a[cur.r+1]))+1;
		int rb=min(N-1,x-st2.askv(cur.l,cur.r));
		if(lb<=rb)ans+=t.qry(rb)-t.qry(lb-1);
	}
	printf("%lld\n",ans);
	return 0;
}