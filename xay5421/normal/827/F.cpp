#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=500005,INF=0X3F3F3F3F;
int n,m,f[N][2];bool vis[N][2];
struct ff{
	int u,v,l,r,tp;
	bool operator<(const ff&k)const{return l>k.l;}
};
priority_queue<ff>Q;
vector<ff>E[N][2];
void sol(int u,int v,int l,int r){
	int op=l&1;
	D(">>> f[%d][%d]=%d\n",u,op,f[u][op]);
	D("u=%d v=%d l=%d r=%d\n",u,v,l,r);
	if(f[u][op]>=l){
		if(v==n)printf("%d\n",l+1),exit(0);
		if(f[v][op^1]<r+1){
			f[v][op^1]=r+1;
			for(auto x:E[v][op^1]){
				Q.push((ff){x.u,x.v,l+1,x.r,0});
			}
			E[v][op^1].clear();
		}
	}else{
		E[u][op].PB((ff){u,v,l,r,0});
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if(n==1)puts("0"),exit(0);
	rep(i,1,m){
		int k1,k2,k3,k4;
		scanf("%d%d%d%d",&k1,&k2,&k3,&k4),--k4;
		int o=(k4-k3)&1;
		Q.push((ff){k1,k2,k3,k4-o,1});
		Q.push((ff){k1,k2,k3+1,k4-!o,1});
	}
	memset(f,192,sizeof(f));
	f[1][0]=0;
	while(SZ(Q)){
		ff cur=Q.top();
		Q.pop();
		if(cur.l>cur.r)continue;
		sol(cur.u,cur.v,cur.l,cur.r);
		if(cur.tp==1)sol(cur.v,cur.u,cur.l,cur.r);
	}
	puts("-1");
	return 0;
}