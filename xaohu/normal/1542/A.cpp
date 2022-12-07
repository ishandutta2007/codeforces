#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n;

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		n *= 2;
		int s = 0;
		while (n--) {
			int a;
			cin >> a;
			s += (a & 1 ? 1 : -1);
		}
		cout << (!s ? "Yes\n" : "No\n");
	}
	return 0;
}