#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int n, mex, ans[111000];
vector<int> fre;
 
int main() {
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
		if (mex > x) {
			cout << "-1\n";
			return 0;
		}
		if (mex == x) {
			ans[i] = 1000000;
			fre.push_back(i);
		}
		else {
			fre.push_back(i);
			rep(j, mex, x - 1) {
				if (fre.empty()) {
					cout << "-1\n";
					return 0;
				}
				ans[fre.back()] = j;
				fre.pop_back();
			}	
		}
		mex = x;
	}
	rep(i, 1, n)	
		cout << ans[i] << " ";
	return 0;
}