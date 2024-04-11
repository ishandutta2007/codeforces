#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
const int N=200005;
int n,m,w[N],d[N];
bool vis[N];
VII G[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",w+i);
	rep(i,1,m){
		int k1,k2;scanf("%d%d",&k1,&k2);
		++d[k1],++d[k2];
		G[k1].PB(MP(k2,i));
		G[k2].PB(MP(k1,i));
	}
	queue<int>q;
	VI ans;
	rep(i,1,n)if(d[i]<=w[i])q.push(i);
	while(SZ(q)){
		int k1=q.front();q.pop();
		for(auto x:G[k1])
			if(!vis[x.se]){
				vis[x.se]=1,ans.PB(x.se);
				if(--d[x.fi]==w[x.fi]){
					q.push(x.fi);
				}
			}
	}
	if(SZ(ans)==m){
		puts("ALIVE");
		for(int i=SZ(ans)-1;i>=0;--i)printf("%d ",ans[i]);puts("");
	}else{
		puts("DEAD");
	}
	return 0;
}