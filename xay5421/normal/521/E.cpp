#include<bits/stdc++.h>
#define EB emplace_back
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,m,fa[N],dep[N],u[N],v[N],U,U2,V,V2,W;
int tg[N],flg;
int pp=1,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void jump(int k1,int k2,int k3){
	U=k1,U2=k2;
	D("%d %d\n",k1,k2);
	while(k1!=k2){
		if(tg[k1]){
			W=k1;
			V=max(u[tg[k1]],v[tg[k1]],[&](int x,int y){return dep[x]<dep[y];});
			V2=min(u[tg[k1]],v[tg[k1]],[&](int x,int y){return dep[x]<dep[y];});
			flg=1;
			return;
		}
		tg[k1]=k3;
		k1=fa[k1];
	}
}
void dfs(int k1){
	dep[k1]=dep[fa[k1]]+1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=fa[k1]){
		if(!fa[to[i]]){
			fa[to[i]]=k1;
			dfs(to[i]);
			if(flg)return;
		}else if(dep[k1]>dep[to[i]]){
			jump(k1,to[i],i>>1);
			if(flg)return;
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2;scanf("%d%d",&k1,&k2);
		u[i]=k1,v[i]=k2;
		ae(k1,k2),ae(k2,k1);
	}
	rep(i,1,n)if(!fa[i]){
		fa[i]=i,dfs(i);
		if(flg)break;
	}
	if(!flg)puts("NO");
	else{
		puts("YES");
		vector<int>lu;
		auto push=[&](int k1,int k2,int rev=0){
			int nowsz=SZ(lu);
			while(k1!=k2){
				assert(dep[k1]>=dep[k2]);
				lu.EB(k1);
				k1=fa[k1];
			}
			lu.EB(k1);
			if(rev)reverse(lu.begin()+nowsz,lu.end());
		};
		auto out=[&](){
			printf("%d",SZ(lu));
			for(auto x:lu)printf(" %d",x);
			puts("");
			lu.clear();
		};
		if(dep[U2]<dep[V2])swap(U,V),swap(U2,V2);
		if(W!=U&&W!=V){
			push(W,U2),out();
			push(V,W,1),push(U2,V2,1),out();
			push(U,W,1),lu.EB(U2),out();
		}else if(dep[U]>dep[V]){
			push(V,U2),out();
			push(U,V,1),lu.EB(U2),out();
			lu.EB(V),push(U2,V2,1),out();
		}else{
			push(U,U2),out();
			lu.EB(U),lu.EB(U2),out();
			push(V,U,1),push(U2,V2,1),out();
		}
	}
	return 0;
}