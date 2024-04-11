#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int> degree(n, 1);
    for (int i : code)
        degree[i]++;

    set<int> leaves;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1)
            leaves.insert(i);
    }

    vector<pair<int, int>> edges;
    for (int v : code) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());

        edges.emplace_back(leaf, v);
        if (--degree[v] == 1)
            leaves.insert(v);
    }
    edges.emplace_back(*leaves.begin(), n-1);
    return edges;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> c;
	for(int i=1; i<n; ++i) {
		int ci;
		cin >> ci, --ci;
		c.push_back(ci);
	}
	vector<int> d(c.begin(), c.end());
	reverse(d.begin(), d.end());
	vector<pair<int, int>> e=pruefer_decode(d);
	//if(c[0]!=e.back().first&&c[0]!=e.back().second) {
		//cout << -1;
		//return 0;
	//}
	e.pop_back();
	cout << c[0]+1 << "\n";
	for(pair<int, int> p : e)
		cout << p.first+1 << " " << p.second+1 << "\n";
}