#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

int n;
map<int, ll> m;
ll res;

int main() { 
	cin >> n;
	rep(i, 0, n) {
		ll x;
		cin >> x;
		res = max(res, (m[i - x] += x));
	}
	cout << res << "\n";
	return 0;
}