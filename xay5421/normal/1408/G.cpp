#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define EB emplace_back
using namespace std;
const int N=1505,P=998244353;
int n,a[N][N],sz[N*2],lc[N*2],rc[N*2],f[N*2][N],good[N*2];
vector<tuple<int,int,int> >e;
struct UFS{
	vector<int>fa,sz,tot;
	void init(int n){
		fa.assign(n+1,0);
		sz.assign(n+1,0);
		tot.assign(n+1,0);
		rep(i,1,n)fa[i]=i;
	}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void mer(int k1,int k2){
		assert(fd(k1)!=fd(k2));
		tot[k2]+=tot[k1],tot[k1]=0;
		sz[k2]+=sz[k1],sz[k1]=0;
		fa[k1]=k2;
	}
}o;
void dfs(int k1){
	if(k1<=n){
		f[k1][1]=1;
		return;
	}
	dfs(lc[k1]);
	dfs(rc[k1]);
	rep(i,1,sz[lc[k1]])rep(j,1,sz[rc[k1]]){
		f[k1][i+j]=(f[k1][i+j]+1LL*f[lc[k1]][i]*f[rc[k1]][j])%P;
	}
	if(good[k1])++f[k1][1];
}
int main(){
	scanf("%d",&n);
	int cur=n;
	rep(i,1,n)rep(j,1,n){
		scanf("%d",&a[i][j]);
		if(i<j)e.EB(a[i][j],i,j);
	}
	sort(e.begin(),e.end());
	o.init(n*2-1);
	rep(i,1,n)o.sz[i]=sz[i]=1;
	for(auto it:e){
		int k1,k2,k3;
		tie(k3,k1,k2)=it;
		k1=o.fd(k1),k2=o.fd(k2);
		if(k1!=k2){
			++cur;
			sz[cur]=sz[k1]+sz[k2];
			lc[cur]=k1;
			rc[cur]=k2;
			o.mer(k1,cur);
			o.mer(k2,cur);
		}
		k1=o.fd(k1);
		if(++o.tot[k1]==1LL*o.sz[k1]*(o.sz[k1]-1)/2){
			good[k1]=1;
		}
	}
	dfs(cur);
	rep(i,1,n)printf("%d ",f[cur][i]);
	puts("");
	return 0;
}