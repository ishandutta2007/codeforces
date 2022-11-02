#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef int ll;
typedef double db;
const ll N=1e6+10;
ll n,m,ans[N],vis[N];
vector<ll>A[N];
struct node{
	int x,y;
	node(int X=0,int Y=0):x(X),y(Y){}
	bool operator <(const node&res)const{
		return x==res.x?y<res.y:x<res.x;
	}
};
set<node>S;
inline void dfs(ll x,ll y){
	if (vis[x]>-1) return;else vis[x]=y;
	for (unsigned i=0;i<A[x].size();++i) dfs(A[x][i],!y);
}
int main(){
	scanf("%d",&n);
	for (ll i=0,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		A[i*2].push_back(i*2+1);
		A[i*2+1].push_back(i*2);
		S.insert(node(x*2,i*2));
		S.insert(node(y*2+1,i*2+1));
	}
	set<node>::iterator it=S.begin();
	for (ll i=0;i<n;++i){
		ll l=it->y;++it;
		ll r=it->y;++it;
		A[l].push_back(r);
		A[r].push_back(l);
	}
	memset(vis,-1,sizeof vis);
	for (ll i=0;i<n;++i) if (vis[i*2]<0) dfs(i*2,0);
	for (ll i=0;i<n;++i) printf("%d ",vis[i*2]);
	return 0;
}