#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;

		string _s; cin >> _s;
		int oh {}, s[n];
		for(int i = 0; i < n; ++i) {
			s[i] = _s[i] - '0';
			oh += s[i];
		}

		if(oh & 1) {
			cout << "NO\n";
		} else {
			if(!*max_element(s, s + n)) {
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";


			bool done[n] {};

			int st {};
			while(!s[st]) ++st;
			++st %= n;

			for(int _ = 1; _ < n; ++_) {
				int i = (_ + st) % n;
				if(s[i]) {
					if(!done[i]) {
						cout << st+1 << ' ' << i+1 << '\n';
					}
					done[i] = 1;
				} else {
					int v = i+2;
					if(v > n) v = 1;
					if(!done[i]) {
						cout << st+1 << ' ' << i+1 << '\n';
					}
					cout << i+1 << ' ' << v << '\n';
					done[i] = 1;
					done[(i+1)%n] = 1;
				}
			}
		}
	}
}