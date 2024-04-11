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

int n,k,vis[100010];
vector<int> G[100010];
void dfs(int num){
	vis[num] = 1;
	for(auto ct:G[num]){
		if(!vis[ct])dfs(ct);
	}
}
int main() {
	read(n);read(k);
	int ans = n;
	for(int i=0;i<k;i++){
		int u,v;
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])ans--;
		dfs(i);
	}
	cout<<k-ans<<endl;
	return 0;
}