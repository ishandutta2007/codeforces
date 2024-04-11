#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+10;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct dat{
	int u,v,c;
}a[N];
vector<int> g[N];
int n,m,grp[N],lv[N],in[N];
bool flag;
 
void dfs(int x,int i){
	grp[x] = 1;
	for(auto u:g[x]){
		if(grp[u]==1) flag = false;
		if(!grp[u]) dfs(u, i);
	}
	grp[x] = 2;
}
 
bool check(int k){
	rep(i,1,n)g[i].clear();
	rep(i,1,m)if(a[i].c>k){
		int u = a[i].u, v = a[i].v;
		g[u].PB(v);
	}
	flag = true;
	memset(grp,0,sizeof grp);
	rep(i,1,n)if(!grp[i]){
		dfs(i,i);
		if(!flag) return false;
	}
	//cout<<k<<endl;
	return true;
}
 
void solve(int k){
	memset(lv,0,sizeof lv);
	memset(in,0,sizeof in);
	rep(i,1,n)g[i].clear();
	
	rep(i,1,m)if(a[i].c>k){
		int u = a[i].u, v = a[i].v;
		g[v].PB(u), in[u]++;
	}
	
	memset(lv,0,sizeof lv);
	queue<int> que;
	rep(i,1,n)if(!in[i])que.push(i);
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto u:g[x]){
			in[u]--;
			if(!in[u]) que.push(u), lv[u] = lv[x] + 1;
		} 
	}
	
	//rep(i,1,n)cout<<lv[i]<<" ";cout<<endl;
}
 
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	int l=0, r=1e9, ans=1e9;
	while(l<=r){
		int mid = l+r>>1;
		if(check(mid)){
			ans = min(ans, mid);
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	solve(ans); 
	vector<int> e;
	rep(i,1,m) if(a[i].c<=ans){
		int u = a[i].u, v = a[i].v;
		//printf("%d %d %d %d %d %d\n",u,v,grp[u],grp[v],lv[u],lv[v]);
		if(lv[u]<lv[v] || lv[u]==lv[v] && u<v) e.PB(i);
	}
	printf("%d %d\n",ans,e.size());
	for(auto i:e) printf("%d ",i);
	return 0;
}