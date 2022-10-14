#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

vector<int> G[500050];
int n,u,v,a[500050],fac[500050],depth[500050],fa[500050];

int vis[500050];
struct llist{
	int id,cnt = 0;
	vector<int> link,rlink;
	int gid(int u){
		if(u==0)return 1;
		if(u==-1)return link.size()-1;
		return lower_bound(G[id].begin(),G[id].end(),u)-G[id].begin()+2;
	}
	void conn(int u,int v){
		u = gid(u);v = gid(v);
		if((link[u] && link[u]!=v) || (rlink[v] && rlink[v]!=u)){
			cout<<0<<endl;
			exit(0);
		}
		link[u] = v;
		rlink[v] = u;
		cnt++;
	}
	int calc(){
		int cs = 1,ccnt = 0;
		while(link[cs]!=link.size()-1 && link[cs]){
			ccnt++;
			cs = link[cs];
		}
		memset(vis,0,link.size()*4);
		for(int i=1;i<link.size()-1;i++){
			if(vis[i])continue;
			int cv = i;
			while(link[cv]){
				vis[cv] = i;
				cv = link[cv];
				if(vis[cv] == i) {
					return 0;
				}
			}
		}
		if(link[cs] == link.size()-1  && ccnt!=link.size()-3)
			return 0;
		return fac[max(0,(int)link.size()-3-cnt)];
	}
}L[500050];

void dfs(int num){
	for(auto ct:G[num]){
		if(!depth[ct]){
			fa[ct] = num;
			depth[ct] = depth[num]+1;
			dfs(ct);
		}
	}
}

int sz_cnt = 0;

void exec_edge(int u,int v){
	vector<int> S1,S2;
	while(depth[u]>depth[v]){
		S1.push_back(u); u = fa[u];
	}
	while(depth[v]>depth[u]){
		S2.push_back(v); v = fa[v];
	}
	while(v!=u){
		S2.push_back(v); v = fa[v];
		S1.push_back(u); u = fa[u];
	}
	S1.push_back(u);
	while(S2.size()){S1.push_back(S2[S2.size()-1]);S2.pop_back();}
	sz_cnt+=S1.size()-1;
	if(sz_cnt>n*2-2 || S1.size() == 1){
		cout<<0<<endl;
		exit(0);
	}
	L[S1[0]].conn(0,S1[1]);
	for(int i=1;i<S1.size()-1;i++)
		L[S1[i]].conn(S1[i-1],S1[i+1]);
	L[S1[S1.size()-1]].conn(S1[S1.size()-2],-1);
}

int main() {
	fac[0] = 1;
	for(int i=1;i<500050;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	depth[1] = 1;
	dfs(1);
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
		for(int j=0;j<G[i].size()+3;j++)L[i].link.push_back(0),L[i].rlink.push_back(0);
		L[i].id = i;
	}
	
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=0) exec_edge(a[i],i);
	}
	int ans = 1;
	for(int i=1;i<=n;i++){
		//cout<<i<<' '<<L[i].calc()<<endl;
		//cout<<"CU "<<i<<endl;
		ans = mul(ans,L[i].calc());
	}
	cout<<ans<<endl;
	return 0;
}