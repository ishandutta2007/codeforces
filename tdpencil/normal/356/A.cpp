#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int broken[300001], nb[300001];


int main() {
	int n, m;
	cin >> n >> m;

	
	set<int> cur;
	for(int i = 0; i < n; i++) cur.insert(i + 1);
	for(int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		
		auto it = cur.lower_bound(l);
		while(it != cur.end() && *it <= r) {
			if(*it == x) {
				++it;
			} else {
				broken[*it] = x;
				cur.erase(it);
				it = cur.lower_bound(l);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) cout << broken[i] << " ";
	
}