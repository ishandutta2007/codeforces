#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
	
    int T; cin >> T;
    for(int case_num = 1; case_num <= T; case_num ++) {
		int n; cin >> n;
		
		map<int, int> freq;
		
		vector<int> a;
		
		for(int i=0; i < 4 * n; ++i) {
			int b; cin >> b;
			freq[b]++;
		}
		bool works = true;
		for(auto e: freq) {
			if(int(e.second) & 1) {
				works = false;
			}
			for(int i=0; i < e.second / 2; i++)
				a.push_back(e.first);	
		}
		if(!works) {
			cout << "NO\n";
			continue;
		}
		set<int> dif;
		
		sort(a.begin(), a.end());
		
		int l = 0, r = 2 * n - 1;
//		assert(int(a.size()) == 2*n);
//		return 0;
		while(l < r) {
			dif.insert(a[l] * a[r]);
//			cerr << a[l] * a[r] << "\n";
			l++;
			r--;
		}
		
		if((int)dif.size() == 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}