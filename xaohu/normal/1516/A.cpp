#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = b; i >= a; i--)
 
using namespace std;

int t, n, k;
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int x = 0;
		rep(i,1,n) {
			int a;
			cin >> a;
			if (i==n) {
				cout << a + x << endl;
			}
			else {
				while (k && a) {
					a--;
					x++;
					k--;
				}
				cout << a << " ";
			}
		}
	}		
	
	return 0;
}