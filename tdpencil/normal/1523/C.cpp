#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <stack>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <string>

using namespace std;
int n, t;
int i, last=1e9;
const int mxN=1e3+1;
stack<pair<int,int>> levels[mxN];
int MAX_LEVEL;
// reverse stack
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--) {
		cin >> n;
		int c=0;
		MAX_LEVEL = 0;
		for(int e = 0; e < n; e++) {
			cin >> i;
			if(levels[c].empty() || levels[c].top().second+1==i) {
				levels[c].push({e,i});
			} else {
				// if i == last + 1 then we can easily attach this
				// otherwise what happens if it isn't? either less or greater
				// if its less (1) then we just attach a new list
				// otherwise we traverse under to assume 
				if(i == 1) {
					while(!levels[c].empty()) ++c;
					levels[c].push({e,i});
				} else {
					while(c>=0) {
						// should be guaranteed to be not empty
						if(levels[c].top().second+1==i) {
							levels[c].push({e,i});
							break;	
						}
						while(levels[c].size()) levels[c].pop();
						--c;
					}
					assert(c>=0);
				}
				// it can only be lowerelse 
				// alright the hardest part is trying to organize a way to install 
			}
			for(int j=0;j<c;j++) {
				cout << levels[j].top().second << ".";
			}
			cout << i << "\n";
			last = i;
		}

		for(int i=0;i<n;i++) {
			while(levels[i].size()) levels[i].pop();
		}
		
	}
}