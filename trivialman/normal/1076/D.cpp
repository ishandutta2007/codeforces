#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
/*maxflow: poj 3436, 1459, 3308, 2112, 1966, 1087, 2289, 3216, 2446 */ 
const LL INF = 1e18;
const int N = 3e5+5;

struct E{
	int id, to; LL d;
	bool operator<(E r) const {return d>r.d;}
};
vector<E> g[N];
LL d[N];
int n, m, k, x, y, z, ans[N];
bool v[N];

void dij(int s){
	rep(i,1,n) d[i] = INF;
	priority_queue<E> heap;
	heap.push({0,s,0}), d[s] = 0;
	
	z = 0;
	while(!heap.empty()){
		E x = heap.top();
		heap.pop();
		LL dist = x.d, to = x.to;
		if(dist>d[to]) continue;
		ans[z++] = x.id;
		
		for(auto u:g[to]) if(d[u.to]>d[to]+u.d) {
			d[u.to] = d[to] + u.d;
			heap.push({u.id,u.to,d[u.to]});
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		g[x].PB({i,y,z});
		g[y].PB({i,x,z});
	}
	dij(1);
	//rep(i,1,n) cout<<i<<" "<<d[i]<<endl;
	
	int num = min(n-1, k);
	printf("%d\n",num);
	rep(i,1,num) printf("%d ",ans[i]);
	return 0;
}