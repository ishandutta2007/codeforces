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

int n,m;
set<int> G[100010],nvis;

void dfs(int num){
	nvis.erase(num);
	set<int>:: iterator it;
	int cc = -1;
	it = nvis.lower_bound(cc);
	while(it!=nvis.end()){
		cc = *it;
		if(!G[num].count(*it)){
			dfs(*it);
		}
		it = nvis.lower_bound(cc+1);
	}
}
int main() {
	read(n);read(m);
	for(int i=0;i<m;i++){
		int u,v;
		read(u);read(v);
		G[u].insert(v);
		G[v].insert(u);
	}
	int ans = -1;
	for(int i=1;i<=n;i++)nvis.insert(i);
	for(int i=1;i<=n;i++){
		if(nvis.count(i)){
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}