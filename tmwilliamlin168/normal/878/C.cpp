#include <bits/stdc++.h>
using namespace std;

int n, k;

struct Group {
	int *high, *low, sz=1;
	Group() {
		high = new int[k], low = new int[k];
		for(int i=0; i<k; ++i) {
			cin >> high[i];
			low[i]=high[i];
		}
	}
	void merge(const Group &o) {
		for(int i=0; i<k; ++i) {
			high[i]=max(high[i], o.high[i]);
			low[i]=min(low[i], o.low[i]);
		}
		sz+=o.sz;
	}
	bool operator<(const Group &o) const {
		for(int i=0; i<k; ++i)
			if(high[i]>o.low[i])
				return false;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	set<Group> gs;
	for(int i=0; i<n; ++i) {
		Group g;
		auto i0 = gs.lower_bound(g), i1 = gs.upper_bound(g);
		//cout << "a" << endl;
		while(i0!=i1) {
			g.merge(*i0);
			i0=gs.erase(i0);
		}
		//cout << "b" << endl;
		gs.insert(g);
		cout << gs.rbegin()->sz << "\n";
	}
}