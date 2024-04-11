#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX = 105;
int n,m;
int mk[MAX];
int cx[MAX],cy[MAX];
bool map[105][105];
int path(int u) {
	for(int v=1; v<=m; v++) {
		if(map[u][v]&&!mk[v]) {
			mk[v]=1;
   			if(cy[v]==-1|| path(cy[v])) {
			   cx[u] = v; 
			   cy[v] = u; 
			   return 1; 
			}
  		}
 	}
	return 0 ; 
}
int MaxMatch() {
	int res=0;
 	memset(cx,255,sizeof(cx)); 
	memset(cy,255,sizeof(cy));
	for(int i=1; i<= n; i++) {
		if(cx[i] == -1) {
			memset(mk,0,sizeof(mk));
			res+=path(i); 
  		}
 	}
 	return res;
}
inline int ABS(int x) {
	return x > 0 ? x : -x;
}
int va[505],vb[505];
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d", va + i);
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i) scanf("%d", vb + i); 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
			if (ABS(va[i] - vb[j]) <= 1) map[i][j] = true;
	printf("%d\n",MaxMatch());
}