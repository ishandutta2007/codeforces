#include<bits/stdc++.h>
using namespace std;
char st[111];
int main() {
	int tests;
	cin >> tests;
	for(int i(0); i < tests; i++) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << "! " << 1 << ' ' << 1 << endl;
			cout.flush();
		}else {
			cout << "? " << 1 << ' ' << 2 << endl;
			cout.flush();
			cin >> st;
			int mx, mn;
			if(st[0] == '>') {
				mx = 1;
				mn = 2;
			}else {
				mx = 2;
				mn = 1;
			}
			for(int i(3); i <= n; i += 2) {
				int mx1, mn1;
				if(i + 1 <= n) {
					cout << "? " << i << ' ' << i + 1 << endl;
					cout.flush();
					cin >> st;
					if(st[0] == '>') {
						mx1 = i;
						mn1 = i + 1;
					}else {
						mx1 = i + 1;
						mn1 = i;
					}
				}else {
					mx1 = mn1 = i;
				}
				cout << "? " << mx << ' ' << mx1 << endl;
				cout.flush();
				cin >> st;
				if(st[0] == '<') {
					mx = mx1;
				}
				cout << "? " << mn << ' ' << mn1 << endl;
				cout.flush();
				cin >> st;
				if(st[0] == '>') {
					mn = mn1;
				}
			}
			cout << "! " << mn << ' ' << mx << endl;
		}
	}
}