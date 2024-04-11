#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int N(333333);
int idx[N], bg[N];
int main() {
	int n, m;
	vector<pair<int, int> > vec;
	int ans(0), cur(0);
	scanf("%d%d", &n, &m);
	for(int i(0); i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == 1) {
			ans++;
			vec.push_back(make_pair(y, idx[y]));
			idx[y]++;
		}else if(x == 2) {
			ans -= idx[y] - bg[y];
			bg[y] = idx[y];
		}else if(x == 3) {
			if(cur < y) {
				for(int j(cur); j < y; j++) {
					int u(vec[j].first);
					if(vec[j].second == bg[u] && vec[j].second < idx[u]) {
						ans--;
						bg[u]++;
					}
				}
				cur = y;
			}
		}
		printf("%d\n", ans);
	}
}