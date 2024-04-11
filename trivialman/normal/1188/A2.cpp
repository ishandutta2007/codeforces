#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 100010;

int n,x[N],y[N],v[N];
struct dat{
	int x,y,v;
};
vector<dat> ans;
vector<int> g[N];

int dfs(int x,int fa,int z){
	if(g[x].size()==1) return x==z?-1:x;
	int mi = n;
	for(auto u:g[x])
		if(u!=fa) mi = min(mi, dfs(u,x,z));
	return mi;
}

void addedge(int x,int y,int v){
	if(g[x].size()==1 && g[y].size()==1){
		ans.PB({x,y,v});
		return;
	}
	if(g[x].size()>g[y].size())swap(x,y);
	if(g[x].size()==1){
		int x1=-1, x2=-1;
		for(auto z:g[y]){
			int xx = dfs(z,y,x);
			if(xx==-1)continue;
			(x1==-1?x1:x2)=xx;
		}
		ans.PB({x,x1,v/2});
		ans.PB({x,x2,v/2});
		ans.PB({x1,x2,-v/2});
	}else{
		int x1;
		for(auto z:g[y])if(z!=x){
			x1 = dfs(z,y,x);
			break;
		}
		addedge(x1,x,v);
		addedge(x1,y,-v);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n-1)cin>>x[i]>>y[i]>>v[i],g[x[i]].PB(y[i]),g[y[i]].PB(x[i]);
	
	bool flag = false;
	rep(i,1,n)if(g[i].size()==2)flag = true;
	if(flag){
		cout<<"NO";
		return 0;
	}
	
	rep(i,1,n-1)addedge(x[i],y[i],v[i]);
	cout<<"YES\n"<<ans.size()<<endl;
	for(auto ele:ans){
		cout<<ele.x<<" "<<ele.y<<" "<<ele.v<<endl; 
	}
	return 0;
}