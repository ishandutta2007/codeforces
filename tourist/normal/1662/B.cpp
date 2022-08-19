#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	vector<string> s(3);
	for(string& x : s){
		cin >> x;
	}
	vector<vector<int> > freq(3, vector<int>(26, 0));
	for(int i = 0; i < 3; i++){
		for(char c : s[i]){
			freq[i][c-'A']++;
		}
	}
	int npairs = 0;
	for(int c = 0; c < 26; c++){
		vector<int> r = {freq[0][c], freq[1][c], freq[2][c]};
		sort(r.begin(), r.end());
		int plus = min(r[0] + r[1], (r[0] + r[1] + r[2]) / 2);
		npairs += plus;
	}
	int l = max({s[0].size(), s[1].size(), s[2].size()});
	while(true){
		int wild = 3 * l - s[0].size() - s[1].size() - s[2].size();
		if(wild + npairs >= l){
			vector<multiset<int>> cs(3);
			for(int i = 0; i < 3; i++){
				for(char c : s[i]){
					cs[i].insert(c - 'A');
				}
				for(int j = 0; j < l - s[i].size(); j++){
					cs[i].insert(27);
				}
				assert(cs[i].size() == l);
			}
			vector<string> ans;
			vector<vector<int> > pairs(3);

			int pairs_made = 0;
			for(int c = 0; c < 26; c++){
				while(pairs_made < l){
					vector<int> ord = {0, 1, 2};
					sort(ord.begin(), ord.end(), [&](int x, int y) { return freq[x][c] < freq[y][c]; });
					int a = ord[1];
					int b = ord[2];
					if(freq[a][c] && freq[b][c]){
						if(pairs_made < l){
							freq[a][c]--; freq[b][c]--;
							cs[a].erase(cs[a].find(c));
							cs[b].erase(cs[b].find(c));
							pairs[3-a-b].push_back(c);
							pairs_made++;
						}
					} else {
						break;
					}
				}
			}
			while(pairs_made < l){
				int done = 0;
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(i == j) continue;
						if(cs[i].empty() || cs[j].empty()) continue;
						if(cs[i].count(27)){
							int a = *cs[j].begin();
							if(a != 27){
								if(pairs_made < l){
									cs[i].erase(cs[i].find(27));
									cs[j].erase(cs[j].find(a));
									pairs[3-i-j].push_back(a);
									pairs_made++;
									done = 1;
								}
							}
						}
					}
				}
				if(!done) break;
			}
			while(pairs_made < l){
				int done = 0;
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(i == j) continue;
						if(cs[i].empty() || cs[j].empty()) continue;
						if(cs[i].count(27)){
							int a = *cs[j].begin();
							if(true){
								if(pairs_made < l){
									cs[i].erase(cs[i].find(27));
									cs[j].erase(cs[j].find(a));
									pairs[3-i-j].push_back(a);
									pairs_made++;
									done = 1;
								}
							}
						}
					}
				}
				if(!done) break;
			}
			if(pairs_made >= l){
				cout << l << '\n';
				for(int i = 0; i < 3; i++){
					for(int a : pairs[i]){
						assert(!cs[i].empty());
						int b = *cs[i].begin();
						cs[i].erase(cs[i].find(b));
						a = min(a, 25);
						b = min(b, 25);
						cout << char(a + 'A');
						cout << char(b + 'A');
						cout << '\n';
					}
				}
				break;
			}
		}
		l++;
	}
}