#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m;
int cache[101][101][26][2];
vector<pii> adj[101];

int DP(int a,int b,int c,int f) {
	int &ret=cache[a][b][c][f];
	if(ret!=-1) return ret;

	int v=f ? b : a;
	ret=0;
	for(auto &it:adj[v]) {
		if(it.first>=c) {
			ret=max(ret, DP( f ? a : it.second, f ? it.second : b, it.first, f^1)^1);
		}
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		char ch;
		scanf("%d%d %c",&a,&b,&ch);
		adj[a].push_back(pii(ch-'a',b));
	}

	memset(cache,-1,sizeof(cache));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j) {
				printf("B");
				continue;
			}
			printf("%c",(DP(i,j,0,0)^1)+'A');
		}
		puts("");
	}
	
	return 0;
}