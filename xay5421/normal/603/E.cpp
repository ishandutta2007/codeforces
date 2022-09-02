#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005,M=300005,INF=0X3F3F3F3F;
int n,m,u[M],v[M],w[M],ans[M],cur=1,id[M],fa[N],sz[N],tt1;
vector<int>G[M*4];
int fd(int k1){return fa[k1]==k1?k1:fd(fa[k1]);}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		G[k1].PB(k6);
		return;
	}
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
}
void sol(int k,int l,int r){
	vector<int>md;
	int ntt1=tt1;
	for(auto i:G[k]){
		int k1=fd(u[i]),k2=fd(v[i]);
		if(k1!=k2){
			if(sz[k1]<sz[k2])swap(k1,k2);
			tt1-=sz[k1]&1,tt1-=sz[k2]&1;
			md.PB(k2),md.PB(k1),md.PB(sz[k2]);
			sz[k1]+=sz[k2],sz[k2]=0,fa[k2]=k1;
			tt1+=sz[k1]&1;
		}
	}
	if(l==r){
		for(;cur<=m&&tt1!=0;++cur){
			int i=id[cur];
			if(i>l)continue;
			int k1=fd(u[i]),k2=fd(v[i]);
			if(k1!=k2){
				if(sz[k1]<sz[k2])swap(k1,k2);
				tt1-=sz[k1]&1,tt1-=sz[k2]&1;
				md.PB(k2),md.PB(k1),md.PB(sz[k2]);
				sz[k1]+=sz[k2],sz[k2]=0,fa[k2]=k1;
				tt1+=sz[k1]&1;
			}
			if(i<=l-1){
				mdf(1,1,m,i,l-1,i);
				D(">>> %d %d %d\n",i,l-1,i);
			}
		}
		if(tt1!=0){
			ans[l]=INF;
		}else{
			//ans[l]=max(w[id[cur-1]],ans[l+1]);
			ans[l]=w[id[cur-1]];
		}
	}
	if(l!=r){
		int mid=(l+r)>>1;
		sol(k*2+1,mid+1,r);
		sol(k*2,l,mid);
	}
	for(int i=SZ(md)-3;i>=0;i-=3){
		fa[md[i]]=md[i];
		sz[md[i]]=md[i+2];
		sz[md[i+1]]-=md[i+2];
	}
	tt1=ntt1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),tt1=n;
	rep(i,1,n)fa[i]=i,sz[i]=1;
	rep(i,1,m)rd(u[i]),rd(v[i]),rd(w[i]),id[i]=i;
	sort(id+1,id+1+m,[&](int k1,int k2){return w[k1]<w[k2];});
	sol(1,1,m);
	rep(i,1,m)pt(ans[i]==INF?-1:ans[i],'\n');
	return 0;
}