#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;
int t, n, k;
int main() { 
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int so_far = 0;
		rep(i, 0, n) {
			cout << (i ^ so_far) << endl;
			int r;
			cin >> r;
			if (r == 1)
				break;
			so_far = i;
		}
	}
	return 0;
}