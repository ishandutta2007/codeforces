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

ll n,m,d[100010],q;
vector<ll> G[100010];
ll ans = 0;
int main() {
	read(n);read(m);
	for(int i=0;i<m;i++){
		int u,v;
		read(u);read(v);
		if(u>v)swap(u,v);
		d[u]++;
		d[v]++;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		ans+=1ll*(d[i]-G[i].size())*G[i].size();
	}
	
		cout<<ans<<"\n";
	read(q);
	while(q--){
		ll w;
		read(w);
		ans-=1ll*(d[w]-G[w].size())*G[w].size();
		for(auto ct:G[w]){
			ans-=G[ct].size();
			G[ct].push_back(w);
			ans+=d[ct]-G[ct].size();
		}
		G[w].clear();
		cout<<ans<<"\n";
	}
	return 0;
}