// author: xay5421
// created: Wed Dec 16 23:08:14 2020
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PB push_back
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005,B=550;
int T,n,m,pos[N];
vector<int>G[N];
vector<pair<int,int> >H[N];
void sol(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int K;
		scanf("%d",&K);
		G[i].assign(K,0);
		rep(j,0,K-1)scanf("%d",&G[i][j]);
	}
	rep(i,1,n)H[i].clear();
	rep(i,1,m)if(SZ(G[i])>B){
		rep(j,0,SZ(G[i])-1)pos[G[i][j]]=j;
		rep(j,1,m)if(j!=i&&!(j<i&&SZ(G[j])>B)){
			int w=-1;
			per(k,SZ(G[j])-1,0){
				if(pos[G[j][k]]==-1)continue;
				if(pos[G[j][k]]>w){
					w=pos[G[j][k]];
				}else{
					if(G[i][pos[G[j][k]]+1]!=G[j][k+1]){
						puts("Human");
						rep(t,0,SZ(G[i])-1)pos[G[i][t]]=-1;
						return;
					}
				}
			}
		}
		rep(j,0,SZ(G[i])-1)pos[G[i][j]]=-1;
	}
	rep(i,1,m)if(SZ(G[i])<=B){
		rep(j,0,SZ(G[i])-1)rep(k,j+1,SZ(G[i])-1){
			H[G[i][j]].EB(G[i][k],G[i][j+1]);
		}
	}
	vector<int>bin(n+1);
	rep(i,1,n){
		for(const auto&x:H[i]){
			if(!bin[x.X])bin[x.X]=x.Y;
			else if(bin[x.X]!=x.Y){
				puts("Human");
				for(const auto&y:H[i])bin[y.X]=0;
				return;
			}
		}
		for(const auto&y:H[i])bin[y.X]=0;
	}
	puts("Robot");
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(pos,-1,sizeof(pos));
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}