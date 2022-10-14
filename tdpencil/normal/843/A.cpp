#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
#define rep(i, a, b) for(lli i = (a); i <= (b); i++)
#define rrep(i, a, b) for(lli i = (a); i >= (b); i--)
#define vi vector<lli>
#define vvi vector<vector<lli>>
pair<lli, lli> a[int(1e5) + 1];
bool visited[int(1e5) + 1];
struct DSU {
	vi parent;
	vi rank;
	lli find_set(lli v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}
	void make_set(lli v) {
		parent[v] = v;
		rank[v] = 0;
	}
	void union_sets(lli a, lli b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				rank[a]++;
		}
	}

	DSU(lli numElements) : parent(numElements + 1, 0), rank(numElements + 1, 0) {
		rep(i, 1, numElements) {
			make_set(i);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	lli n;
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	vvi lists;
	lists.reserve(n);
	rep(i, 1, n) {
		auto x = i;
		vi list;
		while (!visited[x]) {
			visited[x] = true;
			list.push_back(x);
			x = a[x].second;
		}
		if (!list.empty()) {
			lists.push_back(list);
		}
	}
	cout << lists.size() << endl;
	for (auto const& l : lists) {
		cout << l.size() << " ";
		for (auto const& m : l) {
			cout << m << " ";
		}
		cout << endl;
	}
	return 0;
}