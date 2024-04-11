#include <bits/stdc++.h>

typedef long long ll;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> coord(m);	

	for(int i=0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		--a, --b;
		for(int j=a; j <=b; j++)
			coord[j]++;
	}

	auto match = [&]() -> vector<int> {vector<int> ans; for(int i=0; i < m; i++) if(coord[i] == 0) ans.push_back(i+1); return ans;};

	int c = std::count(coord.begin(), coord.end(), 0);
	if(!c)
		cout << 0 << "\n";
	else {
		cout << c << "\n";
		vector<int> a = match();
		for(auto &e: a)
			cout << e << " " ;
	}
}