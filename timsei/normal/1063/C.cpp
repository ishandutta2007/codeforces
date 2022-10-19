#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int x, y, who;
int chg(string cxt) {
	return (cxt == "black");
}
int input(int x, int y) {
	cout << x <<' ' << y << endl;
	fflush(stdout);
	string res;
	cin >> res;
	return chg(res);
}


main() {
	cin >> n;
	if(n == 1) {
		int A = input(1, 1);
		cout << 2 <<" " << 3 <<" " << 3 <<" " << 3 << endl;
		return 0;
	}
	int A = input(1, 1), B = input(2333, (1e9) - 1);
	n -= 2;
	if(A == B) {
		who = 1e9 - 2;
		int L = 2, R = (1e9) - 2;
		for(int i = 1; i <= n; ++ i) {
			int mid = (L + R) >> 1;
			int now = input(2333, mid);
			if(now != A) {
				who = mid + 1;
				L = mid + 1;
			}
			else {
				who = mid - 1;
				R = mid - 1;
			}
		}
		cout << 1 <<" " << 0 << " " << 2333 <<" " << who << endl;
	}
	else {
		who = (1e9) - 2;
		int L = 2, R = (1e9) - 2;
		for(int i = 1; i <= n; ++ i) {
			int mid = (L + R) >> 1;
			int now = input(2333, mid);
			if(now == A) {
				who = mid + 1;
				L = mid + 1;
			}
			else {
				who = mid - 1;
				R = mid - 1;
			}
		}
		cout << 1 <<" " << 2 <<" " << 2333 <<" " << who << endl;
	}
}