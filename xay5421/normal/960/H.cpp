// author: xay5421
// created: Wed Oct 13 10:29:44 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,m,Q,C,a[N],v[N],ans[N],fa[N],nowt;
vector<int>e[N];
vector<pair<int,int> >mods[N];
struct segTree{
	int sum1[N*4],sum2[N*4],tg[N*4],tim[N*4];
	inline void chk(int k1){
		if(tim[k1]!=nowt){
			tim[k1]=nowt,sum1[k1]=0,sum2[k1]=0,tg[k1]=0;
		}
	}
	void pst(int k1,int sz,int k4){
		chk(k1);
		sum2[k1]+=k4*2LL*sum1[k1]+1LL*sz*k4*k4;
		sum1[k1]+=1LL*sz*k4;
		tg[k1]+=k4;
	}
	void psd(int k1,int sz){
		if(tg[k1]){
			pst(k1*2,(sz+1)>>1,tg[k1]);
			pst(k1*2+1,sz>>1,tg[k1]);
			tg[k1]=0;
		}
	}
	void upd(int k1){
		sum1[k1]=sum1[k1*2]+sum1[k1*2+1];
		sum2[k1]=sum2[k1*2]+sum2[k1*2+1];
	}
	void add(int k1,int k2,int k3,int k4,int k5,int k6){
		chk(k1);
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k3-k2+1,k6);
			return;
		}
		psd(k1,k3-k2+1);
		int mid=(k2+k3)>>1;
		add(k1*2,k2,mid,k4,k5,k6),add(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
}tr;
int sz[N],dep[N],son[N],bel[N],ind,tin[N],tou[N];
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1,fa[k1]=k2,sz[k1]=1;
	for(auto x:e[k1])if(x!=k2){
		dfs1(x,k1),sz[k1]+=sz[x];
		if(sz[son[k1]]<sz[x])son[k1]=x;
	}
}
void dfs2(int k1,int k2){
	tin[k1]=++ind;
	if(son[k1]){
		bel[son[k1]]=bel[k1];
		dfs2(son[k1],k1);
	}
	for(auto x:e[k1])if(x!=k2&&x!=son[k1]){
		bel[x]=x;
		dfs2(x,k1);
	}
	tou[k1]=ind;
}
void adds(int k1,int k2){
	//D("adds %d %d\n",k1,k2);
	while(k1){
		tr.add(1,1,n,tin[bel[k1]],tin[k1],k2);
		k1=fa[bel[k1]];
	}
}
signed main(){
	rd(n),rd(m),rd(Q),rd(C);
	rep(i,1,n){
		rd(a[i]);
	}
	rep(i,2,n){
		int k1=i,k2;
		rd(k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	rep(i,1,m){
		rd(v[i]);
	}
	rep(i,1,n){
		mods[a[i]].eb(i,v[a[i]]);
	}
	dfs1(1,0);
	bel[1]=1;
	dfs2(1,0);
	int tot=0;
	rep(i,1,Q){
		int opt;
		rd(opt);
		if(opt==1){
			int p,x;
			rd(p),rd(x);
			mods[a[p]].eb(p,-v[a[p]]);
			a[p]=x;
			mods[a[p]].eb(p,v[a[p]]);
		}else{
			int k;
			rd(k);
			mods[k].eb(-(++tot),k);
		}
	}
	rep(now,1,m){
		++nowt;
		for(auto x:mods[now]){
			if(x.first<0){
				tr.chk(1);
				ans[-x.first]=tr.sum2[1]-2LL*C*tr.sum1[1]+1LL*n*C*C;
			}else{
				adds(x.first,x.second);
			}
		}
	}
	rep(i,1,tot)printf("%.20f\n",1.*ans[i]/n);
	return 0;
}