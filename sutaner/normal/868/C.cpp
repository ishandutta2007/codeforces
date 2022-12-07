#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#define maxn 100005
using namespace std;

bool vis[10];
map<int, int> save;
int geo[maxn][10];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++){
			scanf("%d", &geo[i][j]);
			if (!geo[i][j]) vis[j] = 1;
		}
	}
	for (int i = 0; i < k; i++){
		if (!vis[i]){
			printf("NO");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++){
		int ans = 0;
		for (int j = 0; j < k; j++){
			ans = (ans << 1) + geo[i][j];
		}
		if (save.count(ans)) save[ans] = 1;
		else save[ans]++;
	}


	for (int i = 1; i <= n; i++){
		int ans = 0;
		for (int j = 0; j < k; j++){
			ans = (ans << 1) + geo[i][j];
		}
		for (int j = 0; j < (1 << k); j++){
			if (!save.count(j)) continue;
			bool f = 1;
			for (int t = 0; t < k; t++){
				if ((j & (1 << t)) && (ans & (1 << t))) {
					f = 0;
					break;
				}
			}
			if (f) {
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}