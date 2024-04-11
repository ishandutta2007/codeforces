#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si set<int>
#define PB push_back
#define ct cin.tie(0)
#define is ios::sync_with_stdio(0)
#define ll long long
const int mxn = 2e5;
int n, m, k;
int main() {
	cin >> n;
	bool ok = 1;
	while(n--) {
		int y;
		cin >> y;
		if(y) ok =0;
	}
	cout << (ok ? "EASY" : "HARD");
	return 0;
}