// author: xay5421
// created: Thu Dec 17 18:57:07 2020
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=400005,M=1000005;
int T,n,m,s,t,pre[N],go[N],dep[N],dir[M];
int pp,lnk[N],nxt[M*2],to[M*2];
vector<int>v[N];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	for(int i=lnk[k1];i;i=nxt[i])if(i/2!=k2/2){
		if(!dep[to[i]]){
			dep[to[i]]=dep[k1]+1;
			go[k1]=to[i];
			pre[to[i]]=i;
			dfs(to[i],i);
		}else if(dep[to[i]]<dep[k1]){
			v[go[to[i]]].PB(i);
		}
	}
}
void sol(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	pp=1;
	rep(i,1,n)lnk[i]=0,pre[i]=0,go[i]=0,dep[i]=0,v[i].clear();
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		dir[i]=-1;
	}
	dep[s]=1,dfs(s,0);
	queue<pair<int,int> >q;
	q.emplace(t,0);
#define baba(x) to[pre[x]^1]
	while(SZ(q)){
		int k1=q.front().X,k2=q.front().Y;
		q.pop();
		for(;pre[k1]&&dir[pre[k1]/2]==-1;k1=baba(k1)){
			dir[pre[k1]/2]=k2;
			for(const auto&i:v[k1]){
				dir[i/2]=k2;
				if(to[i]==baba(k1))q.emplace(to[i^1],k2^1);
				else q.emplace(to[i],k2^1);
			}
		}
	}
	rep(i,1,m)if(dir[i]==-1){
		puts("No");
		return;
	}
	puts("Yes");
	rep(i,1,m){
		if(dir[i]^(dep[to[i*2]]<dep[to[i*2+1]]))printf("%d %d\n",to[i*2],to[i*2+1]);
		else printf("%d %d\n",to[i*2+1],to[i*2]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}