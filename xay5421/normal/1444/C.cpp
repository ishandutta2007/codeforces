#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
//#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int n,m,K,ind,c[N],bel[N],col[N],bad[N];
int bigc[N],tim[N],nowt;
vector<int>G[N];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){
	D("ae %d %d %d\n",k1,k2,k3);
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
struct ff{
	int c1,c2,u,v;
	bool operator<(const ff&k)const{
		return c1^k.c1?c1<k.c1:c2<k.c2;
	}
	bool operator==(const ff&k)const{
		return c1==k.c1&&c2==k.c2;
	}
}e[N];
void dfs1(int k1,int k2){
	if(bel[k1])return;
	bel[k1]=k2;
	for(auto j:G[k1]){
		if(!bel[j]){
			col[j]=col[k1]^1;
			dfs1(j,k2);
		}else{
			if(col[j]!=(col[k1]^1))bad[c[k1]]=1;
		}
	}
}
bool err=0;
void dfs2(int k1,int k2){
	if(bigc[k1]!=-1){
		if(bigc[k1]!=k2)err=1;
		return;
	}
	bigc[k1]=k2;
	for(int i=lnk[k1];i;i=nxt[i]){
		dfs2(to[i],k2^1^we[i]);
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m),rd(K);
	rep(i,1,n)rd(c[i]);
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		if(c[k1]==c[k2]){
			G[k1].PB(k2);
			G[k2].PB(k1);
			D("ae1 %d %d\n",k1,k2);
		}
		if(c[k1]>c[k2])swap(k1,k2);
		e[i]=(ff){c[k1],c[k2],k1,k2};
	}
	rep(i,1,n)if(!bel[i]){
		dfs1(i,++ind);
	}
	LL ans=1LL*K*(K-1)/2;
	int tot=K;
	rep(i,1,K){
		if(bad[i])ans-=--tot;
	}
	rep(i,1,ind)bigc[i]=-1;
	sort(e+1,e+1+m);
	for(int i=1,j;i<=m;i=j){
		j=i+1;
		while(j<=m&&e[i]==e[j])++j;
		if(e[i].c1==e[i].c2)continue;
		if(bad[e[i].c1]||bad[e[i].c2])continue;
		D("---\n");
		rep(k,i,j-1){
			ae(bel[e[k].u],bel[e[k].v],col[e[k].u]^col[e[k].v]);
			ae(bel[e[k].v],bel[e[k].u],col[e[k].u]^col[e[k].v]);
		}
		err=0;
		rep(k,i,j-1){
			if(bigc[bel[e[k].u]]==-1){
				dfs2(bel[e[k].u],0);
				if(err)break;
			}
		}
		ans-=err;
		if(err)D("bad %d %d\n",e[i].c1,e[i].c2);
		rep(k,i,j-1){
			bigc[bel[e[k].u]]=-1;
			bigc[bel[e[k].v]]=-1;
			lnk[bel[e[k].u]]=0;
			lnk[bel[e[k].v]]=0;
		}
		pp=0;
	}
	pt(ans,'\n');
	return 0;
}