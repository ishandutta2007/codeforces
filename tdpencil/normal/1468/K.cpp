#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
int a[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	auto choose = [&](char c, pair<int, int> p) {
		if(c == 'L') p.first--;
		if(c == 'R') p.first++;
		if(c == 'D') p.second--;
		if(c == 'U') p.second++;
		return p;
	};
	while(t-- > 0) {
		string s;
		cin >> s;

		int n = s.size();
		pair<int, int> cur(0, 0);
		set<pair<int, int>> to_try;
		for(int i=0; i < n; i++) {
			// try this position

			cur = choose(s[i], cur);
			to_try.insert(cur); 

			
		}


		// n log n?
		// lets iterate through each position and see what happens when we place the obstacle there
		bool can = false;

		for(auto &pt: to_try) {
			pair<int, int> c = make_pair(0, 0);
			
			bool works = false;
			
			for(int i=0; i < n; i++) {
				
				c = choose(s[i], c);
				if(c == pt) {
					if(s[i] == 'L') c.first++;
					if(s[i] == 'R') c.first--;
					if(s[i] == 'U') c.second--;
					if(s[i] == 'D') c.second++;
					// reverse the actions
				}


			}

			if(c.first == 0 && c.second == 0) works = true;			

			if(works) {
				cout << pt.first << " " << pt.second << "\n";
				can = true;
				break;
			}

			
		}


		if(!can)cout << 0 << " " << 0  << "\n";

		
	}
}