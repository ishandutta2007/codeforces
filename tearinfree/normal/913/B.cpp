#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
const lli mod=1e9+7;
const int inf=1e9;

inline int _abs(int a) {
	return a<0 ? -a : a;
}
inline lli _abs(lli a) {
	return a<0 ? -a : a;
}

int flag=1;
vector<int> adj[1001];

void dfs(int cur) {
	if(adj[cur].size()==0) return ;
	
	int sum=0;
	for(auto &it:adj[cur]) {
		if(adj[it].size()==0) sum++;
		else dfs(it);
	}
	if(sum<3) flag=0;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		int a;
		scanf("%d",&a);
		adj[a].push_back(i);
	}

	dfs(1);
	
	puts(flag ? "Yes" : "No");
	
	return 0;
}