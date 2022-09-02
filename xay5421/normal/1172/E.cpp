#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=400005;
struct LCT{
	int fa[N],asz[N],vsz[N],ch[N][2];
	LL vsz2[N];
	int isrt(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
	int get(int k1){return ch[fa[k1]][1]==k1;}
	void upd(int k1){
		asz[k1]=asz[ch[k1][0]]+asz[ch[k1][1]]+vsz[k1]+1;
	}
	void rtt(int k1){
		assert(k1);
		assert(!isrt(k1));
		int k2=fa[k1],x=get(k1);
		if(!isrt(k2))ch[fa[k2]][get(k2)]=k1;
		fa[k1]=fa[k2];
		fa[ch[k2][x]=ch[k1][x^1]]=k2;
		fa[ch[k1][x^1]=k2]=k1;
		upd(k2),upd(k1);
	}
	void sp(int k1){
		for(;!isrt(k1);rtt(k1))if(!isrt(fa[k1]))rtt(get(k1)==get(fa[k1])?fa[k1]:k1);
	}
	void ac(int k1){
		for(int k2=0;k1;k2=k1,k1=fa[k1]){
			sp(k1);
			vsz[k1]+=asz[ch[k1][1]]-asz[k2];
			vsz2[k1]+=1LL*asz[ch[k1][1]]*asz[ch[k1][1]]-1LL*asz[k2]*asz[k2];
			ch[k1][1]=k2;
			upd(k1);
		}
	}
	int fd(int k1){
		assert(k1);
		ac(k1),sp(k1);
		while(ch[k1][0])k1=ch[k1][0];
		return sp(k1),k1;
	}
	void link(int k1,int k2){ // fa[k1]=k2
		//D("link %d %d\n",k1,k2);
		assert(k1);
		assert(k2);
		ac(k1),sp(k1);
		ac(k2),sp(k2);
		fa[k1]=k2,ch[k2][1]=k1;
		upd(k2);
	}
	void cut(int k1,int k2){
		ac(k1),sp(k1),sp(k2);
		//D("cut %d %d\n",k1,k2);
		assert(fa[k1]==k2);
		assert(ch[k2][1]==k1);
		fa[k1]=ch[k2][1]=0;
		upd(k2);
	}
	LL qry(int k1){
		assert(k1);
		k1=fd(k1),sp(k1),k1=ch[k1][1];
		return 1LL*asz[k1]*asz[k1];
	}
	LL qry2(int k1){
		k1=fd(k1),sp(k1);
		assert(fd(k1));
		return 1LL*asz[ch[k1][0]]*asz[ch[k1][0]]+1LL*asz[ch[k1][1]]*asz[ch[k1][1]]+vsz2[k1];
	}
}lct;
int n,m,fa[N],col[N];
LL ans[N];
vector<pair<int,int> >G[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	fa[k1]=k2;
	if(k2)lct.link(k1,k2);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)dfs(to[i],k1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int c;
		scanf("%d",&c);
		col[i]=c;
		G[c].EB(i,0);
	}
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		G[k2].EB(k1,i);
		G[col[k1]].EB(k1,i);
		col[k1]=k2;
	}
	ae(n+1,1),dfs(n+1,0);
	memset(col,0,sizeof(col));
	rep(c,1,n){
		//D("c=%d\n",c);
		for(auto x:G[c]){
			if(col[x.X]^=1){
				ans[x.Y]-=lct.qry(x.X);
				lct.cut(x.X,fa[x.X]);
				ans[x.Y]+=lct.qry2(x.X);
				if(col[fa[x.X]]==0){
					ans[x.Y]+=lct.qry(fa[x.X]);
				}
			}else{
				if(col[fa[x.X]]==0){
					ans[x.Y]-=lct.qry(fa[x.X]);
				}
				ans[x.Y]-=lct.qry2(x.X);
				lct.link(x.X,fa[x.X]);
				ans[x.Y]+=lct.qry(x.X);
			}
		}
		//D("ans[0]=%lld\n",ans[0]);
		reverse(G[c].begin(),G[c].end());
		for(auto x:G[c]){
			if(col[x.X]==1){
				lct.link(x.X,fa[x.X]);
				col[x.X]=0;
			}
		}
	}
	rep(i,1,m)ans[i]+=ans[i-1];
	rep(i,0,m)printf("%lld\n",-ans[i]);
	return 0;
}