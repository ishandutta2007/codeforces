#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

ll sz[N+5],dep[N+5];
vector<int>link[N+5];
int n,k;

void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	sz[u] = 1;
	for(auto v : link[u]){
		if(v == fa)continue;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

struct cmp{
	In bool operator () (int u,int v){
		return sz[u] - dep[u] < sz[v] - dep[v];
	}
};

priority_queue<int,vector<int>,cmp>q;
ll ans;

void bfs(){
	ans = 0;
	q.push(1);
	for(rg int i = 1;i <= n - k;i++){
		int u = q.top();
//cout<<"u="<<u<<" sz="<<sz[u]<<" dep="<<dep[u]<<endl;
		q.pop();
		ans += sz[u] - dep[u];
		for(auto v : link[u])if(dep[v] > dep[u])q.push(v);
	}
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);		
	n = read(),k = read();
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		link[u].push_back(v);
		link[v].push_back(u);
	}	
	dfs(1,0);
	bfs();
	cout << ans << endl;
	return 0;
}