#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define X first
#define Y second
#define PB push_back
#define EB emplace_back
using namespace std;
const int N=100005,B=350;
int n,Q,dep[N],tt[N];
pair<int,int>q[N];
int pp,lnk[N],nxt[N],to[N];
bool pd[N],col[N],clr[N];
vector<pair<int,int> >G[N];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs1(int k1,int k2,int k3){
	if(pd[k1]){
		if(k2)G[k2].EB(k3,k1);
	}
	for(int i=lnk[k1];i;i=nxt[i])dfs1(to[i],pd[k1]?k1:k2,pd[k1]?0:k3+(!col[k1]));
}
void sol1(int k1){
	if(col[k1]==0){
		col[k1]=1;
		return;
	}
	++tt[k1];
	for(auto&x:G[k1])if(x.X==0)sol1(x.Y);else --x.X;
}
void sol2(int k1){
	clr[k1]=1,col[k1]=0,tt[k1]=0;
	for(auto&x:G[k1]){
		sol2(x.Y);
		x.X=dep[x.Y]-dep[k1]-1;
	}
}
void dfs2(int k1,int k2,int k3){
	if(pd[k1]){
		k2=tt[k1];
		k3|=clr[k1];
	}else{
		if(k3)col[k1]=0;
		if(!col[k1]&&k2)col[k1]=1,--k2;
	}
	for(int i=lnk[k1];i;i=nxt[i]){
		dfs2(to[i],k2,k3);
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	rep(i,2,n){
		int k;
		scanf("%d",&k);
		ae(k,i);
		dep[i]=dep[k]+1;
	}
	rep(i,1,Q)scanf("%d%d",&q[i].X,&q[i].Y);
	for(int l=1,r;l<=Q;l=r+1){
		r=min(l+B-1,Q);
		rep(i,l,r)pd[q[i].Y]=1;
		dfs1(1,0,0);
		rep(i,l,r){
			if(q[i].X==1){
				sol1(q[i].Y);
			}else if(q[i].X==2){
				sol2(q[i].Y);
			}else{
				puts(col[q[i].Y]?"black":"white");
			}
		}
		dfs2(1,0,0);
		rep(i,l,r)pd[q[i].Y]=0,clr[q[i].Y]=0,G[q[i].Y].clear(),tt[q[i].Y]=0;
	}
	return 0;
}