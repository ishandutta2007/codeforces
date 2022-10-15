#include<bits/stdc++.h>
using namespace std;
int debug = 0;
const int N(111111);
int col[N];
int n;
void init() {
	for(int i(1); i <= n; i++) {
		col[i] = rand() % 3;
	}
}
int ans[N], d[N], di[N], blg[N];
void query(vector<pair<int, int> > & vec) {
	if(vec.empty()) return;
	printf("Q %d", (int)vec.size());
	for(auto tmp : vec) {
		printf(" %d %d", tmp.first, tmp.second);
	}
	printf("\n");
	fflush(stdout);
	if(debug) {
		for(int i(0); i < (int)vec.size(); i++) {
			ans[i] = col[vec[i].first] == col[vec[i].second] ? 0 : 1;
		}
	}else {
		string s;
		cin >> s;
		for(int i(0); i < (int)s.size(); i++) {
			ans[i] = s[i] == '1' ? 0 : 1;
		}
	}
}
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq(1); qq <= tests; qq++) {
		scanf("%d", &n);
		if(debug) {
			init();
		}
		vector<pair<int, int> > vec;
		int c;
		for(int _ = 0; _ < 2; _++) {
			vec.clear();
			for(int i(1 + _); i <= n; i += 2) {
				if(i + 1 <= n) vec.push_back({i, i + 1});
			}
			query(vec);
			c = 0;
			for(int i(1 + _); i <= n; i += 2) {
				if(i + 1 <= n) {
					d[i] = ans[c++];
				}
			}
		}

		vector<pair<int, int> > ints;
		int strt = 1;
		for(int i(2); i <= n; i++) {
			if(d[i - 1] == 0) {
				
			}else {
				ints.push_back({strt, i - 1});
				strt = i;
			}
		}
		ints.push_back({strt, n});
		
		for(int _ = 0; _ < 3; _++) {
			vec.clear();
			for(int i(_); i + 2 < (int)ints.size(); i += 3) {
				vec.push_back({ints[i].first, ints[i + 2].first});
			}
			query(vec);
			c = 0;
			for(int i(_); i + 2 < (int)ints.size(); i += 3) {
				di[i] = ans[c++];
			}
		}
		blg[0] = 0;
		blg[1] = 1;
		for(int i(2); i < (int)ints.size(); i++) {
			if(di[i - 2] == 1) blg[i] = 3 - blg[i - 1] - blg[i - 2];
			else blg[i] = blg[i - 2];

		}
		vector<int> g[3];
		for(int i(0); i < (int)ints.size(); i++) {
			for(int j(ints[i].first); j <= (ints[i].second); j++) {
				g[blg[i]].push_back(j);
			}
		}
		printf("A %d %d %d\n", (int)g[0].size(), (int)g[1].size(), (int)g[2].size());
		for(int _(0); _ < 3; _++) {
			int prv = -1;
			for(int i(0); i < (int)g[_].size(); i++) {
				if(prv != -1 && debug) assert(col[prv] == col[g[_][i]]);
				printf("%d%c", prv = g[_][i], i == (int)g[_].size() - 1 ? '\n' : ' ');
			}
			if(g[_].empty()) printf("\n");
		}
		fflush(stdout);
	}

}