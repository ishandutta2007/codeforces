#include<bits/stdc++.h>
using namespace std;
const int N = 100011;
set<int> ban[N], rmn;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ban[x].insert(y);
		ban[y].insert(x);
	}
	for(int i(1); i <= n; i++) {
		rmn.insert(i);
	}
	int ans = n - 1;
	for(int i(1); i <= n; i++) {
		if(rmn.count(i)) {
			rmn.erase(i);
			static vector<int> q;
			q.clear();
			q.push_back(i);
			for(int op = 0; op < (int)q.size(); op++) {
				int v = q[op];
				for(auto j = rmn.begin(); j != rmn.end(); ) {
					if(ban[v].count(*j)) {
						j++;
					}else {
						q.push_back(*j);
						ans--;
						rmn.erase(j++);
					}
				}
			}
		}
	}
	cout << ans << endl;
	
}