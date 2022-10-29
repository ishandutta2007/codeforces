#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

struct dat{
	int subid,dist;
}a[N];
struct dat2{
	int minD,center;
}b[N];
int n,m,x,y,nowid;
vector<int> g[N],ans;

int dfs(int x,int p,int id){
	a[x].subid = id;
	int d = 0;
	for(auto u:g[x]) if(u!=p)
		d = max(dfs(u,x,id)+1, d);
	return d;
}

bool cmp(dat2 x,dat2 y){return x.minD>y.minD;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>m;
	rep(i,1,m){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	rep(i,1,n-m) b[i].minD = N;
	rep(i,1,n){
		int id = a[i].subid?a[i].subid:++nowid;
		a[i].dist = dfs(i,0,id);
		if(a[i].dist<b[id].minD){
			b[id].minD = a[i].dist;
			b[id].center = i;
		}
	}
	
	sort(b+1, b+nowid+1, cmp);
	rep(i,2,nowid){
		x = b[1].center; y = b[i].center;
		g[x].push_back(y);
		g[y].push_back(x);
		ans.push_back(y);
	}
	
	int dist=0;
	rep(i,1,n) dist = max(dist, dfs(i,0,0));
	cout<<dist<<endl;
	for(auto x:ans)cout<<b[1].center<<" "<<x<<endl;
	return 0;
}