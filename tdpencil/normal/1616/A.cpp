#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	while(T--) {
		set<int> distinct;

		int N; cin >> N;
		for(int i = 0, x; i < N; i++) {
			cin >> x;
			if(distinct.count(x)) x = -x;
			distinct.insert(x);
		}

		cout << distinct.size() << "\n";
	}
}