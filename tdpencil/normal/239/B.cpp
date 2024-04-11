#include <bits/stdc++.h>
using namespace std;


int cnt[10];
bool used[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, q; cin >> n >> q;
	int l, r;
	string t;
	cin >> t;
//	int t = 1;
	while(q--) {
		cin >> l >> r;
		--l, --r;
		auto oub = [&](int x) {
			return l <= x && x <= r;	
		};
		string s = t;
		int f = l;
		bool dir = 1;
		memset(used, 0, sizeof used);
		memset(cnt, 0, sizeof cnt);
		int lastDir = -1;
		while(oub(f)) {
			if(isdigit(s[f]) && !used[f]) {
				++cnt[s[f] - '0'];
				s[f]--;
				lastDir = -1;
				if(s[f] - '0' < 0) {
					used[f] = 1;
				}
			} else if(!isdigit(s[f]) && !used[f]) {
				if(s[f] == '<') {
					dir = 0;
					if(lastDir != -1) {
						used[lastDir] = 1;
					}
					lastDir = f;
				} else {
					dir = 1;
					if(lastDir != -1) {
						used[lastDir] = 1;
					}
					lastDir = f;
				}
			}
			
			if(dir == 1) {
				++f;
			} else {
				--f;
			}
//			cout << f << endl;
		}
		
		for(int i = 0; i < 10; ++i) {
			cout << cnt[i] << " ";
		}
		cout << "\n";
	}
}