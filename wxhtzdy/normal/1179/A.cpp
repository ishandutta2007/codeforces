#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	deque<int> dq;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		dq.push_back(a);
	}
	vector<pair<int, int>> vc;
	for (int i = 0; i <= 3 * n; i++){
		int x = dq.front();
		dq.pop_front();
		int y = dq.front();
		dq.pop_front();
		vc.push_back({x, y});
		if (x < y) swap(x, y);
		dq.push_front(x);
		dq.push_back(y);
	}
	while (q--){
		// zasto mora ll -> lik koji je pravio test primere je newbie realno
		long long m;
		cin >> m;
		--m;
		if(m < vc.size()){
			cout << vc[m].first << " " << vc[m].second << "\n";
		}
		else{
			int i = ((m - n) % (n - 1)) + n;
			cout << vc[i].first << " " << vc[i].second << "\n";
		}
	}
}