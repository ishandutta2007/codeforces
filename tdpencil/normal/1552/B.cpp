#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt=1;
	cin >> tt;
	
	while(tt--) {
		int n; cin >> n;
		vector<vector<int>> a(n, vector<int> (5));
		for (int i = 0; i < n; ++i) {
		 	for (int j = 0; j < 5; j++) {
		 	 	cin >> a[i][j];
		 	}
		}
		int id = 0;
		for (int i = 1; i < n; ++i) {
			int cnt = 0;
			for(int j = 0; j < 5; j++) 
			{
				
			 	if (a[i][j] < a[id][j]) {
			 		cnt++;
			 	}
			 	if(cnt>=3) id = i;
			}
		}
		bool out = true;
		for (int i = 0; i < n; ++i) {
		 	int cnt = 0;
		 	for (int j = 0; j < 5; j++) {
		 	 	if(a[i][j] < a[id][j])
		 	 		++cnt;
		 	}
		 	if(cnt>=3) {
		 	 	cout << -1 << "\n";
		 		out = false;
		 		break;
		 	}
		}
		if(out) {
		 	cout << id + 1 << "\n";
		}
	}
}