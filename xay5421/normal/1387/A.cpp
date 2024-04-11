#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
const int N=100005,M=200005;
int n,m,fa[N],x;
int pp,lnk[N],nxt[M*2],to[M*2],w[M*2];
VI G[N];
PII num[N],bkup[N];
bool pd,vis[N];
double ans[N];
void ae(int k1,int k2,int k3){to[++pp]=k2,w[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
PII operator-(const PII&k1,const PII&k2){
	return MP(k1.fi-k2.fi,k1.se-k2.se);
}
void dfs(int k1){
	vis[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i]){
		if(!vis[to[i]]){
			num[to[i]]=MP(w[i],0)-num[k1];
			dfs(to[i]);
		}else{
			PII tmp=MP(w[i],0)-num[k1];
			if(tmp!=num[to[i]]){
				if(tmp.se==num[to[i]].se)puts("NO"),exit(0);
				if(pd){
					if(tmp.fi+tmp.se*x!=num[to[i]].fi+num[to[i]].se*x)puts("NO"),exit(0);
				}else{
					pd=1,x=(tmp.fi-num[to[i]].fi)/(num[to[i]].se-tmp.se);
					assert(tmp.fi+tmp.se*x==num[to[i]].fi+num[to[i]].se*x);
				}
			}
		}
	}
}
void sol(int k1){
	pd=0,x=0;
	num[k1]=MP(0,1);
	dfs(k1);
	for(auto k2:G[k1])bkup[k2]=num[k2];
	if(!pd){
		for(auto k2:G[k1]){
			if(num[k2].se>0)num[k2]=MP(0,0)-num[k2];
//			printf("num[%d]={%d,%d}\n",k2,num[k2].fi,num[k2].se);
		}
		sort(G[k1].begin(),G[k1].end(),[&](int k1,int k2){return num[k1]<num[k2];});
		x=num[G[k1][SZ(G[k1])/2]].fi;
	}
//	printf("x=%d\n",x);
	for(auto k2:G[k1])ans[k2]=(bkup[k2].fi+bkup[k2].se*x)/2.;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		k3*=2;
		ae(k1,k2,k3),ae(k2,k1,k3);
		fa[fd(k1)]=fd(k2);
	}
	rep(i,1,n)G[fd(i)].PB(i);
	rep(i,1,n)if(fd(i)==i)sol(i);
	puts("YES");
	rep(i,1,n)printf("%.6lf\n",ans[i]);
	return 0;
}