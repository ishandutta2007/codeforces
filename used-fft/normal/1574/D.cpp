#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a[10];
vector<vector<int>> bad;
int n, m, c[10], res = 1;

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for(int i=0; i<n; ++i){
		cin >> c[i];
		a[i].resize(c[i]);
		for(int &j : a[i]) cin >> j;
	}

	cin >> m;
	bad.resize(m, vector<int> (n));
	
	for(auto &i : bad)
		for(int &j : i) cin >> j, --j;

	vector<vector<int>> groups(1, vector<int> (m));
	iota(begin(groups[0]), end(groups[0]), 0LL);

	vector<int> ans;
	int currBest = 0;
	vector<int> sum(m);

	for(int i=0; i<n; ++i){
		if(currBest){
			int j = max_element(begin(a[i]), end(a[i])) - begin(a[i]);
			ans.push_back(j);
			currBest += a[i][j];
		}else if(!i){
			set<array<int, 2>> left;
			for(int j=0; j<c[i]; ++j) left.insert({a[i][j], j});
			for(int j=0; j<m; ++j){
				auto f = left.find({a[i][bad[j][i]], bad[j][i]});
				if(f != end(left)) left.erase(f);
			}

			if(!empty(left)){
				auto [val, j] = (*--end(left));
				ans.push_back(j);
				currBest = val;
			}
		}

		vector<vector<int>> newgroups;

		set<array<int, 2>> q;
		for(int j=0; j<c[i]; ++j) q.insert({a[i][j], j});

		for(auto &group : groups){
			int currBest1 = -1, currInd;

			map<int, vector<int>> h;

			for(int &j : group){
				q.erase({a[i][bad[j][i]], bad[j][i]});

				h[bad[j][i]].push_back(j);

				if(currBest1 < sum[j]){
					currBest1 = sum[j];
					currInd = j;
				}

				sum[j] += a[i][bad[j][i]];
			}

			for(auto [j, v] : h){
				newgroups.push_back(v);
			}

			if(!empty(q)){
				currBest1 += (*--end(q))[0];
				if(currBest < currBest1){
					ans.clear();
					for(int j=0; j<i; ++j)
						ans.push_back(bad[currInd][j]);
					ans.push_back((*--end(q))[1]);
					currBest = currBest1;
				}
			}

			for(int &j : group){
				// if(here) cout << j+1 << ' ';
				q.insert({a[i][bad[j][i]], bad[j][i]});
			}
			// if(here) cout << '\n';
		}
		groups.swap(newgroups);
	}

	for(int &i : ans) cout << i+1 << ' ';

}