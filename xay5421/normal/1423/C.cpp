#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=10005;
int n,fa[N],sz[N],bsz[N];
int pp,lnk[N],nxt[N*2],to[N*2];
bool ban[N];
set<pair<int,int> >S;
vector<pair<int,int> >ans;
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void push(int x,int y){
	if(x==y)return;
	if(!S.count(minmax(x,y))){
		S.insert(minmax(x,y));
		ans.PB(minmax(x,y));
	}
}
void jb(int k1,int k2,int k3){
	push(k1,k2);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k3&&!ban[to[i]]){
		jb(to[i],k2,k1);
	}
}
void sol(int k1){
	vector<int>q;
	q.PB(k1);
	rep(i,0,SZ(q)-1){
		int k1=q[i];
		sz[k1]=1,bsz[k1]=0;
		for(int i=lnk[k1];i;i=nxt[i])if(!ban[to[i]]&&to[i]!=fa[k1]){
			fa[to[i]]=k1;
			q.PB(to[i]);
		}
	}
	if(SZ(q)<=4)return;
	vector<int>cut;
	int B=min(SZ(q),int(sqrt(SZ(q))*1.5));
	per(i,SZ(q)-1,0){
		int k1=q[i];
		if(sz[k1]>=B||bsz[k1]>1||i==0){
			cut.PB(k1);
			ban[k1]=1;
			sz[k1]=0;
			bsz[k1]=1;
		}
		if(i){
			sz[fa[k1]]+=sz[k1];
			bsz[fa[k1]]+=bsz[k1];
		}
	}
	rep(i,0,SZ(cut)-1){
		ban[cut[i]]=1;
		rep(j,i+1,SZ(cut)-1){
			push(cut[i],cut[j]);
		}
	}
	rep(i,0,SZ(cut)-1){
		jb(cut[i],cut[i],0);
	}
	for(auto x:q)if(!ban[x])sol(x);
}
int main(){
	scanf("%d%*d",&n);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		S.insert(minmax(k1,k2));
	}
	sol(1);
	printf("%d\n",SZ(ans));
	rep(i,0,SZ(ans)-1)printf("%d %d\n",ans[i].X,ans[i].Y);
	return 0;
}