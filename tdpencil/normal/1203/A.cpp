#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);
	auto sorted = [&](vector<int> &a) {
		for(int i=1; i < a.size(); i++)
			if(a[i] < a[i-1]) return false;
		return true;	
	};
	auto revsorted = [&](vector<int> &a) {
		for(int i=1; i < a.size(); i++)
			if(a[i] > a[i-1]) return false;
		return true;
	};
    int T; cin >> T;
    for(int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
		vector<int> q(N);
		vector<int> b(N);
		for(int i=0; i < N; i++) cin >> q[i];
		for(int i=0; i < N; i++) b[i] = q[i];
		if(sorted(q)) {
			cout << "YES\n";
			continue;
		} else if(revsorted(q)) {
			cout << "YES\n";
			continue;
		} else {
			int p=-1;
			for(int i=1; i < N; i++)
				if(q[i] > q[i-1]) p = i;
			if(p == -1) {
				cout << "NO\n";
				continue;	
			} else {
				rotate(q.begin(), q.begin() + p, q.end());
				if(sorted(q)) {
					cout << "YES\n";
				} else if(revsorted(q)) {
					cout << "YES\n";
				} else {
					p = -1;
					for(int i = 1; i < N; i++)
						if(b[i] < b[i-1]) p = i;
					rotate(b.begin(), b.begin() + p, b.end());
					if(p == -1) {
						cout << "NO\n";	
					}
					else if(sorted(b)) {
						cout << "YES\n";
					} else if(revsorted(b)) {
						cout << "YES\n";
					} else {
						cout << "NO\n";
					}
				}
			}
		}
    }
}